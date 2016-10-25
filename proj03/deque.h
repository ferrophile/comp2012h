#ifndef DEQUE_H
#define DEQUE_H

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
		int size;
};

template <typename T>
class Deque<T>::Iterator {
	public:
		Iterator();
		Iterator(const Deque<T>& deque);
		T operator*();
		Iterator& operator++();
	private:
		Node *curNode;
}

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
Deque<T>::Deque() : head(NULL), tail(NULL), size(0) {}

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

Iterator Deque<T>::iterator() {
	Iterator itr = Iterator(*this);
	return itr;
}

/*
 * Iterator class member functions
 */

Deque<T>::Iterator::Iterator() : node(NULL) {}

Deque<T>::Iterator::Iterator(const Deque<T>& deque) : node(deque.head) {}

T Deque<T>::Iterator::operator*() {
	return *(curNode->data);
}

Iterator& Deque<T>::Iterator::operator++() {
	curNode = curNode->next;
	return *this;
}

#endif
