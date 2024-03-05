/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#ifndef MANAGER
#define MANAGER

#include "moviestore.h"

class Manager {
public:
  /**
   * constructor
   */
  explicit Manager(vector<string> vec);

  /**
   * destructor
   */
  ~Manager();

private:
  /**
   * vector of stores
   */
  vector<MovieStore *> stores;

  /**
   * creates a store from information
   */
  void createStore(const string &a, const string &b, const string &c);
};

#endif