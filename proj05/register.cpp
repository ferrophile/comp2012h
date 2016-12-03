#include "register.h"

Register::Register()
:	student(29), 
	course(17),
	rootMenu("HKUST Course Registation System"),
	studentMenu("Student Menu") {
	
	rootMenu.addItem("Student List management", Register::test);
	rootMenu.addChild("Course List management", &studentMenu);

	studentMenu.addItem("Test", Register::test2);
	studentMenu.addChild("Back to main menu", &rootMenu);

	Menu::setActiveMenu(&rootMenu);
}

Register::~Register() {}

void Register::test() {
	std::cout << "Hello!" << std::endl;
	std::cout << std::endl;
}

void Register::test2() {
	std::cout << "Hello World!" << std::endl;
	std::cout << std::endl;
}
