/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

#include "customer.h"
#include "classic.h"

/**
 * Customer method to handole the input that is taken as the customer object
 * from command line
 *
 * @param customerFID Unique for each customer ID
 * @param lastName customer lastName
 * @param firstName customer firstName
 */
Customer::Customer(string customerFID, string lastName, string firstName) {
  customerID = std::move(customerFID);
  lastName = std::move(lastName);
  firstName = std::move(firstName);
  borrowing.emplace_back(nullptr);
}

/**
 * Delete itself when program end
 * No more else what memory leak ?
 * point off by no commit No no no not today heee
 */
Customer::~Customer() {
  for (auto &h : history) {
    delete h;
  }
}

/**
 * When it be call it will gets a movie from the borrowing vector
 *
 * @param type The type of Movie refer to dvdmovie class
 * @param strA Information about the movie need to borrowing refer to dvdmovie
 * class
 * @param strB Information about the movie need to borrowing refer to dvdmovie
 * class
 */
DVDMovie *&Customer::getMovie(char type, const string &strA,
                              const string &strB) {
  for (int i = 1; i < borrowing.size(); i++) {
    if (type == 'F' && borrowing[i]->title == strA &&
        borrowing[i]->date == strB) {
      return borrowing[i];
    }
    if (type == 'D' && borrowing[i]->director == strA &&
        borrowing[i]->title == strB) {
      return borrowing[i];
    }
    if (type == 'C' && borrowing[i]->date == strA &&
        dynamic_cast<Classic *>(borrowing[i])->majorActor == strB) {
      return borrowing[i];
    }
  }
  cerr << "Error: Customer " << customerID
       << " has borrowed no movies with variables " << type << " " << strA
       << " " << strB << "!" << endl;
  return borrowing[0];
}

/**
 * When call it will remove the curreny object fro mthe Movie list
 *
 * @param type The type of Movie refer to dvdmovie class
 * @param strA Information about the movie need to borrowing refer to dvdmovie
 * class
 * @param strB Information about the movie need to borrowing refer to dvdmovie
 * class
 */
void Customer::removeMovie(char type, const string &strA, const string &strB) {
  for (int i = 1; i < borrowing.size(); i++) {
    if (type == 'F' && borrowing[i]->title == strA &&
        borrowing[i]->date == strB) {
      borrowing.erase(borrowing.begin() + i);
    }
    if (type == 'D' && borrowing[i]->director == strA &&
        borrowing[i]->title == strB) {
      borrowing.erase(borrowing.begin() + i);
    }
    if (type == 'C' && borrowing[i]->date == strA &&
        dynamic_cast<Classic *>(borrowing[i])->majorActor == strB) {
      borrowing.erase(borrowing.begin() + i);
    }
  }
}