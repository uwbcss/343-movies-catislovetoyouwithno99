
#ifndef INVENTORY
#define INVENTORY

#include "dvdmovie.h"
#include <algorithm>
#include <map>

/**
 * A place where you are a person that having all this movie you holder ... loki
 * why
 */
class Inventory {
public:
  // constructor
  Inventory() = default;

  // inserts the DVDMovie into the inventory, then sorts. return index number if
  // insert is successful, -1 otherwise
  bool insert(DVDMovie *mov);

  // obtains the DVDMovie from the inventory
  void retrieve(char type, const string &strA, const string &strB,
                DVDMovie *&mov);

  // displays one type of movie from the inventory
  void display(char ch);

  // destructor
  ~Inventory();

private:
  // MAIN ha inventory ...
  map<char, vector<DVDMovie *>> inventory;

  // comparison for comedy. returns true if mov1 is smaller
  static bool compareDF(DVDMovie *mov1, DVDMovie *mov2);

  // comparison for drama. returns true if mov1 is smaller
  static bool compareDD(DVDMovie *mov1, DVDMovie *mov2);

  // comparison for classic. returns true if mov1 is smaller
  static bool compareDC(DVDMovie *mov1, DVDMovie *mov2);

  friend class MovieStore;
};

#endif