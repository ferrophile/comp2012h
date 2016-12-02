#include "hashTable.h"

int main(int argc, char** argv) {
	HashTable<int, std::string> student(29);

	student.putElem(20315504, "Pang Hong Wing");
	student.putElem(12219689, "Rex Cheng");
	student.putElem(20319823, "Jonathan Liu");
	student.putElem(20313207, "Kristian Suhartono");
	student.putElem(20346773, "Simon Tam");
	student.putElem(20309610, "Kenta Iwasaki");

	student.putElem(58, "TestStu1");
	student.putElem(29, "TestStu2");
	student.putElem(0, "TestStu3");

	student.printTable();

	return 0;
}
