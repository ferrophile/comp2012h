#include <string>
#include <iostream>
#include "hashTable.h"
#include "student.h"
#include "menu.h"

HashTable<int, Student> student(29);
HashTable<std::string, std::string> course(17);

void test() {
	std::cout << "Hello!" << std::endl;
}

void test2() {
	std::cout << "Hello World!" << std::endl;
}


int main(int argc, char** argv) {
	/*
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

	student.putElem(20315504, Student("Pang Hong Wing", 2, 'M'));
	student.printTable();

	course.putElem("COMP1021", "Python programming");
	course.putElem("COMP2012H", "Intro to OOP");

	course.printTable();
	*/

	Menu rootMenu;
	Menu studentMenu;

	rootMenu.addItem("Student List management", test);
	rootMenu.addItem("Course List management", std::bind(Menu::setActiveMenu, &studentMenu));

	studentMenu.addItem("Test", test2);
	studentMenu.addItem("Back", std::bind(Menu::setActiveMenu, &rootMenu));
	
	Menu::setActiveMenu(&rootMenu);

	while(true) {
		Menu::showActiveMenu();
	}

	return 0;
}
