/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "borrow.h"
/**
 * Borrow constructor
 */
BorrowFactory::BorrowFactory() { Transaction::rememberType('B', this); }
/**
 * overidde create
 * return new Borrow
 */
Transaction *BorrowFactory::create() const { return new Borrow(); }
/**
 * factory that is not used
 */
BorrowFactory strangeBorrowFactory;