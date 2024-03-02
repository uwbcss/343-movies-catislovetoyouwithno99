#include "return.h"

ReturnFactory::ReturnFactory() { Transaction::rememberType('R', this); }

Transaction *ReturnFactory::create() const { return new Return(); }

ReturnFactory strangeReturnFactory;