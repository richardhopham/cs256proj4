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

#include <iostream>
#include "Warehouse.h"

int main(int argc, char** argv) {

    //program requires two input files
	if(argc != 3) {
		cout << "Usage: proj03 <data file> <search list>\n";
		return -1;
	}

	ifstream dataFile;
	dataFile.open(argv[1]);

	ifstream searchFile;
	searchFile.open(argv[2]);

    //check if data file is valid
	if(dataFile.fail()) {
		cout << "Unable to read file: " << argv[1] << endl;
		return -1;
	}

    //check if search file is valid
	if(searchFile.fail()) {
		cout << "Unable to read file: " << argv[2] << endl;
		return -1;
	}

	Warehouse ware;
	dataFile >> ware;

    cout << "---------- List of Books ----------\n" << endl;
	cout << ware << endl;
	cout << "---------- Inventory Search by ISBN ----------\n";

	string isbn;
	Book* book = new PaperbackBook();
	while(getline(searchFile,isbn)) {
		cout << endl << "ISBN: " << isbn << endl;
		if(ware.find(isbn, book)) {
			cout << " -- FOUND:\n";
            cout << *book;
		} else {
			cout << " -- NOT FOUND!!\n";
		}
	}
	delete book;
    dataFile.close();
    searchFile.close();
}
