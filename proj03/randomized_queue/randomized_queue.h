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

/*
 * SIZE
 * Specifies how much to increase or decrease each time
 * Can be adjusted to optimize space
 */
#define SIZE	5

//RandomizedQueue class definition
template <typename T>
class RandomizedQueue {
	public:
		//Public member functions
		RandomizedQueue();
		~RandomizedQueue();
		bool isEmpty();
		int size();
		void enqueue(T item);
		T dequeue();
		T sample();

		//Iterator
		class Iterator;
		Iterator iterator();
	private:
		//Utility function
		void changeSize(int size);

		//Private data members
		int maxTop;	//Current capacity of array
		int Top; //Current array size
		T *values; //Data array
};

//Iterator class within RandomizedQueue class definition
template <typename T>
class RandomizedQueue<T>::Iterator {
	public:
		//Public member functions
		Iterator();
		Iterator(const RandomizedQueue<T>& rQueue);

		//Operators
		T operator*();
		Iterator& operator++();
	private:
		//Private data members
		T *elem; //Array element the iterator is pointing to
};

/*
 * RandomizedQueue class member functions
 */

//Deafult constructor
template <typename T>
RandomizedQueue<T>::RandomizedQueue() : maxTop(SIZE), Top(0), values(new T[SIZE]) {}

//Destructor
template <typename T>
RandomizedQueue<T>::~RandomizedQueue() {
	delete [] values; //Delete whole array
}

//Return true if array is empty
template <typename T>
bool RandomizedQueue<T>::isEmpty() {
	return (Top == 0);
}

//Return size of array
template <typename T>
int RandomizedQueue<T>::size() {
	return Top;
}

//Append element to end of array
template <typename T>
void RandomizedQueue<T>::enqueue(T item) {
	values[Top] = item; //Add item to array
	Top++; //Increase array size

	//If reached max size, expand array
	if (Top == maxTop) {
		changeSize(maxTop+SIZE);
	}
}

//Remove an element in array at random
template <typename T>
T RandomizedQueue<T>::dequeue() {
	//If empty, throw error
	if (this->isEmpty()) {
		throw runtime_error("Try to remove item from an empty list.");
	}

	//If have extra space, shrink array
	if (Top % SIZE == 0) {
		changeSize(maxTop-SIZE);
	}

	int n = rand() % Top; //Generate random index
	T item = values[n]; //Store chosen element
	values[n] = values[Top-1]; //Replace it with end item
	Top--; //Decrease array size

	return item;
}

//Return an element in array at random, without removing it
template <typename T>
T RandomizedQueue<T>::sample() {
	return values[rand() % Top];
}

//Create and return new iterator
template <typename T>
typename RandomizedQueue<T>::Iterator RandomizedQueue<T>::iterator() {
	Iterator itr = Iterator(*this);
	return itr;
}

//Change size of array
template <typename T>
void RandomizedQueue<T>::changeSize(int size) {
	//Create array of new size
	T* newArray = new T[size];

	//Copy data from old to new array
	for (int i=0; i<Top; i++) {
		newArray[i] = values[i];
	}

	maxTop = size; //Update array capacity
	delete [] values; //Delete old values
	values = newArray; //Update current array
}

/*
 * Iterator class member functions
 */

//Default constructor
template <typename T>
RandomizedQueue<T>::Iterator::Iterator() : elem(NULL) {}

//Contructor by randomized queue reference, set iterator to first elememt
template <typename T>
RandomizedQueue<T>::Iterator::Iterator(const RandomizedQueue<T>& rQueue) : elem(rQueue.values) {}

//Overload dereference operator
template <typename T>
T RandomizedQueue<T>::Iterator::operator*() {
	return *elem; //Return data of current element
}

//Overload prefix increment operator
template <typename T>
typename RandomizedQueue<T>::Iterator& RandomizedQueue<T>::Iterator::operator++() {
	elem += sizeof(T); //Move iterator to next element
	return *this;
}

#endif
