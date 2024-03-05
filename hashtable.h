/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#ifndef HASHNODE
#define HASHNODE

#include "customer.h"
#include <iostream>

using namespace std;

struct HashNode {
public:
  /**
   * Hash Node contains customer pointer and next pointer
   */
  Customer *val;
  HashNode *next;
  /**
   * HashNode constructor
   */
  explicit HashNode(Customer *newCustomer) : val(newCustomer), next(nullptr) {}
};

class HashTable {
public:
  /**
   * insert into hash table
   */
  bool insert(Customer *newCustomer);

  /**
   * retrieve from hash table. ret becomes nullptr if it isn't there
   */
  void retrieve(string idNumber, Customer *&ret);

  /**
   * constructor
   */
  HashTable();

  /**
   *  destructor
   */
  ~HashTable();

private:
  /**
   * number of buckets hashtable has
   */
  const int buckets = 29;

  /**
   * the hashtable itself
   */
  HashNode **hashTable;

  /**
   * hashing function that takes the value of all chars in customer id
   * times their index positions plus one
   */
  int getHash(string &num) const;
};

#endif