/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "transaction.h"
/**
 * for printing transaction cout
 */
ostream &Transaction::print(ostream &out) const {
  out << "Transaction Type: " << transactionType << endl;
  out << *movie << endl;
  return out;
}
/**
 * print transaction
 */
ostream &operator<<(ostream &out, const Transaction &tra) {
  return tra.print(out);
}
/**
 * for factory to remember/ allow types of factories
 */
void Transaction::rememberType(const char &type, TransactionFactory *factory) {
  getFactories().emplace(type, factory);
}
/**
 * create the factories for the types
 */
Transaction *Transaction::create(const char &type) {
  if (getFactories().count(type) > 0) {
    return getFactories().at(type)->create();
  }
  cerr << "Error: No factory exists for " << type << "!" << endl;
  return nullptr;
}
/**
 * get all the factories
 */
map<char, TransactionFactory *> &Transaction::getFactories() {
  static map<char, TransactionFactory *> factories;
  return factories;
}