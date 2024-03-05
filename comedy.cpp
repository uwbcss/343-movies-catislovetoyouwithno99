/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "comedy.h"
/**
 * Comedy constructor sets media D and genre F
 */
Comedy::Comedy() {
  media = 'D';
  genre = 'F';
}
/**
 * comparison operator for comedy genre
 *
 * @param mov object being compared to
 */
bool Comedy::operator>(const Comedy *&mov) const {
  if (this->title > mov->title) {
    return true;
  }
  if (this->title == mov->title) {
    if (this->date > mov->date) {
      return true;
    }
  }
  return false;
}
/**
 * == operator to check if mov objects are equal to each other
 *
 * @param mov other movie that is being compared to
 */
bool Comedy::operator==(const Comedy *&mov) const {
  return this->title == mov->title && this->date == mov->date;
}