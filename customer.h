/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

#ifndef CUSTOMER
#define CUSTOMER

#include "dvdmovie.h"
#include "transaction.h"
using namespace std;

/**
 * This class repond the customer in the program
 * The Customer only have two power get a moive or give back which remove the
 * move from currlty customer
 *
 * Customer can having more than one movie to borrowing
 * Each time when Customer borrowing or return this will storgy in the currlty
 * Customer history ANTI-THEFT
 */
class Customer {
public:
  /**
   * When it be call it will gets a movie from the borrowing vector
   *
   * @param type The type of Movie refer to dvdmovie class
   * @param strA Information about the movie need to borrowing refer to dvdmovie
   * class
   * @param strB Information about the movie need to borrowing refer to dvdmovie
   * class
   */
  DVDMovie *&getMovie(char type, const string &strA, const string &strB);

  /**
   * When call it will remove the curreny object fro mthe Movie list
   *
   * @param type The type of Movie refer to dvdmovie class
   * @param strA Information about the movie need to borrowing refer to dvdmovie
   * class
   * @param strB Information about the movie need to borrowing refer to dvdmovie
   * class
   */
  void removeMovie(char type, const string &strA, const string &strB);

private:
  // values
  string customerID;
  string firstName;
  string lastName;
  vector<DVDMovie *> borrowing;
  vector<Transaction *> history;

  /**
   * Customer method to handole the input that is taken as the customer object
   * from command line
   * 
   * @param customerFID Unique for each customer ID
   * @param lastName customer lastName
   * @param firstName customer firstName
   */
  explicit Customer(string customerFID, string lastName, string firstName);

  /**
   * Delete itself when program end
   * No more else what memory leak ?
   * point off by no commit No no no not today heee
   */
  ~Customer();

  friend class HashTable;
  friend class Inventory;
  friend class MovieStore;
};

#endif