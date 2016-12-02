#include <string>
#include <iostream>
#include "hashTable.h"

HashTable<int, std::string> student(29);
HashTable<std::string, std::string> course(17);

void printKey(int k) {
	std::string result;
	if (student.getElem(k, &result))
		std::cout << result << std::endl;
	else
		std::cout << "Cannot find entry!" << std::endl;
}

int main(int argc, char** argv) {
	student.putElem(20315504, "Pang Hong Wing");
	student.putElem(12219689, "Rex Cheng");
	student.putElem(20319823, "Jonathan Liu");
	student.putElem(20313207, "Kristian Suhartono");
	student.putElem(20346773, "Simon Tam");
	student.putElem(20309610, "Kenta Iwasaki");

	student.putElem(58, "TestStu1");
	student.putElem(29, "TestStu2");
	student.putElem(0, "TestStu3");
	student.putElem(0, "TestStu3");

	student.printTable();

	course.putElem("COMP1021", "Python programming");
	course.putElem("COMP2012H", "Intro to OOP");

	course.printTable();

	printKey(0);
	printKey(12219689);
	printKey(479);

	return 0;
}
