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

template <typename T>
class Node {
	public:
		Node();
		Node(const T& data);
		~Node();
		Node<T> *next;
		Node<T> *prev;
		T *data;
};

template <typename T>
class Deque {
	public:
		Deque();
		~Deque();
		bool isEmpty();
		int size();
		void addFirst(T item);
		void addLast(T item);
		T removeFirst();
		T removeLast();
		
		class Iterator;
		Iterator iterator();
	private:
		Node<T> *head;
		Node<T> *tail;
		int dequeSize;
};

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

template <typename T>
Deque<T>::~Deque() {
	if (this->isEmpty()) return;
	Node<T>* cur = head;
	while(cur != tail) {
		cur = cur->next;
		delete cur->prev;
	}
	delete cur;
}

template <typename T>
bool Deque<T>::isEmpty() {
	return (dequeSize == 0);
}

template <typename T>
int Deque<T>::size() {
	return dequeSize;
}

template <typename T>
void Deque<T>::addFirst(T item) {
	Node<T> *newNode = new Node<T>(item);
	if (this->isEmpty()) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	dequeSize++;
}

template <typename T>
void Deque<T>::addLast(T item) {
	Node<T> *newNode = new Node<T>(item);
	if (this->isEmpty()) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	dequeSize++;
}

template <typename T>
T Deque<T>::removeFirst() {
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}
	T firstData = *(head->data);
	Node<T> *temp = head;
	if (this->size() == 1) {
		head = NULL;
	} else {
		head->next->prev = NULL;
		head = head->next;
	}
	delete temp;
	dequeSize--;
	return firstData;
}

template <typename T>
T Deque<T>::removeLast() {
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}
	T lastData = *(tail->data);
	Node<T> *temp = tail;
	if (this->size() == 1) {
		head = NULL;
	} else {
		tail->prev->next = NULL;
		tail = tail->prev;
	}
	delete temp;
	dequeSize--;
	return lastData;
}

template <typename T>
typename Deque<T>::Iterator Deque<T>::iterator() {
	Iterator itr = Iterator(*this);
	return itr;
}

/*
 * Iterator class member functions
 */

template <typename T>
Deque<T>::Iterator::Iterator() : curNode(NULL) {}

template <typename T>
Deque<T>::Iterator::Iterator(const Deque<T>& deque) : curNode(deque.head) {}

template <typename T>
T Deque<T>::Iterator::operator*() {
	return *(curNode->data);
}

template <typename T>
typename Deque<T>::Iterator& Deque<T>::Iterator::operator++() {
	curNode = curNode->next;
	return *this;
}

#endif
