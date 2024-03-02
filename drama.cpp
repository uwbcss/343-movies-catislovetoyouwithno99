/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

#include "drama.h"

/**
 * Defult constructor for Drama and its
 */
Drama::Drama() {
  // ID for Drama
  media = 'D';
  genre = 'D';
}

/**
 * Checking the Drama Movie by sotred in the director order
 * Only using for helping the hash table
 */
bool Drama::operator>(const Drama *&mov) const {
  if (this->director > mov->director) {
    return true;
  }
  if (this->director == mov->director) {
    if (this->title > mov->title) {
      return true;
    }
  }
  return false;
}

/**
 * Checking the Drama Movie by sotred in the director order
 * Only using for helping the hash table
 */
bool Drama::operator==(const Drama *&mov) const {
  return this->director == mov->director && this->title == mov->title;
}