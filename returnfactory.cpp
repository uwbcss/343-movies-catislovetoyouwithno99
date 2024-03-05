/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "return.h"
/**
 * Constructor for return factory
 */
ReturnFactory::ReturnFactory() { Transaction::rememberType('R', this); }
/**
 * Overide create return new Return
 */
Transaction *ReturnFactory::create() const { return new Return(); }
/**
 * Compiler happy factory object
 */
ReturnFactory strangeReturnFactory;