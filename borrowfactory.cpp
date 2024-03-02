#include "borrow.h"

BorrowFactory::BorrowFactory() { Transaction::rememberType('B', this); }

Transaction *BorrowFactory::create() const { return new Borrow(); }

BorrowFactory strangeBorrowFactory;