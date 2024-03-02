/**
 * Created By Houming Ge
 * Modify By Jack Landers
 * Date 3/4/2024
 */

/**
 * The DVD Movie should only contain the itself
 * This head file iwll not contain it child.
 * Child need having its only head file to access this head files
 *
 * Movie Object currly having::
 *
 * Classics (‘C’)  Release date, Major actor
 * Comedy (‘F’)    Title, Year it released
 * Dramas (‘D’)    Director, Title
 *
 * It print should be look like this::
 * Classics   C, Stock, Director, Title, Major actor Release date
 * Comedy     F, Stock, Director, Title, Year it released
 * Drama      D, Stock, Director, Title, Year it released
 *
 */

// All library should be Only important by once time NO MORE
#ifndef DVDMovice
#define DVDMovice

// Library
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Temp locaiton Tell DVD Movie Factory who is it
class DVDMovie;

/**
 * When the DVD movie need created
 * The DVD movie Factory will help the master to created the object
 */
class DVDMovieFactory {
public:
  /**
   * Build the DVDMovie in virtual
   */
  virtual DVDMovie *create() const = 0;
};

class DVDMovie {
  /**
   * When the master need to print the object using the cout
   * This will over write the cout to adapt to the object print
   *
   * @param out Object that pass in to be ready to print on the screen
   * @param mov Object that need to print on the screen
   */
  friend ostream &operator<<(ostream &out, const DVDMovie &mov);

  /**
   * Due to the object is created in polymorphism
   * Cout need a helper method to working with it
   * This is helper function to helping the cout to print
   *
   * @param out The ostream that need to be adding the strign to be print on the
   * screen
   */
  virtual ostream &print(ostream &out) const;

public:
  /**
   * Delete the function that helping the class to clearn when the process is
   * end
   */
  virtual ~DVDMovie() = default;

  /**
   * Helping to remeber the type of this object is
   *
   * @param type the type of the Object that need to be respond to the movie
   * @param factory THe object that reflash to be be created in the time
   */
  static void rememberType(const char &type, DVDMovieFactory *factory);

  /**
   * Creates a DVDMovie
   *
   * @param type the Movie type
   */
  static DVDMovie *create(const char &type);

protected:
  // Base valable for a DVD movie in any factory
  string date;
  string title;
  string director;
  int maxStock;
  int currStock;
  char genre;
  char media;

private:
  // factory list
  static map<char, DVDMovieFactory *> &getFactories();
  friend class MovieStore;
  friend class Inventory;
  friend class Customer;
};

#endif