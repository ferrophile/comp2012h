#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Node {
	public:
		Node();
		Node(const T& data);
		Node<T> *nextNode();
	private:
		Node<T> *next;
		Node<T> *prev;
		T *data;
};

template <typename T>
class Deque {
	public:
		Deque();
		bool isEmpty();
		int size();
		void addFirst(T item);
		void addLast(T item);
		T removeFirst();
		T removeLast();
		//Iterator
	private:
		Node<T> *head;
		Node<T> *tail;
		int size;
};

/*
 * Node class member functions
 */

//Default constructor
template <typename T>
Node<T>::Node() : prev(NULL), next(NULL), data(NULL) {}

//Type conversion constructor
template <typename T>
Node<T>::Node(const T& data) : prev(NULL), next(NULL), data(new T(t)) {}

//Destructor
template <typename T>
Node<T>::~Node() {
	delete data;
}

//Return next node
template <typename T>
Node<T>* Node<T>::nextNode() {
	return next;
}

/*
 * Deque class member functions
 */

//Default constructor
template <typename T>
Deque<T>::Deque() : head(NULL), tail(NULL), size(0) {}

template <typename T>
bool Deque<T>::isEmpty() {
	return (size == 0);
}

template <typename T>
int Deque<T>::size() {
	return size;
}

template <typename T>
void Deque<T>::addFirst(T item) {
	Node<T> *newNode = new Node<T>(item&);
	if (this->isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	size++;
}

template <typename T>
void Deque<T>::addLast(T item) {
	Node<T> *newNode = new Node<T>(item&);
	if (this->isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	size++;
}

template <typename T>
T Deque<T>::removeFirst() {
	if (this->isEmpty()) {
		//throw error
		return;
	}
	head->next->prev = NULL;
	T *firstData = head->data;
	Node<T> *temp = head;
	head = head->next;
	delete temp;
	size--;
	return *firstData;
}

template <typename T>
T Deque<T>::removeLast() {
	if (this->isEmpty()) {
		//throw error
		return;
	}
	tail->prev->next = NULL;
	T *lastData = tail->data;
	Node<T> *temp = tail;
	tail = tail->prev;
	delete temp;
	size--;
	return *lastData;
}

#endif
