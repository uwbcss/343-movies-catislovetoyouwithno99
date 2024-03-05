/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "comedy.h"
/**
 * comedy factory object for compiler
 */
ComedyFactory strangeComedyFactory;
/**
 * sets movie type
 */
ComedyFactory::ComedyFactory() { DVDMovie::rememberType('F', this); }
/**
 * override create return new comedy movie
 */
DVDMovie *ComedyFactory::create() const { return new Comedy(); }