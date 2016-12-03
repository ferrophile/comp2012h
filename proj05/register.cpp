#include "register.h"

Register::Register()
:	student(29), 
	course(17),
	rootMenu("HKUST Course Registation System"),
	studentMenu("Student Menu")
	{
	
	rootMenu.addChild("Student Management", &studentMenu);
	rootMenu.addItem("Course Management", std::bind(&Register::foobar, this));
	rootMenu.addItem("Course Registration", std::bind(&Register::foobar, this));
	rootMenu.addItem("Report Management", std::bind(&Register::foobar, this));
	rootMenu.addItem("File Management", std::bind(&Register::foobar, this));
	rootMenu.addItem("Exit", std::bind(&Register::foobar, this));

	studentMenu.addItem("Insert Student Record", std::bind(&Register::studentInsertEntry, this));
	studentMenu.addItem("Modify Student Record", std::bind(&Register::studentModifyEntry, this));
	studentMenu.addItem("Delete Student Record", std::bind(&Register::studentDeleteEntry, this));
	studentMenu.addItem("Debug", std::bind(&Register::debug, this));
	studentMenu.addChild("Back to main menu", &rootMenu);

	Menu::setActiveMenu(&rootMenu);
}

Register::~Register() {}

void Register::studentInsertEntry() {
	int stuID = 0;
	Student stud;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	//check if student already exists here
	/*
	Student temp;
	if (student.getElem(stuID, &temp)) {
		std::cout << "Student already exist: " << temp << std::endl;
		std::cout << std::endl;
		return;
	}
	*/

	std::cout << "Enter the student name: ";
	parseStuName(stud);
	std::cout << "Enter the student year [1-4]: ";
	parseStuYear(stud);
	std::cout << "Enter the student gender [M,F]: ";
	parseStuGender(stud);

	student.putElem(stuID, stud);

	std::cout << "Creation of student record successful" << std::endl;
	std::cout << std::endl;
}

void Register::studentModifyEntry() {
	int stuID = 0;
	Student stud;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.removeElem(stuID, &stud)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the student name [" << stud.getName() << "]: ";
	parseStuName(stud);
	std::cout << "Enter the student year [" << stud.getYear() << "]: ";
	parseStuYear(stud);
	std::cout << "Enter the student gender [" << stud.getGender() << "]: ";
	parseStuGender(stud);

	student.putElem(stuID, stud);

	std::cout << "Modification of student record successful" << std::endl;
	std::cout << std::endl;
}

void Register::studentDeleteEntry() {
	int stuID = 0;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.removeElem(stuID)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Deletion of student record successful" << std::endl;
	std::cout << std::endl;
}


void Register::parseStuID(int* stuID) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = validateStuID(input, stuID);
		if (!state)
			std::cout << "Invalid input, enter again [student ID]: ";
	} while (!state);
}

void Register::parseStuName(Student& s) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = s.setName(input);
		if (!state)
			std::cout << "Invalid input, enter again [student name]: ";
	} while (!state);
}

void Register::parseStuYear(Student& s) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = s.setYear(input);
		if (!state)
			std::cout << "Invalid input, enter again [student year]: ";
	} while (!state);
}

void Register::parseStuGender(Student& s) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = s.setGender(input);
		if (!state)
			std::cout << "Invalid input, enter again [M, F]: ";
	} while (!state);
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
