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

#ifndef BOOK
#define BOOK

#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//a class named Book
class Book {
    //overloaded stream insertion operator to retrieve its attributes from the provided database
	friend istream& operator >> (istream&, Book&);

	//overloaded stream extraction operator to output the values of the data members
	friend ostream& operator << (ostream&, const Book&);

	public:
		static const int MAX_AUTHORS = 20; //max number of authors

		Book();     //default constructor
		virtual ~Book();    //destructor

		string getPublisher() const;                //get Publisher
		string getISBN() const;                     //get ISBN
		bool getHardcover() const;			//get hardCover
		bool operator== (const Book&) const;        //overloaded equality operator to check if two books are equal
		Book* operator= (const Book&);               //overloaded assignment operator to set a book equal to another
		bool operator> (const Book&) const;         //overloaded greater than operator to compare two Book objects

		virtual string getCoverType() const = 0;	//get Cover Type

	private:
		string title_;                          //title of the book
		string authors_[Book::MAX_AUTHORS];     //an array of string, representing authors of the book
		short authorCount_;                     //number of authors
		string publisher_;                      //name of publisher
		short yearPublish_;                     //year book was published
		bool hardCover_;                        //true if book is hard cover, false if paperback
		float price_;                           //price of the book
		string isbn_;                           //isbn number/code
		long copies_;                           //number of copies in the warehouse
};

#endif /** BOOK **/

