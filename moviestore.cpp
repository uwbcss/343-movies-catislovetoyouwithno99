#include "moviestore.h"
#include "classic.h"

MovieStore::MovieStore(const string &customersInput, const string &moviesInput,
                       const string &commandsInput) {
  string temp;
  ifstream inputF(customersInput);
  if (inputF) {
    while (getline(inputF, temp)) {
      customerQueue.push(temp);
    }
    processCustomerData();
  } else {
    cerr << "Error: Invalid filename " << customersInput << "!" << endl;
  }
  ifstream inputS(moviesInput);
  if (inputS) {
    while (getline(inputS, temp)) {
      movieQueue.push(temp);
    }
    processMovieData();
  } else {
    cerr << "Error: Invalid filename " << moviesInput << "!" << endl;
  }
  ifstream inputT(commandsInput);
  if (inputT) {
    while (getline(inputT, temp)) {
      commandQueue.push(temp);
    }
    processCommands();
  } else {
    cerr << "Error: Invalid filename " << commandsInput << "!" << endl;
  }
}

string MovieStore::subStringUntilChar(string &str, int &start, char ch) {
  string temp;
  for (int i = start; i < str.size(); i++) {
    if (str[i] == ch) {
      start += 1;
      return temp;
    }
    temp += str[i];
    start += 1;
  }
  return temp;
}

void MovieStore::processCustomerData() {
  string idNumber;
  string lastName;
  string firstName;
  int index = 0;
  while (!customerQueue.empty()) {
    index = 5;
    idNumber = customerQueue.front().substr(0, 4);
    // clang-format demanded this comment to exist to stop its loop
    lastName = subStringUntilChar(customerQueue.front(), index, ' ');
    firstName = customerQueue.front().substr(index);
    customers.insert(new Customer(idNumber, lastName, firstName));
    customerQueue.pop();
  }
}

void MovieStore::processDramedyDVDMovie(string &str) {
  int index = 3;
  DVDMovie *newMov = DVDMovie::create(str[0]);
  newMov->maxStock = stoi(subStringUntilChar(str, index, ','));
  newMov->currStock = newMov->maxStock;
  index += 1;

  newMov->director = subStringUntilChar(str, index, ',');
  index += 1;

  newMov->title = subStringUntilChar(str, index, ',');
  index += 1;

  newMov->date = str.substr(index);
  movies['D'].insert(newMov);
}

void MovieStore::processClassicDVDMovie(string &str) {
  int index = 3;
  auto *newMov = dynamic_cast<Classic *>(DVDMovie::create(str[0]));
  newMov->maxStock = stoi(subStringUntilChar(str, index, ','));
  newMov->currStock = newMov->maxStock;
  index += 1;

  newMov->director = subStringUntilChar(str, index, ',');
  index += 1;

  newMov->title = subStringUntilChar(str, index, ',');
  index += 1;

  newMov->majorActor = subStringUntilChar(str, index, ' ');
  newMov->majorActor += ' ';
  newMov->majorActor.append(subStringUntilChar(str, index, ' '));

  string dateOfMovie = subStringUntilChar(str, index, ' ');
  if (dateOfMovie.size() == 1) {
    dateOfMovie = '0' + dateOfMovie;
  }

  string yearOfMovie = subStringUntilChar(str, index, ' ');
  yearOfMovie += " ";
  yearOfMovie.append(dateOfMovie);
  newMov->date = yearOfMovie;
  cout << newMov->date << " yo!!" << endl;

  movies['D'].insert(newMov);
}

void MovieStore::processMovieData() {
  while (!movieQueue.empty()) {
    char mediaName = 'D'; // no other option
    char genreName = movieQueue.front()[0];
    if (mediaName == 'D') {
      if (genreName == 'F' || genreName == 'D') {
        processDramedyDVDMovie(movieQueue.front());
      } else if (genreName == 'C') {
        processClassicDVDMovie(movieQueue.front());
      } else {
        cerr << "Error: Genre " << genreName << " doesn't exist!" << endl;
      }
    } else {
      cerr << "Error: Media type " << mediaName << " doesn't exist!" << endl;
    }
    movieQueue.pop();
  }
}

void MovieStore::processComedyDVDMovieTransaction(string &str,
                                                  Customer *&customer) {
  int index = 11;
  Transaction *transact = Transaction::create(str[0]);
  string titleN = subStringUntilChar(str, index, ',');
  string yearN = str.substr(index + 1);
  DVDMovie *mov = nullptr;
  movies['D'].retrieve(str[9], titleN, yearN, mov);
  if (mov != nullptr) {
    if (transact->transactionType == 'B') {
      if (mov->currStock > 0) {
        transact->movie = mov;
        mov->currStock -= 1;
        customer->borrowing.emplace_back(mov);
        customer->history.push_back(transact);
      } else {
        delete transact;
        cerr << "Error: No stock left for movie " << str[0] << " " << titleN
             << " " << yearN << "!" << endl;
      }
    } else if (transact->transactionType == 'R') {
      DVDMovie *customerMov = customer->getMovie(str[9], titleN, yearN);
      if (mov == customerMov) {
        customer->removeMovie(str[9], titleN, yearN);
        transact->movie = mov;
        mov->currStock += 1;
        customer->history.push_back(transact);
      }
    }
  } else {
    delete transact;
    cerr << "Error: Comedy movie " << titleN << " " << yearN
         << " doesn't exist!" << endl;
  }
}

