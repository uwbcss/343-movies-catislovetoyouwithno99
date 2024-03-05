/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "classic.h"
/**
 * Constructor
 * classics only have a genre D or C
 */
Classic::Classic() {
  media = 'D';
  genre = 'C';
}
/**
 * comparison for classics
 *
 * @param mov Movie to be compared to
 */
bool Classic::operator>(const Classic *&mov) const {
  if (this->date > mov->date) {
    return true;
  }
  if (this->date == mov->date) {
    if (this->majorActor > mov->majorActor) {
      return true;
    }
  }
  return false;
}
/**
 * checking to see if they are the same movie
 *
 * @param mov movie being compared to
 */
bool Classic::operator==(const Classic *&mov) const {
  return this->date == mov->date && this->majorActor == mov->majorActor;
}
/**
 * for cout print statement
 */
ostream &Classic::print(ostream &out) const {
  out << "Media: " << media << endl;
  out << "Genre: " << genre << endl;
  out << "Title: " << title << endl;
  out << "Major Actor: " << majorActor << endl;
  out << "Director: " << director << endl;
  out << "Release Year: " << date << endl;
  out << "Borrowed Stock: " << maxStock - currStock << endl;
  out << "Remaining Stock: " << currStock << endl;
  return out;
}