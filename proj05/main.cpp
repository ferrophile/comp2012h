#include "hashTable.h"

int main(int argc, char** argv) {
	HashTable<int, std::string> student(29);

	student.putElem(20315504, "Pang");
	student.putElem(47, "ABCD");
	student.printTable();

	return 0;
}
