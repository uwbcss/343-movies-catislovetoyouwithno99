/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "manager.h"
/**
 *Manager constructor
 */
Manager::Manager(vector<string> vec) {
  for (int i = 0; i < vec.size(); i += 3) {
    createStore(vec[i], vec[i + 1], vec[i + 2]);
  }
}
/**
 * destructor
 */
Manager::~Manager() {
  for (auto &i : stores) {
    delete i;
  }
}
/**
 *create store
 */
void Manager::createStore(const string &a, const string &b, const string &c) {
  stores.emplace_back(new MovieStore(a, b, c));
}