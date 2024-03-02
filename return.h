#include "transaction.h"

class Return : public Transaction {
private:
  // the constructor
  explicit Return();

  // for corresponding factory to access it
  friend class ReturnFactory;
};

class ReturnFactory : public TransactionFactory {
public:
  // the constructor
  ReturnFactory();

  // overrided create function that returns a return transaction
  Transaction *create() const override;
};
