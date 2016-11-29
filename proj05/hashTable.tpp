template <typename T>
class HashTable {
private:
	int size; //no of linked lists
	list<T> * table; //List of linked lists
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	int getHashVal();
	T getElem(T elem);
	void putElem(T elem);
}
