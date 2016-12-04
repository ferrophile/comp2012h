#include "register.h"

Register::Register()
:	student(STUD_BUCKET_NO), 
	course(COR_BUCKET_NO),
	studentFinder(STUD_BUCKET_NO),
	courseFinder(COR_BUCKET_NO),
	rootMenu("HKUST Course Registation System"),
	studentMenu("Student Menu"),
	courseMenu("Course Menu"),
	regCourseMenu("Registration Menu")
	{
	
	rootMenu.addChild("Student Management", &studentMenu);
	rootMenu.addChild("Course Management", &courseMenu);
	rootMenu.addChild("Course Registration", &regCourseMenu);
	rootMenu.addItem("Report Management", std::bind(&Register::foobar, this));
	rootMenu.addItem("File Management", std::bind(&Register::foobar, this));
	rootMenu.addItem("Exit", std::bind(&Register::foobar, this));

	studentMenu.addItem("Insert Student Record", std::bind(&Register::studentInsertEntry, this));
	studentMenu.addItem("Modify Student Record", std::bind(&Register::studentModifyEntry, this));
	studentMenu.addItem("Delete Student Record", std::bind(&Register::studentDeleteEntry, this));
	studentMenu.addItem("Query Student Record", std::bind(&Register::studentQueryEntry, this));
	studentMenu.addItem("Debug", std::bind(&Register::debug, this));
	studentMenu.addChild("Back to main menu", &rootMenu);

	courseMenu.addItem("Insert Course Record", std::bind(&Register::courseInsertEntry, this));
	courseMenu.addItem("Modify Course Record", std::bind(&Register::courseModifyEntry, this));
	courseMenu.addItem("Delete Course Record", std::bind(&Register::courseDeleteEntry, this));
	courseMenu.addItem("Query Course Record", std::bind(&Register::courseQueryEntry, this));
	courseMenu.addItem("Debug", std::bind(&Register::debug, this));
	courseMenu.addChild("Back to main menu", &rootMenu);

	regCourseMenu.addItem("Add Course", std::bind(&Register::recordAddCourse, this));
	regCourseMenu.addItem("Drop Course", std::bind(&Register::recordDropCourse, this));
	regCourseMenu.addChild("Back to main menu", &rootMenu);

	Menu::setActiveMenu(&rootMenu);
}

Register::~Register() {}

void Register::studentInsertEntry() {
	int stuID = 0;
	Student stud;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	//check if student already exists here
	Student temp;
	if (student.checkElem(stuID, &temp)) {
		std::cout << "Student already exist: " << temp << std::endl;
		std::cout << std::endl;
		return;
	}

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

	if (!student.checkElem(stuID, &stud)) {
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

	student.setElem(stud, stuID);

	std::cout << "Modification of student record successful" << std::endl;
	std::cout << std::endl;
}

void Register::studentDeleteEntry() {
	int stuID = 0;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.removeElemByKey(stuID)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Deletion of student record successful" << std::endl;
	std::cout << std::endl;
}

void Register::studentQueryEntry() {
	int stuID = 0;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	Student stud;
	if (!student.checkElem(stuID, &stud)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << "ID:\t" << stuID << std::endl;
	std::cout << "Name:\t" << stud.getName() << std::endl;
	std::cout << "Year:\t" << stud.getYear() << std::endl;
	std::cout << "Gender:\t" << stud.getGender() << std::endl;
	std::cout << std::endl;
}

void Register::courseInsertEntry() {
	std::string corID;
	Course cor;

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	//check if course already exists here
	Course temp;
	if (course.checkElem(corID, &temp)) {
		std::cout << "Course already exist: " << temp << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the course name: ";
	parseCourseName(cor);
	std::cout << "Enter the no. of credits [0-5]: ";
	parseCourseCredit(cor);

	course.putElem(corID, cor);

	std::cout << "Creation of course record successful" << std::endl;
	std::cout << std::endl;
}

void Register::courseModifyEntry() {
	std::string corID;
	Course cor;

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	if (!course.checkElem(corID, &cor)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the course name [" << cor.getName() << "]: ";
	parseCourseName(cor);
	std::cout << "Enter the no. of credits [" << cor.getCredit() << "]: ";
	parseCourseCredit(cor);

	course.setElem(cor, corID);

	std::cout << "Modification of course record successful" << std::endl;
	std::cout << std::endl;
}

void Register::courseDeleteEntry() {
	std::string corID;

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	if (!course.removeElemByKey(corID)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Deletion of course record successful" << std::endl;
	std::cout << std::endl;
}

void Register::courseQueryEntry() {
	std::string corID;

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	Course cor;
	if (!course.checkElem(corID, &cor)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << "Code:\t" << corID << std::endl;
	std::cout << "Name:\t" << cor.getName() << std::endl;
	std::cout << "Credit:\t" << cor.getCredit() << std::endl;
	std::cout << std::endl;
}

void Register::recordAddCourse() {
	int stuID = 0;
	std::string corID;
	recordIterator itr;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.checkElem(stuID)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	if (!course.checkElem(corID)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	Record record(stuID, corID);
	itr = records.begin();
	while (itr != records.end() && record >= *itr) {
		if (record == *itr) {
			std::cout << "Course already registered!" << std::endl;
			return;
		}
		itr++;
	}
	itr = records.insert(itr, record);

	studentFinder.putElem(stuID, itr);
	courseFinder.putElem(corID, itr);

	std::cout << "Course successfully added" << std::endl;
	std::cout << std::endl;
}

void Register::recordDropCourse() {
	int stuID = 0;
	std::string corID;
	std::vector<recordIterator>::iterator itr;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.checkElem(stuID)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	if (!course.checkElem(corID)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::vector<recordIterator> results = studentFinder.getElemList(stuID);
	itr = results.begin();
	while (itr != results.end()) {
		if(corID == (*itr)->getCorID()) {
			studentFinder.removeElemByVal(stuID, *itr);
			std::cout << "Course sucessfully dropped" << std::endl;
			std::cout << std::endl;
			return;
		}
		itr++;
	}

	std::cout << "Registration record does not exist!" << std::endl;
	std::cout << std::endl;
	return;
}

/*--Parsers, may move them to another file later--*/

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

void Register::parseCourseID(std::string* courseID) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = validateCourseID(input, courseID);
		if (!state)
			std::cout << "Invalid input, enter again [course ID]: ";
	} while (!state);
}

void Register::parseCourseName(Course& c) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = c.setName(input);
		if (!state)
			std::cout << "Invalid input, enter again [course name]: ";
	} while (!state);
}

void Register::parseCourseCredit(Course& c) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = c.setCredit(input);
		if (!state)
			std::cout << "Invalid input, enter again [course credits]: ";
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

bool Register::validateCourseID(std::string input, std::string* res) {
	int len = input.length();
	int i = 0;

	if (len == 8 || len == 9) {
		while (i < len) {
			input[i] = std::toupper(input[i]);
			if (i < 4 && (input[i] < 'A' || input[i] > 'Z'))
				break;
			if ((i >= 4 && i < 8) && (input[i] < '0' || input[i] > '9'))
				break;
			i++;
		}
	}
	if (i == len) {
		*res = input;
		return true;
	}
	return false;
}

void Register::debug() {
	//student.printTable();
	//course.printTable();
	studentFinder.printTable();
	std::cout << std::endl;
}
void Register::foobar() {
	std::cout << "Hello World!" << std::endl;
	std::cout << std::endl;
}
