#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <list>
#include <string>
#include <iostream>

template <typename Key, typename Value>
class HashTable {
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

		//ostream operator, for some reason it must be inline...
		friend std::ostream& operator<<(std::ostream& os, const HashElem& elem) {
			os << "{" << elem._key << ", " << elem._value << "}";
			return os;
		}
	};
private:
	int size; //no of linked lists
	std::list<HashElem> * table; //Array of linked lists
public:
	HashTable();
	HashTable(int s);
	//HashTable(const HashTable&);
	~HashTable();
	
	int getHashVal(int);
	int getHashVal(std::string);
	
	int getSize();
	//HashElem getElem(HashElem elem);
	void putElem(const Key&, const Value&);
	void printTable();
};

//HashTable class members

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() : size(0) {}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(int s) : size(s) {
	table = new std::list<HashElem>[size];
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
	//think of this later lolz
	return 0;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::getSize() {
	return size;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::putElem(const Key& k, const Value& v) {
	typename std::list<HashElem>::iterator itr;
	
	HashElem elem(k, v);
	int val = getHashVal(k);
	itr = table[val].begin();
	while (itr != table[val].end() && k >= itr->getKey()) {
		if (k == itr->getKey()) {
			std::cout << "Error: Key already exist!";
			return;
		}
		++itr;
	}
	table[val].insert(itr, elem);
}

template <typename Key, typename Value>
void HashTable<Key, Value>::printTable() {
	typename std::list<HashElem>::iterator itr;

	for (int i=0; i < size; i++) {
		std::cout << "Bucket " << i << ": ";
		for (itr = table[i].begin(); itr != table[i].end(); ++itr)
			std::cout << *itr << " <- ";
		std::cout << "NULL" << std::endl;
	}
}

//HashElem class members

template <typename Key, typename Value>
HashTable<Key, Value>::HashElem::HashElem() {}

template <typename Key, typename Value>
HashTable<Key, Value>::HashElem::HashElem(const Key& k, const Value& v)
: _key(k), _value(v) {}

template <typename Key, typename Value>
HashTable<Key, Value>::HashElem::~HashElem() {}

template <typename Key, typename Value>
Key HashTable<Key, Value>::HashElem::getKey() {
	return _key;
}

template <typename Key, typename Value>
Value HashTable<Key, Value>::HashElem::getValue() {
	return _value;
}

//perform validation here later

#endif
