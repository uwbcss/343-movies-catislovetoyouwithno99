/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "customer.h"
#include "hashtable.h"
#include "inventory.h"
#include <fstream>
#include <queue>
#include <sstream>

class MovieStore {
public:
  /**
   * processes the customer data, returns true if successful
   * otherwise, returns false
   */
  void processCustomerData();

  /**
   * processes the customer data, returns true if successful
   * otherwise, returns false
   */
  void processMovieData();

  /**
   * processes the customer data, returns true if successful
   * otherwise, returns false
   */
  void procCommand();

  /**
   * constructor
   */
  MovieStore(const string &customersInput, const string &moviesInput,
             const string &commandsInput);

  /**
   * default destructor
   */
  ~MovieStore() = default;

private:
  /**
   *  Movie Store values
   *
   */
  map<char, Inventory> movies;
  HashTable customers;
  queue<string> customerQueue;
  queue<string> movieQueue;
  queue<string> commandQueue;

  /**
   * helper for getting substring until an instance of char
   *
   */
  static string subStringUntilChar(string &str, int &start, char ch);

  /**
   * helper for processing drama or comedy movie
   */
  void processDramedyDVDMovie(string &str);

  /**
   * helper for processing classic movie
   */
  void processClassicDVDMovie(string &str);

  /**
   * helper for processing a transaction involving a comedy movie
   */
  void processFDVDTran(string &str, Customer *&customer);

  /**
   * helper for processing a transaction involving a drama movie
   */
  void processDDVDTran(string &str, Customer *&customer);

  /**
   * helper for processing a transaction involving a classic movie
   */
  void processCDVDTran(string &str, Customer *&customer);

  /**
   * helper for processing transactions
   */
  void processTran(string &str);
};