void MovieStore::processDramaDVDMovieTransaction(string &str,
                                                 Customer *&customer) {
  int index = 11;
  Transaction *transact = Transaction::create(str[0]);
  string directorN = subStringUntilChar(str, index, ',');
  index += 1;
  string titleN = subStringUntilChar(str, index, ',');
  DVDMovie *mov = nullptr;
  movies['D'].retrieve(str[9], directorN, titleN, mov);
  if (mov != nullptr) {
    if (transact->transactionType == 'B') {
      if (mov->currStock > 0) {
        transact->movie = mov;
        mov->currStock -= 1;
        customer->borrowing.emplace_back(mov);
        customer->history.push_back(transact);
      } else {
        delete transact;
        cerr << "Error: No stock left for movie " << str[0] << " " << directorN
             << " " << titleN << "!" << endl;
      }
    } else if (transact->transactionType == 'R') {
      DVDMovie *customerMov = customer->getMovie(str[9], directorN, titleN);
      if (mov == customerMov) {
        customer->removeMovie(str[9], directorN, titleN);
        transact->movie = mov;
        mov->currStock += 1;
        customer->history.push_back(transact);
      }
    }
  } else {
    delete transact;
    cerr << "Error: Drama movie " << directorN << " " << titleN
         << " doesn't exist!" << endl;
  }
}

void MovieStore::processClassicDVDMovieTransaction(string &str,
                                                   Customer *&customer) {
  int index = 11;
  Transaction *transact = Transaction::create(str[0]);
  string date = subStringUntilChar(str, index, ' ');

  if (date.size() == 1) {
    date = '0' + date;
  }

  string yearOfMovie = subStringUntilChar(str, index, ' ');
  yearOfMovie += " ";
  yearOfMovie.append(date);

  string majorActorMoive = str.substr(index);
  DVDMovie *movie = nullptr;

  movies['D'].retrieve(str[9], yearOfMovie, majorActorMoive, movie);
  if (movie != nullptr) {
    if (transact->transactionType == 'B') {
      if (movie->currStock > 0) {
        transact->movie = movie;
        movie->currStock -= 1;
        customer->borrowing.emplace_back(movie);
        customer->history.push_back(transact);
      } else {
        delete transact;
        cerr << "Error: No stock left for movie " << str[0] << " "
             << yearOfMovie << " " << majorActorMoive << "!" << endl;
      }

    } else if (transact->transactionType == 'R') {
      DVDMovie *customerMov =
          customer->getMovie(str[9], yearOfMovie, majorActorMoive);
      if (movie == customerMov) {
        customer->removeMovie(str[9], yearOfMovie, majorActorMoive);
        transact->movie = movie;
        movie->currStock += 1;
        customer->history.push_back(transact);
      }
    }
  } else {
    delete transact;
    cerr << "Error: Classic movie " << yearOfMovie << " " << majorActorMoive
         << " doesn't exist!" << endl;
  }
}

void MovieStore::processTransaction(string &str) {
  char mediaN = str[7];
  char genreN = str[9];
  Customer *cus = nullptr;
  customers.retrieve(str.substr(2, 4), cus);

  if (cus != nullptr) {
    if (mediaN == 'D') {
      if (genreN == 'F') {
        processComedyDVDMovieTransaction(str, cus);
      } else if (genreN == 'D') {
        processDramaDVDMovieTransaction(str, cus);
      } else if (genreN == 'C') {
        processClassicDVDMovieTransaction(str, cus);
      } else {
        cerr << "Error: Genre " << genreN << " doesn't exist!" << endl;
      }
    } else {
      cerr << "Error: Media type " << mediaN << " doesn't exist!" << endl;
    }
  } else {
    delete cus;
  }
}

void MovieStore::processCommands() {
  while (!commandQueue.empty()) {
    char command = commandQueue.front()[0];
    if (command == 'B' || command == 'R') {
      processTransaction(commandQueue.front());
    } else if (command == 'I') {
      cout << "Printing inventory!" << endl;
      movies['D'].display('F');
      movies['D'].display('D');
      movies['D'].display('C');
    } else if (command == 'H') {
      Customer *cus;
      customers.retrieve(commandQueue.front().substr(2, 4), cus);
      if (cus != nullptr) {
        cout << "Printing history for " << cus->customerID << "!" << endl;
        for (auto &i : cus->history) {
          cout << *i << endl;
        }
      }
    } else {
      cerr << "Error: No command " << command << " exists!" << endl;
    }
    commandQueue.pop();
  }
}