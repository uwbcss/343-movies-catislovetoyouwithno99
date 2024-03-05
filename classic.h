/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#ifndef CLASSIC
#define CLASSIC
#include "dvdmovie.h"
/**
 *
 */
class Classic : public DVDMovie {
public:
  /**
   * returns true if this is higher than other mov object
   *
   * @param mov other movie object being compared
   */
  bool operator>(const Classic *&mov) const;

  /**
   * returns true is this is equal to mov
   *
   * @param mov other movie object being compared
   */
  bool operator==(const Classic *&mov) const;

  /**
   * helper for cout
   * works with overloading
   * @param out output stream shows what's displayed
   */
  ostream &print(std::ostream &out) const override;

private:
  // the major actor of the classic
  string majorActor;

  // the month of release
  int month;

  /**
   * the constructor
   */
  explicit Classic();

  // for corresponding factory to access it
  friend class ClassicFactory;

  friend class MovieStore;

  friend class Inventory;

  friend class Customer;
};

class ClassicFactory : public DVDMovieFactory {
public:
  /**
   * the constructor for the classic factory
   */
  ClassicFactory();

  /**
   * overrided create function that returns a classic movie
   */
  DVDMovie *create() const override;
};

#endif