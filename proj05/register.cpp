#include "register.h"

Register::Register()
:	student(29), 
	course(17),
	rootMenu("HKUST Course Registation System"),
	studentMenu("Student Menu")
	{
	
	rootMenu.addChild("Student Management", &studentMenu);
	rootMenu.addItem("Course Management", Register::foobar);
	rootMenu.addItem("Course Registration", Register::foobar);
	rootMenu.addItem("Report Management", Register::foobar);
	rootMenu.addItem("File Management", Register::foobar);
	rootMenu.addItem("Exit", Register::foobar);

	studentMenu.addItem("Insert Student Record", Register::studentAddEntry);
	studentMenu.addItem("Debug", Register::debug);
	studentMenu.addChild("Back to main menu", &rootMenu);

	Menu::setActiveMenu(&rootMenu);
}

Register::~Register() {}

void Register::studentAddEntry() {
	std::string input;
	bool state;

	int stuID = 0;
	Student stud;

	state = false;
	std::cout << "Enter the student ID: ";
	do {
		std::cin >> input;
		state = Register::validateStuID(input, &stuID);
		if (!state)
			std::cout << "Invalid input, enter again [student ID]: ";
	} while (!state);

	//check if student already exists here

	state = false;
	std::cout << "Enter the student name: ";
	do {
		std::cin >> input;
		state = stud.setName(input);
		if (!state)
			std::cout << "Invalid input, enter again [student name]: ";
	} while (!state);
	
	state = false;
	std::cout << "Enter the student year [1-4]: ";
	do {
		std::cin >> input;
		state = stud.setYear(input);
		if (!state)
			std::cout << "Invalid input, enter again [student year]: ";
	} while (!state);
	
	state = false;
	std::cout << "Enter the student gender [M,F]: ";
	do {
		std::cin >> input;
		state = stud.setGender(input);
		if (!state)
			std::cout << "Invalid input, enter again [M, F]: ";
	} while (!state);

	student.putElem(stuID, stud);

	std::cout << "Creation of student record successful" << std::endl;
	std::cout << std::endl;
}

bool Register::validateStuID(std::string input, int* res) {
	int temp = 0;

	if (input.length() != 8) return false;
	try {
		temp = std::stoi(input);
	} catch (...) {
		return false;
	}
	*res = temp;
	return true;
}

void Register::debug() {
	student.printTable();
	std::cout << std::endl;
}
void Register::foobar() {
	std::cout << "Hello World!" << std::endl;
	std::cout << std::endl;
}
