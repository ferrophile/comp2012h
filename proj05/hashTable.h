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
	};
private:
	int size; //no of linked lists
	list<HashElem> * table; //Array of linked lists
public:
	HashTable();
	HashTable(int size);
	//copy ctor
	~HashTable();
	
	int getHashVal(int);
	int getHashVal(string);
	
	T getElem(T elem);
	void putElem(T elem);
};
