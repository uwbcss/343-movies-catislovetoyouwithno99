/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

#include "drama.h"

/**
 * the dconstructor that using the Facory when dvdmoive class ask
 * This will remove the object as this is meaning the object of drama is being
 * delete
 *
 * This should not be use as create
 */
DramaFactory::DramaFactory() { DVDMovie::rememberType('D', this); }

/**
 * Create function that returns a drama movie by override the defult in the
 * dvdmovie class
 */
DVDMovie *DramaFactory::create() const { return new Drama(); }

/**
 * Identification This CLASS IS WHAT
 */
DramaFactory strangeDramaFactory;