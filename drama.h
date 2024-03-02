/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

#ifndef DRAMA
#define DRAMA
#include "dvdmovie.h"

/**
 * Object name Drama the child of the DVDMovie
 * More pls refer to to the dvdmovie class
 */
class Drama : public DVDMovie {
public:
  /**
   * Checking the Drama Movie by sotred in the director order
   * Only using for helping the hash table
   * returns true if this is higher than mov
   *
   * @param mov movie that should be the Drama Class
   */
  bool operator>(const Drama *&mov) const;

  /**
   * Checking the Drama Movie by sotred in the director order
   * Only using for helping the hash table
   * Returns true if this is equal to mov
   *
   * @param mov movie that should be the Drama Class
   */
  bool operator==(const Drama *&mov) const;

private:
  /**
   * Defult constructor for Drama and its
   */
  explicit Drama();

  /**
   * Helping all other factory when this object is need to be created
   */
  friend class DramaFactory;
  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

class DramaFactory : public DVDMovieFactory {
public:
  /**
   * the dconstructor that using the Facory when dvdmoive class ask
   * This will remove the object as this is meaning the object of drama is being
   * delete
   *
   * This should not be use as create
   */
  DramaFactory();

  /**
   * Create function that returns a drama movie by override the defult in the
   * dvdmovie class
   */
  DVDMovie *create() const override;
};

#endif