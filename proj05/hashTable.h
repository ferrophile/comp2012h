#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <list>
#include <string>
#include <iostream>

template <typename Key, typename Value>
class HashElem {
private:
	Key _key;
	Value _value;
public:
	HashElem();
	HashElem(const Key&, const Value&);
	~HashElem();
	Key getKey();
	Value getValue();
	void setKey(const Key&);
	void setValue(const Value&);

	//ostream operator, for some reason it must be inline...
	friend std::ostream& operator<<(std::ostream& os, const HashElem& elem) {
		os << "{" << elem._key << ", " << elem._value << "}";
		return os;
	}
};

template <typename Key, typename Value>
using hashElemIterator = typename std::list< HashElem<Key, Value> >::iterator;

template <typename Key, typename Value>
class HashTable {
private:
	int size; //no of linked lists
	std::list< HashElem<Key, Value> > * table; //Array of linked lists

	hashElemIterator<Key, Value> getElem(Key k, Value * v = 0);
public:
	HashTable();
	HashTable(int s);
	//HashTable(const HashTable&);
	~HashTable();
	
	int getHashVal(int);
	int getHashVal(std::string);
	
	int getSize();
	bool checkElem(Key k, Value * v = 0);
	bool setElem(Value& newVal, Key k, Value * v = 0);
	bool removeElem(Key k, Value * v = 0);
	void putElem(const Key&, const Value&);
	void printTable();
};

//HashTable class members

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() : size(0) {}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(int s) : size(s) {
	table = new std::list< HashElem<Key, Value> >[size];
}

/*
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable& ht) : size(ht.getSize()) {
	//copy
}
*/

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
	delete [] table;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::getHashVal(int key) {
	return key % size;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::getHashVal(std::string key) {
	int hashVal = 0, charVal = 0;
	int prod = 1;
	for (int i=0; i < key.length(); ++i) {
		if (key[i] >= '0' && key[i] <= '9')
			charVal = key[i] - '0';
		else
			charVal = key[i] - 'A' + 10;
		hashVal = (charVal * prod % size + hashVal) % size;
		prod = prod * 36 % size;
	}
	return hashVal;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::getSize() {
	return size;
}

template <typename Key, typename Value>
hashElemIterator<Key, Value> HashTable<Key, Value>::getElem(Key k, Value * v) {
	hashElemIterator<Key, Value> itr;

	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end() && k != itr->getKey()) {
		++itr;
	}
	if (itr != table[val].end() && v) {
		*v = itr->getValue();
	}
	return itr;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::checkElem(Key k, Value * v) {
	hashElemIterator<Key, Value> itr = getElem(k, v);

	int val = getHashVal(k);
	return itr != table[val].end();
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::setElem(Value& newVal, Key k, Value * v) {
	hashElemIterator<Key, Value> itr = getElem(k, v);

	int val = getHashVal(k);
	if (itr == table[val].end())
		return false; 
	itr->setValue(newVal);
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::removeElem(Key k, Value * v) {
	hashElemIterator<Key, Value> itr = getElem(k, v);

	int val = getHashVal(k);
	if (itr == table[val].end())
		return false; 
	table[val].erase(itr);
	return true;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::putElem(const Key& k, const Value& v) {
	hashElemIterator<Key, Value> itr;
	
	HashElem<Key, Value> elem(k, v);
	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end() && k >= itr->getKey()) {
		if (k == itr->getKey()) {
			std::cout << "Error: Key already exist!" << std::endl;
			return;
		}
		++itr;
	}
	table[val].insert(itr, elem);
}

template <typename Key, typename Value>
void HashTable<Key, Value>::printTable() {
	hashElemIterator<Key, Value> itr;

	for (int i=0; i < size; i++) {
		std::cout << "Bucket " << i << ": ";
		for (itr = table[i].begin(); itr != table[i].end(); ++itr)
			std::cout << *itr << " <- ";
		std::cout << "NULL" << std::endl;
	}
}

//HashElem class members

template <typename Key, typename Value>
HashElem<Key, Value>::HashElem() {}

template <typename Key, typename Value>
HashElem<Key, Value>::HashElem(const Key& k, const Value& v)
: _key(k), _value(v) {}

template <typename Key, typename Value>
HashElem<Key, Value>::~HashElem() {}

template <typename Key, typename Value>
Key HashElem<Key, Value>::getKey() {
	return _key;
}

template <typename Key, typename Value>
Value HashElem<Key, Value>::getValue() {
	return _value;
}

template <typename Key, typename Value>
void HashElem<Key, Value>::setKey(const Key& k) {
	_key = k;
}

template <typename Key, typename Value>
void HashElem<Key, Value>::setValue(const Value& v) {
	_value = v;
}

#endif
