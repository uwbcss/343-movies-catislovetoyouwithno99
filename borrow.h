
#ifndef BORROW
#define BORROW

#include "transaction.h"

class Borrow : public Transaction {
private:
  // the constructor
  explicit Borrow();

  // Friend that should be connect with
  friend class BorrowFactory;
  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

class BorrowFactory : public TransactionFactory {
public:
  // the constructor
  BorrowFactory();

  // overrided create function that returns a borrow transaction
  Transaction *create() const override;
};

#endif