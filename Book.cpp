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

#include "Book.h"
#include <iostream>

Book::Book() {

}

Book:: ~Book() {

}


istream& operator>> (istream& input, Book& book) {
    string line;
    getline(input, book.title_);

    input >> book.authorCount_;
    getline(input, line);

	for(int i = 0; i < book.authorCount_; i++ ) {
        getline(input, book.authors_[i]);
	}

    getline(input, book.publisher_);
    input >> book.yearPublish_;

	int hardback;
	input >> hardback;
	if(hardback == 1)
		book.hardCover_ = true;
	else
		book.hardCover_ = false;

    input >> book.price_;
    getline(input, line);

	getline(input, book.isbn_);

	input >> book.copies_;
	getline(input, line);
	return input;
}

ostream& operator<< (ostream& output, const Book& book) {
	output << "Title: " << book.title_ << endl;

	for(int i = 0; i < book.authorCount_; i++) {
		output << "Author: " << book.authors_[i] << endl;
	}

	output << "Publisher: " << book.publisher_ << endl;

	output << "Year: " << book.yearPublish_ << endl;

	output << "Cover: " << book.getCoverType() << endl;

	output << "Price: $" << setprecision(2) << fixed << book.price_ << endl;

	output << "ISBN: " << book.isbn_ << endl;

	output << "Copies " << book.copies_ << endl;
	return output;
}

string Book::getPublisher() const {
    return publisher_;
}

string Book::getISBN() const {
	return isbn_;
}

bool Book::getHardcover() const {
	return hardCover_;
}

bool Book::operator== (const Book& book) const{
	bool result = true;
	if(authorCount_ != book.authorCount_)
		result = false;
	else {
		for(int i = 0; i < authorCount_; i++) {
				if(authors_[i] != book.authors_[i])
					result = false;
		}
	}
	if((publisher_ != book.publisher_) || (yearPublish_ != book.yearPublish_)||
	   (hardCover_ != book.hardCover_) || (price_ != book.price_)||
	   (isbn_ != book.isbn_) || (copies_ != book.copies_))
		result = false;
	return result;
}

Book* Book::operator= (const Book& book) {
	if(&book != this) {
		title_ = book.title_;
		authorCount_ = book.authorCount_;

		for(int i = 0; i < authorCount_; i++) {
			authors_[i] = book.authors_[i];
		}
		publisher_ = book.publisher_;
		yearPublish_ = book.yearPublish_;
		hardCover_ = book.hardCover_;
		price_ = book.price_;
		isbn_ = book.isbn_;
		copies_ = book.copies_;
	}
	return this;
}

bool Book::operator> (const Book& book) const{
	if(isbn_.compare(book.getISBN()) > 0)
		return true;
	else
		return false;
}


