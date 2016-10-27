/*
 * COMP2012H Project 3
 * Hong Wing PANG 20315504
 * deque.h
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <cstdlib>
#include <stdexcept>

using namespace std;

//Node class definition
template <typename T>
class Node {
	public:
		//Member functions and data members
		Node();
		Node(const T& data);
		~Node();
		Node<T> *next; //Next node
		Node<T> *prev; //Previous node
		T *data; //Node data
};

//Deque class defition
template <typename T>
class Deque {
	public:
		//Public member functions
		Deque();
		~Deque();
		bool isEmpty();
		int size();
		void addFirst(T item);
		void addLast(T item);
		T removeFirst();
		T removeLast();
		
		//Iterator
		class Iterator;
		Iterator iterator();
	private:
		//Private data members
		Node<T> *head; //Pointer to head of deque
		Node<T> *tail; //Pointer to tail of deque
		int dequeSize; //Size of deque
};

//Iterator class within Deque class definition
template <typename T>
class Deque<T>::Iterator {
	public:
		Iterator();
		Iterator(const Deque<T>& deque);
		T operator*();
		Iterator& operator++();
	private:
		Node<T> *curNode;
};

/*
 * Node class member functions
 */

//Default constructor
template <typename T>
Node<T>::Node() : prev(NULL), next(NULL), data(NULL) {}

//Type conversion constructor
template <typename T>
Node<T>::Node(const T& data) : prev(NULL), next(NULL), data(new T(data)) {}

//Destructor
template <typename T>
Node<T>::~Node() {
	delete data;
}

/*
 * Deque class member functions
 */

//Default constructor
template <typename T>
Deque<T>::Deque() : head(NULL), tail(NULL), dequeSize(0) {}

//Destructor
template <typename T>
Deque<T>::~Deque() {
	//If empty deque, no need delete nodes
	if (this->isEmpty()) return;

	//Delete nodes one by one
	Node<T>* cur = head;
	while(cur != tail) {
		cur = cur->next;
		delete cur->prev;
	}
	delete cur;
}

//Return true if deque is empty
template <typename T>
bool Deque<T>::isEmpty() {
	return (dequeSize == 0);
}

//Return size of deque
template <typename T>
int Deque<T>::size() {
	return dequeSize;
}

//Append element to head of deque
template <typename T>
void Deque<T>::addFirst(T item) {
	Node<T> *newNode = new Node<T>(item);
	if (this->isEmpty()) {
		//First element, set it as both head and tail
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head; //New node prev point to current head
		head->prev = newNode; //Current head next point to new node
		head = newNode; //Update head
	}

	//Increase deque size
	dequeSize++;
}

//Append element to end of deque
template <typename T>
void Deque<T>::addLast(T item) {
	Node<T> *newNode = new Node<T>(item);
	if (this->isEmpty()) {
		//First element, set it as both head and tail
		head = newNode;
		tail = newNode;
	} else {
		newNode->prev = tail; //New node prev point to current tail
		tail->next = newNode; //Current tail next point to new node
		tail = newNode; //Update tail
	}
	
	//Increase deque size
	dequeSize++;
}

//Remove element from head of deque
template <typename T>
T Deque<T>::removeFirst() {
	//If empty, throw error
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}

	//Temporarily store current head node
	T firstData = *(head->data);
	Node<T> *temp = head;

	if (this->size() == 1) {
		//If last element, set deque as empty
		head = NULL;
		tail = NULL;
	} else {
		head->next->prev = NULL; //Set next node prev as NULL
		head = head->next; //Update head
	}
	delete temp; //Delete old node
	dequeSize--; //Decrease deque size
	return firstData;
}

//Remove element from tail of deque
template <typename T>
T Deque<T>::removeLast() {
	//If empty, throw error
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}

	//Temporarily store current tail node
	T lastData = *(tail->data);
	Node<T> *temp = tail;

	if (this->size() == 1) {
		//If last element, set deque as empty
		head = NULL;
		tail = NULL;
	} else {
		tail->prev->next = NULL; //Set next node next as NULL
		tail = tail->prev; //Update tail
	}
	delete temp; //Delete old node
	dequeSize--; //Decrease deque size
	return lastData;
}

//Create and return new iterator
template <typename T>
typename Deque<T>::Iterator Deque<T>::iterator() {
	Iterator itr = Iterator(*this);
	return itr;
}

/*
 * Iterator class member functions
 */

//Default constructor
template <typename T>
Deque<T>::Iterator::Iterator() : curNode(NULL) {}

//Constructor by deque reference, set current node to head node
template <typename T>
Deque<T>::Iterator::Iterator(const Deque<T>& deque) : curNode(deque.head) {}

//Overload dereference operator
template <typename T>
T Deque<T>::Iterator::operator*() {
	return *(curNode->data); //Return data of current node
}

//Overload prefix increment operator
template <typename T>
typename Deque<T>::Iterator& Deque<T>::Iterator::operator++() {
	curNode = curNode->next; //Move iterator to next element
	return *this;
}

#endif
