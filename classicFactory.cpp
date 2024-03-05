/**
 *  Created By Houming Ge
 *  Modify By Jack Landers
 *  Date 3/4/2024
 *
 */
#include "classic.h"
/**
 * Classic factory constructor
 */
ClassicFactory::ClassicFactory() { DVDMovie::rememberType('C', this); }
/**
 * create and returns new classic movie
 */
DVDMovie *ClassicFactory::create() const { return new Classic(); }
/**
 * classic factory object for compiler
 */
ClassicFactory strangeClassicFactory;