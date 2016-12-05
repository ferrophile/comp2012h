#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename Key, typename Value>
class HashElem {
private:
	Key _key;
	Value _value;
public:
	HashElem();
	HashElem(const Key&, const Value&);
	~HashElem();
	Key getKey() const;
	Value getValue() const;
	void setKey(const Key&);
	void setValue(const Value&);
	bool operator<(const HashElem&);

	//ostream operator, for some reason it must be inline...
	friend std::ostream& operator<<(std::ostream& os, const HashElem& elem) {
		os << elem._key;
		//os << "{" << elem._key << ", " << elem._value << "}";
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

	hashElemIterator<Key, Value> getElemByKey(Key k, Value * v = 0);
public:
	HashTable();
	HashTable(int s);
	HashTable(const HashTable<Key, Value>&);
	~HashTable();
	
	int getHashVal(int);
	int getHashVal(std::string);
	
	int getSize();
	std::vector<Value> getElemList(Key k);
	std::vector< HashElem<Key, Value> > getAllElem();
	std::list< HashElem<Key, Value> > getBucket(int i) const;
	bool checkElem(Key k, Value * v = 0);
	bool setElem(Value& newVal, Key k);
	bool removeElemByKey(Key k);
	bool removeElemByVal(Key k, Value delVal);
	void putElem(const Key&, const Value&);
	void printTable();
	HashTable<Key, Value>& operator=(const HashTable<Key, Value>&);
};

//HashTable class members

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() : size(0) {}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(int s) : size(s) {
	table = new std::list< HashElem<Key, Value> >[size];
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable<Key, Value>& ht) : size(ht.getSize()) {
	for (int i=0; i < size; i++) {
		table[i] = getBucket(i);
	}
}

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
hashElemIterator<Key, Value> HashTable<Key, Value>::getElemByKey(Key k, Value * v) {
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
std::vector<Value> HashTable<Key, Value>::getElemList(Key k) {
	hashElemIterator<Key, Value> itr;
	std::vector<Value> values;

	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end()) {
		if (k == itr->getKey())
			values.push_back(itr->getValue());
		itr++;
	}
	return values;
}

template <typename Key, typename Value>
std::vector< HashElem<Key, Value> > HashTable<Key, Value>::getAllElem() {
	hashElemIterator<Key, Value> itr;
	std::vector< HashElem<Key, Value> > elemArray;

	for (int i=0; i < size; i++) {
		for (itr = table[i].begin(); itr != table[i].end(); itr++) {
			elemArray.push_back(*itr);
		}
	}

	std::sort(elemArray.begin(), elemArray.end());
	return elemArray;
}

template <typename Key, typename Value>
std::list< HashElem<Key, Value> > HashTable<Key, Value>::getBucket(int i) const {
	if (i > size || i < 0) i = 0;
	return table[i];
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::checkElem(Key k, Value * v) {
	hashElemIterator<Key, Value> itr = getElemByKey(k, v);

	int val = getHashVal(k);
	return itr != table[val].end();
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::setElem(Value& newVal, Key k) {
	hashElemIterator<Key, Value> itr = getElemByKey(k);

	int val = getHashVal(k);
	if (itr == table[val].end())
		return false; 
	itr->setValue(newVal);
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::removeElemByKey(Key k) {
	hashElemIterator<Key, Value> itr = getElemByKey(k);

	int val = getHashVal(k);
	if (itr == table[val].end())
		return false; 
	table[val].erase(itr);
	return true;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::removeElemByVal(Key k, Value delVal) {
	hashElemIterator<Key, Value> itr;
	std::vector<Value> values;

	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end()) {
		if (k == itr->getKey() && delVal == itr->getValue()) {
			table[val].erase(itr);
			break;
		}
		itr++;
	}
	return itr != table[val].end();
}

template <typename Key, typename Value>
void HashTable<Key, Value>::putElem(const Key& k, const Value& v) {
	hashElemIterator<Key, Value> itr;
	
	HashElem<Key, Value> elem(k, v);
	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end() && k >= itr->getKey()) {
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

template <typename Key, typename Value>
HashTable<Key, Value>& HashTable<Key, Value>::operator=(const HashTable<Key, Value>& ht) {
	for (int i=0; i < size; i++) {
		table[i] = ht.getBucket(i);
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
Key HashElem<Key, Value>::getKey() const {
	return _key;
}

template <typename Key, typename Value>
Value HashElem<Key, Value>::getValue() const {
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

template <typename Key, typename Value>
bool HashElem<Key, Value>::operator<(const HashElem& elem) {
	return _key < elem.getKey();
}

#endif
