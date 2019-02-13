/* Richard Pham
** CS256-01, Fall 2017
** Project #4
** Description:
** 	Continue from Project 3. Convert the existing Book class into an abstract base class with a
**  public pure virtual method that returns a string for the cover type. Define two concrete derived
**  classes from the Book class, which both implement the 'getCoverType' method from the base class.
**  Modify the Warehouse class by adding a 'createBook_' method that reads in one set of book data from
**  the input data stream and creates an instance of HardcoverBook or PaperbackBook depending on the input
**  data. The program shall be able to process the same data format and produce the same outputs as in
**  Project 3.
*/

#ifndef WAREHOUSE

#define WAREHOUSE
#include <string>
#include <fstream>
#include "HardcoverBook.h"
#include "PaperbackBook.h"
#include "LinkedList.h"

using namespace std;

//a class named Warehouse
class Warehouse {
    //overloaded stream insertion operator to retrieve its attributes from the provided database
	friend istream& operator >> (istream&, Warehouse&);

	//overloaded stream extraction operator to output all the books read in
	friend ostream& operator << (ostream&, Warehouse&);

	public:
		static const long MAX_BOOKS = 5000;  //max number of books the warehouse can hold

		Warehouse();    //default constructor
		~Warehouse();   //destructor

		bool find(string , Book*);    //function to find book by isbn

	protected:
		bool createBook_(Book*);

	private:
		LinkedList<Book*> list_;         //beginning of linked list of books
		long bookCount_;    //number of books
};
#endif	/** WAREHOUSE **/

