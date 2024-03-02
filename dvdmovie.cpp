#include "dvdmovie.h"

/**
 * When the master need to print the object using the cout
 * This will over write the cout to adapt to the object print
 *
 * @param out Object that pass in to be ready to print on the screen
 * @param mov Object that need to print on the screen
 */
ostream &operator<<(ostream &out, const DVDMovie &mov) {
  return mov.print(out);
}

/**
 * Due to the object is created in polymorphism
 * Cout need a helper method to working with it
 * This is helper function to helping the cout to print
 *
 * @param out The ostream that need to be adding the strign to be print on the
 * screen
 */
ostream &DVDMovie::print(ostream &out) const {
  out << "Media: " << media << endl;
  out << "Genre: " << genre << endl;
  out << "Title: " << title << endl;
  out << "Director: " << director << endl;
  out << "Release Year: " << date << endl;
  out << "Borrowed Stock: " << maxStock - currStock << endl;
  out << "Remaining Stock: " << currStock << endl;
  return out;
}

/**
 * Helping to remeber the type of this object is
 *
 * @param type the type of the Object that need to be respond to the movie
 * @param factory THe object that reflash to be be created in the time
 */
void DVDMovie::rememberType(const char &type, DVDMovieFactory *factory) {
  getFactories().emplace(type, factory);
}

/**
 * Creates a DVDMovie
 *
 * @param type the Movie type
 */
DVDMovie *DVDMovie::create(const char &type) {
  if (getFactories().count(type) > 0) {
    return getFactories().at(type)->create();
  }
  cerr << "Error: No factory exists for " << type << "!" << endl;
  return nullptr;
}

map<char, DVDMovieFactory *> &DVDMovie::getFactories() {
  static map<char, DVDMovieFactory *> factories;
  return factories;
}