template <typename Key, typename Value>
class HashTable {
	class HashElem {
		friend class HashTable;
	private:
		Key _key;
		Value _value;
	public:
		HashElem();
		HashElem(const Key&, const Value&);
		~HashElem();
		Key getKey();
		Value getValue();
	};
private:
	int size; //no of linked lists
	list<HashElem> * table; //Array of linked lists
public:
	HashTable();
	HashTable(int s);
	//HashTable(const HashTable&);
	~HashTable();
	
	int getHashVal(int);
	int getHashVal(string);
	
	int getSize();
	//HashElem getElem(HashElem elem);
	void putElem(HashElem elem);
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
int HashTable<Key, Value>::getHashVal(string key) {
	//foobar
}

template <typename Key, typename Value>
int HashTable<Key, Value>::getSize() {
	return size;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::putElem(HashElem elem) {
	std::list<HashElem>::iterator l;
	
	int val = getHashVal(elem.getKey());
	table[val]->push_back(elem);
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
