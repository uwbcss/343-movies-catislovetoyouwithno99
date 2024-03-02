
#ifndef TRANSACTION
#define TRANSACTION

#include "dvdmovie.h"
#include <iostream>

class TransactionFactory;

class Transaction {
  // for cout
  friend ostream &operator<<(ostream &out, const Transaction &tra);

  // also for cout, but it works with overloading
  virtual ostream &print(std::ostream &out) const;

public:
  // virtual destructor for virtual class
  virtual ~Transaction() = default;

  // type of transaction
  char transactionType;

  // media being transacted
  DVDMovie *movie;

  // remembers the different types of factories
  static void rememberType(const char &type, TransactionFactory *factory);

  // creates a Transaction
  static Transaction *create(const char &type);

private:
  // Value
  static map<char, TransactionFactory *> &getFactories();

  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

class TransactionFactory {
public:
  // virtual to build the Transaction
  virtual Transaction *create() const = 0;
};

#endif
