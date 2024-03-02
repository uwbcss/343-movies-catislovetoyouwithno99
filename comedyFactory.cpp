#include "comedy.h"

ComedyFactory strangeComedyFactory;
ComedyFactory::ComedyFactory() { DVDMovie::rememberType('F', this); }

DVDMovie *ComedyFactory::create() const { return new Comedy(); }