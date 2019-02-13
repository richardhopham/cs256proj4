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

#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

template <class T>
class LinkedList {
	public:
		LinkedList();       //default constructor
		~LinkedList();      //destructor

	//Method to return the data stored within the current iterator reference
	T data() const;

	//Method to insert the new data into end of the list
	void insert(T);

	//Method to return the current list length
	long length() const;

	//Method to advance the current iterator. @return -1 if current iterator is NULL
	int advance();

	//Method to reset the iterator back to the head of the list
	void resetIterator();

	private:
		//reference to the head of the list
		Node<T>* head_;

		//reference to the end of the list
		Node<T>* tail_;

		//iterator reference
		Node<T>* iterator_;

		//current list length
		long length_;

};

#endif /** LINKEDLIST **/

template <class T>
LinkedList<T>::LinkedList() {
	head_ = NULL;
	iterator_ = NULL;
	tail_ = NULL;
	length_ = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* temp;
	while(head_) {
		temp = head_;
		head_ = head_->getNext();
		delete temp;
	}
	head_ = NULL;
	iterator_ = NULL;
	tail_ = NULL;
	length_ = 0;
}

template <class T>
T LinkedList<T>::data() const {
	return iterator_->getData();
}

template <class T>
void LinkedList<T>::insert(T data) {
    Node<T>* temp = new Node<T>(data, NULL);
	if(head_ == NULL) {
		head_ = temp;
		tail_ = temp;
		iterator_ = head_;
		length_++;
	} else {
		tail_->setNext(temp);
		tail_ = temp;
		length_++;
	}
}

template <class T>
long LinkedList<T>::length() const {
	return length_;
}

template <class T>
int LinkedList<T>::advance() {
	if(iterator_ == NULL)
		return -1;
	else {
		iterator_ = iterator_->getNext();
		return 0;
	}
}

template <class T>
void LinkedList<T>::resetIterator() {
	iterator_ = head_;
}
