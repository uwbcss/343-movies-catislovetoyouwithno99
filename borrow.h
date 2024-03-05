/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#ifndef BORROW
#define BORROW

#include "transaction.h"
/**
 *  Borrow child of transaction when command comes from the file
 */
class Borrow : public Transaction {
private:
  /**
   * Constructor for the borrow class
   */
  explicit Borrow();

  /**
   * Friend classes that should be able to see borrow
   */
  friend class BorrowFactory;
  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

class BorrowFactory : public TransactionFactory {
public:
  /**
   * Borrow Factory Constructor
   */
  BorrowFactory();

  /**
   * Overidded create method and return burrow transaction
   */
  Transaction *create() const override;
};

#endif