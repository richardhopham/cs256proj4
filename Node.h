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

#ifndef NODE
#define NODE

#include <cstddef>

template <class T>
class Node {
	public:
		Node();             //default constructor
		Node(T, Node*);     //constructor to create a Node with T data and a next Node reference
		~Node();            //destructor

		//Method to obtain the internal data
		T getData() const;

		//Method to set the internal data
		void setData(T);

		//Method to obtain the next Node reference
		Node* getNext() const;

		//Method to set the next Node reference
		void setNext(Node*);

	private:
		//the internal data
		T data_;

		//the next node reference
		Node* next_;

};

#endif /** NODE **/

template <class T>
Node<T>::Node() : next_(NULL) {}

template <class T>
Node<T>::Node(T data, Node* next) : data_(data), next_(next) {}

template <class T>
Node<T>::~Node() {
	this->next_ = NULL;
}

template <class T>
T Node<T>::getData() const {
	return this->data_;
}

template <class T>
void Node<T>::setData(T data) {
	this->data_ = data;
}

template <class T>
Node<T>* Node<T>::getNext() const {
	return this->next_;
}

template <class T>
void Node<T>::setNext(Node* next) {
	this->next_ = next;
}
