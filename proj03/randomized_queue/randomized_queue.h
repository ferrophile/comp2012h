/*
 * COMP2012H Project 3
 * Hong Wing PANG 20315504
 * randomized_queue.h
 */

#ifndef RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H

#include <cstdlib>
#include <stdexcept>

using namespace std;

#define SIZE	5

template <typename T>
class RandomizedQueue {
	public:
		RandomizedQueue();
		~RandomizedQueue();
		bool isEmpty();
		int size();
		void enqueue(T item);
		T dequeue();
		T sample();

		class Iterator;
		Iterator iterator();
	private:
		void changeSize(int size);
		int maxTop;
		int Top;
		T *values;
};

template <typename T>
class RandomizedQueue<T>::Iterator {
	public:
		Iterator();
		Iterator(const RandomizedQueue<T>& rQueue);
		T operator*();
		Iterator& operator++();
	private:
		T *elem;
};

/*
 * RandomizedQueue class member functions
 */

template <typename T>
RandomizedQueue<T>::RandomizedQueue() : maxTop(SIZE), Top(0), values(new T[SIZE]) {}

template <typename T>
RandomizedQueue<T>::~RandomizedQueue() {
	delete [] values;
}

template <typename T>
bool RandomizedQueue<T>::isEmpty() {
	return (Top == 0);
}

template <typename T>
int RandomizedQueue<T>::size() {
	return Top;
}

template <typename T>
void RandomizedQueue<T>::enqueue(T item) {
	values[Top] = item;
	Top++;

	if (Top == maxTop) {
		changeSize(maxTop+SIZE);
	}
}

template <typename T>
T RandomizedQueue<T>::dequeue() {
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}

	if (Top % SIZE == SIZE - 1) {
		changeSize(maxTop-SIZE);
	}

	int n = rand() % Top;
	T item = values[n];
	values[n] = values[Top-1];
	Top--;

	return item;
}

template <typename T>
T RandomizedQueue<T>::sample() {
	return values[rand() % Top];
}

template <typename T>
typename RandomizedQueue<T>::Iterator RandomizedQueue<T>::iterator() {
	Iterator itr = Iterator(*this);
	return itr;
}

template <typename T>
void RandomizedQueue<T>::changeSize(int size) {
	T* newArray = new T[size];
	for (int i=0; i<Top; i++) {
		newArray[i] = values[i];
	}
	maxTop = size;
	delete [] values;
	values = newArray;
}

/*
 * Iterator class member functions
 */

template <typename T>
RandomizedQueue<T>::Iterator::Iterator() : elem(NULL) {}

template <typename T>
RandomizedQueue<T>::Iterator::Iterator(const RandomizedQueue<T>& rQueue) : elem(rQueue.values) {}

template <typename T>
T RandomizedQueue<T>::Iterator::operator*() {
	return *elem;
}

template <typename T>
typename RandomizedQueue<T>::Iterator& RandomizedQueue<T>::Iterator::operator++() {
	elem += sizeof(T);
	return *this;
}

#endif
