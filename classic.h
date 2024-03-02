#ifndef CLASSIC
#define CLASSIC
#include "dvdmovie.h"

class Classic : public DVDMovie {
public:
  // returns true if this is higher than mov
  bool operator>(const Classic *&mov) const;

  // returns true if this is equal to mov
  bool operator==(const Classic *&mov) const;

  // for cout, but it works with overloading
  ostream &print(std::ostream &out) const override;

private:
  // the major actor of the classic
  string majorActor;

  // the month of release
  int month;

  // the constructor
  explicit Classic();

  // for corresponding factory to access it
  friend class ClassicFactory;

  friend class MovieStore;

  friend class Inventory;

  friend class Customer;
};

class ClassicFactory : public DVDMovieFactory {
public:
  // the constructor
  ClassicFactory();

  // overrided create function that returns a classic movie
  DVDMovie *create() const override;
};

#endif