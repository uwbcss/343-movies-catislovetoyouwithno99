/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#ifndef COMEDY
#define COMEDY

#include "dvdmovie.h"

class Comedy : public DVDMovie {
public:
  /**
   * returns true if this is higher than mov
   */
  bool operator>(const Comedy *&mov) const;

  /**
   * returns true if this is equal to mov
   */
  bool operator==(const Comedy *&mov) const;

private:
  /**
   * the constructor
   */
  explicit Comedy();

  /**
   * Helping all other factory when this object is need to be created
   */
  friend class ComedyFactory;
  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

class ComedyFactory : public DVDMovieFactory {
public:
  /**
   *  the constructor for comedy factory
   */
  ComedyFactory();

  /**
   * overrided create function that returns a comedy movie
   */
  DVDMovie *create() const override;
};

#endif