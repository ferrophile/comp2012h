/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * register.cpp
 */

#include "register.h"

//Constructor, initializes the data members
Register::Register()
:	student(STUD_BUCKET_NO), 
	course(COR_BUCKET_NO),
	studentFinder(STUD_BUCKET_NO),
	courseFinder(COR_BUCKET_NO),
	records(new std::list<Record>),
	activeGenerator(0),
	activeFileManager(0),
	rootMenu("HKUST Course Registation System"),
	studentMenu("Student Menu"),
	courseMenu("Course Menu"),
	regCourseMenu("Registration Menu"),
	reportMenu("Report Generation Menu"),
	fileMenu("File Menu")
	{
	
	//Set up menu
	rootMenu.addChild("Student Management", &studentMenu);
	rootMenu.addChild("Course Management", &courseMenu);
	rootMenu.addChild("Course Registration", &regCourseMenu);
	rootMenu.addChild("Report Management", &reportMenu);
	rootMenu.addChild("File Management", &fileMenu);
	rootMenu.addItem("Exit", Menu::exitMenu);

	studentMenu.addItem("Insert Student Record", std::bind(&Register::studentInsertEntry, this));
	studentMenu.addItem("Modify Student Record", std::bind(&Register::studentModifyEntry, this));
	studentMenu.addItem("Delete Student Record", std::bind(&Register::studentDeleteEntry, this));
	studentMenu.addItem("Query Student Record", std::bind(&Register::studentQueryEntry, this));
	studentMenu.addChild("Back to main menu", &rootMenu);

	courseMenu.addItem("Insert Course Record", std::bind(&Register::courseInsertEntry, this));
	courseMenu.addItem("Modify Course Record", std::bind(&Register::courseModifyEntry, this));
	courseMenu.addItem("Delete Course Record", std::bind(&Register::courseDeleteEntry, this));
	courseMenu.addItem("Query Course Record", std::bind(&Register::courseQueryEntry, this));
	courseMenu.addChild("Back to main menu", &rootMenu);

	regCourseMenu.addItem("Add Course", std::bind(&Register::recordAddCourse, this));
	regCourseMenu.addItem("Drop Course", std::bind(&Register::recordDropCourse, this));
	regCourseMenu.addItem("Modify Exam Mark", std::bind(&Register::recordModifyMark, this));
	regCourseMenu.addItem("Query Registration", std::bind(&Register::recordQueryEntry, this));
	regCourseMenu.addChild("Back to main menu", &rootMenu);

	reportMenu.addItem("List all students information", std::bind(&Register::genStudentReport, this));
	reportMenu.addItem("List all courses information", std::bind(&Register::genCourseReport, this));
	reportMenu.addItem("List all courses of a student", std::bind(&Register::genStudentCourseReport, this));
	reportMenu.addItem("List all students of a course", std::bind(&Register::genCourseStudentReport, this));
	reportMenu.addChild("Back to main menu", &rootMenu);

	fileMenu.addItem("Save Database", std::bind(&Register::saveDatabase, this));
	fileMenu.addItem("Load Database", std::bind(&Register::loadDatabase, this));
	fileMenu.addChild("Back to main menu", &rootMenu);

	Menu::setActiveMenu(&rootMenu);
}

//Destructor
Register::~Register() {
	delete records;
}

/*
 *Student menu functions
 */

//Insert student entry to Student hash table
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

//Modify student entry
void Register::studentModifyEntry() {
	int stuID = 0;
	Student stud;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	//check if student exists
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

//Delete student entry
void Register::studentDeleteEntry() {
	int stuID = 0;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	//check if student exists
	if (!student.removeElemByKey(stuID)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	//check if student is deletable
	std::vector<recordIterator> results = studentFinder.getElemList(stuID);
	if (results.size() != 0) {
		std::cout << "Student has registered courses, cannot delete!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Deletion of student record successful" << std::endl;
	std::cout << std::endl;
}

//Query student entry
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

/*
 * Course menu functions
 * more or less same as the above
 */

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

	std::vector<recordIterator> results = courseFinder.getElemList(corID);
	if (results.size() != 0) {
		std::cout << "Course has been registered by students, cannot delete!" << std::endl;
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

/*
 * Registration menu functions
 */

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
	itr = records->begin();
	while (itr != records->end() && record >= *itr) {
		if (record == *itr) {
			std::cout << "Course already registered!" << std::endl;
			return;
		}
		itr++;
	}
	itr = records->insert(itr, record);

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
			records->erase(*itr);
			std::cout << "Course successfully dropped" << std::endl;
			std::cout << std::endl;
			return;
		}
		itr++;
	}

	std::cout << "Registration record does not exist!" << std::endl;
	std::cout << std::endl;
}

void Register::recordModifyMark() {
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
			std::cout << "Enter the exam mark [" << (*itr)->showExamMark() << "]: ";

			parseExamMark(*itr);
			std::cout << "Exam mark successfully modified" << std::endl;
			std::cout << std::endl;
			return;
		}
		itr++;
	}

	std::cout << "Registration record does not exist!" << std::endl;
	std::cout << std::endl;
}

void Register::recordQueryEntry() {
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
			std::cout << std::endl;
			std::cout << "Student ID:\t" << stuID << std::endl;
			std::cout << "Course Code:\t" << corID << std::endl;
			std::cout << "Exam Mark:\t" << (*itr)->showExamMark() << std::endl;
			std::cout << std::endl;
			return;
		}
		itr++;
	}

	std::cout << "Registration record does not exist!" << std::endl;
	std::cout << std::endl;
}

/*
 * Report generation menu functions
 */

void Register::genStudentReport() {
	std::vector< HashElem<int, Student> > studArray = student.getAllElem();
	std::vector< HashElem<int, Student> >::iterator itr;

	activeGenerator = new ReportGenerator("Students.html", "List of all students");
	activeGenerator->writeHtmlHeader();

	if (studArray.size() == 0) {
		activeGenerator->writeString("No students found");
	} else {
		activeGenerator->writeTableHeader();
		std::vector<std::string> entry = {"Student ID", "Student Name", "Year", "Gender"};
		activeGenerator->writeTableRow(entry, true);

		for (itr = studArray.begin(); itr != studArray.end(); itr++) {
			std::string key = std::to_string(itr->getKey());
			Student value = itr->getValue();

			entry.clear();
			entry.push_back(key);
			entry.push_back(value.getName());
			entry.push_back(std::to_string(value.getYear()));
			entry.push_back(value.getGender());
			activeGenerator->writeTableRow(entry);
		}
		activeGenerator->writeTableFooter();
	}

	activeGenerator->writeHtmlFooter();
	delete activeGenerator;
	std::cout << "Output successful" << std::endl;
	std::cout << std::endl;
}

void Register::genCourseReport() {
	std::vector< HashElem<std::string, Course> > corArray = course.getAllElem();
	std::vector< HashElem<std::string, Course> >::iterator itr;

	activeGenerator = new ReportGenerator("Courses.html", "List of all courses");
	activeGenerator->writeHtmlHeader();

	if (corArray.size() == 0) {
		activeGenerator->writeString("No courses found");
	} else {
		activeGenerator->writeTableHeader();
		std::vector<std::string> entry = {"Course Code", "Course Name", "Credit"};
		activeGenerator->writeTableRow(entry, true);

		for (itr = corArray.begin(); itr != corArray.end(); itr++) {
			std::string key = itr->getKey();
			Course value = itr->getValue();

			entry.clear();
			entry.push_back(key);
			entry.push_back(value.getName());
			entry.push_back(std::to_string(value.getCredit()));
			activeGenerator->writeTableRow(entry);
		}
		activeGenerator->writeTableFooter();
	}

	activeGenerator->writeHtmlFooter();
	delete activeGenerator;
	std::cout << "Output successful" << std::endl;
	std::cout << std::endl;
}

void Register::genStudentCourseReport() {
	int stuID = 0;
	std::vector<recordIterator>::iterator itr;
	std::vector<Record> recordList;
	std::vector<Record>::iterator recItr;
	Student stud;

	std::cout << "Enter the student ID: ";
	parseStuID(&stuID);

	if (!student.checkElem(stuID, &stud)) {
		std::cout << "Student does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::string filename = std::to_string(stuID) + ".html";
	activeGenerator = new ReportGenerator(filename, "Course Records for Student", stud.getName(), std::to_string(stuID));
	activeGenerator->writeHtmlHeader();

	std::vector<recordIterator> results = studentFinder.getElemList(stuID);
	for (itr = results.begin(); itr != results.end(); itr++) {
		recordList.push_back(**itr);
	}

	if (results.size() == 0) {
		activeGenerator->writeString("Student hasn't taken any courses");
	} else {
		activeGenerator->writeTableHeader();
		std::vector<std::string> entry = {"Course Code", "Course Name", "Credit", "Exam Mark"};
		activeGenerator->writeTableRow(entry, true);


		std::sort(recordList.begin(), recordList.end());

		for (recItr = recordList.begin(); recItr != recordList.end(); recItr++) {
			std::string corID = recItr->getCorID();
			Course cor;
			course.checkElem(corID, &cor);

			entry.clear();
			entry.push_back(corID);
			entry.push_back(cor.getName());
			entry.push_back(std::to_string(cor.getCredit()));
			entry.push_back(recItr->showExamMark());
			activeGenerator->writeTableRow(entry);
		}
		activeGenerator->writeTableFooter();
	}

	activeGenerator->writeHtmlFooter();
	delete activeGenerator;
	std::cout << "Output successful" << std::endl;
	std::cout << std::endl;
}

void Register::genCourseStudentReport() {
	std::string corID;
	std::vector<recordIterator>::iterator itr;
	std::vector<Record> recordList;
	std::vector<Record>::iterator recItr;
	Course cor;

	std::cout << "Enter the course ID: ";
	parseCourseID(&corID);

	if (!course.checkElem(corID, &cor)) {
		std::cout << "Course does not exist!" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::string filename = corID + ".html";
	activeGenerator = new ReportGenerator(filename, "Student Records for Course", cor.getName(), corID);
	activeGenerator->writeHtmlHeader();

	std::vector<recordIterator> results = courseFinder.getElemList(corID);
	for (itr = results.begin(); itr != results.end(); itr++) {
		recordList.push_back(**itr);
	}

	if (results.size() == 0) {
		activeGenerator->writeString("No student takes this course");
	} else {
		activeGenerator->writeTableHeader();
		std::vector<std::string> entry = {"Student ID", "Student Name", "Year", "Gender", "Exam Mark"};
		activeGenerator->writeTableRow(entry, true);

		std::sort(recordList.begin(), recordList.end());

		for (recItr = recordList.begin(); recItr != recordList.end(); recItr++) {
			int stuID = recItr->getStuID();
			Student stud;
			student.checkElem(stuID, &stud);

			entry.clear();
			entry.push_back(std::to_string(stuID));
			entry.push_back(stud.getName());
			entry.push_back(std::to_string(stud.getYear()));
			entry.push_back(stud.getGender());
			entry.push_back(recItr->showExamMark());
			activeGenerator->writeTableRow(entry);
		}
		activeGenerator->writeTableFooter();
	}

	activeGenerator->writeHtmlFooter();
	delete activeGenerator;
	std::cout << "Output successful" << std::endl;
	std::cout << std::endl;
}

/*
 * File menu functions
 */

void Register::saveDatabase() {
	std::vector< HashElem<int, Student> > studArray = student.getAllElem();
	std::vector< HashElem<int, Student> >::iterator studItr;
	std::vector< HashElem<std::string, Course> > corArray = course.getAllElem();
	std::vector< HashElem<std::string, Course> >::iterator corItr;
	std::list<Record>::iterator recItr;
	Student stud;
	Course cor;
	Record rec;

	std::string filename = "";
	std::cout << "Enter file name: ";
	std::getline(std::cin, filename);
	activeFileManager = new FileManager(filename);
	activeFileManager->openOutFile();
	if (!(activeFileManager->isFileOpen())) {
		std::cout << "Error: cannot open file" << std::endl;
		std::cout << std::endl;
		return;
	}

	int temp, len;
	std::string corCode;
	
	//Student Table
	activeFileManager->writeInt(NEW_TABLE_FLAG);
	activeFileManager->writeInt(studArray.size());
	for (studItr = studArray.begin(); studItr != studArray.end(); studItr++) {
		stud = studItr->getValue();
		temp = stud.getYear() + ((stud.getGender() == "F") ? 4 : 0);
		len = stud.getName().length();

		activeFileManager->writeInt(NEW_ENTRY_FLAG);
		activeFileManager->writeString(std::to_string(studItr->getKey()));
		activeFileManager->writeInt(len);
		activeFileManager->writeString(stud.getName());
		activeFileManager->writeInt(len);
		activeFileManager->writeInt(temp);
	}

	//Course Table
	activeFileManager->writeInt(NEW_TABLE_FLAG);
	activeFileManager->writeInt(corArray.size());
	for (corItr = corArray.begin(); corItr != corArray.end(); corItr++) {
		cor = corItr->getValue();
		len = cor.getName().length();

		activeFileManager->writeInt(NEW_ENTRY_FLAG);
		corCode = corItr->getKey();
		if (corCode.length() == 8) corCode += "#";
		activeFileManager->writeString(corCode);
		activeFileManager->writeInt(len);
		activeFileManager->writeString(cor.getName());
		activeFileManager->writeInt(len);
		activeFileManager->writeInt(cor.getCredit());
	}

	//CourseSelection Table
	activeFileManager->writeInt(NEW_TABLE_FLAG);
	activeFileManager->writeInt(records->size());
	for (recItr = records->begin(); recItr != records->end(); recItr++) {
		rec = *recItr;

		activeFileManager->writeInt(NEW_ENTRY_FLAG);
		activeFileManager->writeString(std::to_string(rec.getStuID()));
		corCode = rec.getCorID();
		if (corCode.length() == 8) corCode += "#";
		activeFileManager->writeString(corCode);
		temp = rec.getExamMark();
		if (temp == -1)
			activeFileManager->writeInt(NO_MARK_FLAG);
		else
			activeFileManager->writeInt(temp);
	}

	delete activeFileManager;
	std::cout << "Database Saved" << std::endl;
	std::cout << std::endl;
}

void Register::loadDatabase() {
	std::string filename = "";
	std::cout << "Enter file name: ";
	std::getline(std::cin, filename);
	activeFileManager = new FileManager(filename);
	activeFileManager->openInFile();
	if (!(activeFileManager->isFileOpen())) {
		std::cout << "Error: cannot open file" << std::endl;
		std::cout << std::endl;
		return;
	}

	int entries = 0;
	int i;
	HashTable<int, Student> studentBuffer(STUD_BUCKET_NO);
	HashTable<std::string, Course> courseBuffer(COR_BUCKET_NO);
	recordsBuffer = new std::list<Record>;
	recordIterator recItr;

	int stuID, intBuffer;
	std::string corID, strBuffer;
	Student stud;
	Course cor;
	Record rec;

	try {
		//Student Table
		activeFileManager->checkValue(NEW_TABLE_FLAG);
		entries = activeFileManager->readNum();
		for (i=0; i < entries; i++) {
			activeFileManager->checkValue(NEW_ENTRY_FLAG);
			try {
				stuID = std::stoi(activeFileManager->readString(8));
			} catch (...) {
				throw "Load Error!";
			}

			intBuffer = activeFileManager->readNum();
			strBuffer = activeFileManager->readString(intBuffer);
			activeFileManager->checkValue(intBuffer);
			stud.setName(strBuffer);

			intBuffer = activeFileManager->readNum(8);
			if (intBuffer > 4) {
				intBuffer -= 4;
				stud.setGender("F");
			} else {
				stud.setGender("M");
			}
			stud.setYear(intBuffer);

			studentBuffer.putElem(stuID, stud);
		}

		//Course Table
		activeFileManager->checkValue(NEW_TABLE_FLAG);
		entries = activeFileManager->readNum();
		for (i=0; i < entries; i++) {
			activeFileManager->checkValue(NEW_ENTRY_FLAG);
			corID = activeFileManager->readString(9);
			if (corID[8] == '#') corID.pop_back();

			intBuffer = activeFileManager->readNum();
			strBuffer = activeFileManager->readString(intBuffer);
			activeFileManager->checkValue(intBuffer);
			cor.setName(strBuffer);

			intBuffer = activeFileManager->readNum(5);
			cor.setCredit(intBuffer);

			courseBuffer.putElem(corID, cor);
		}

		//CourseSelection Table
		activeFileManager->checkValue(NEW_TABLE_FLAG);
		entries = activeFileManager->readNum();
		for (i=0; i < entries; i++) {
			activeFileManager->checkValue(NEW_ENTRY_FLAG);

			try {
				stuID = std::stoi(activeFileManager->readString(8));
			} catch (...) {
				throw "Load Error!";
			}
			if (!studentBuffer.checkElem(stuID)) throw "Load Error!";
			rec.setStuID(stuID);

			corID = activeFileManager->readString(9);
			if (corID[8] == '#') corID.pop_back();
			if (!courseBuffer.checkElem(corID)) throw "Load Error!";
			rec.setCorID(corID);

			intBuffer = activeFileManager->readNum();
			if (intBuffer == NO_MARK_FLAG)
				rec.setExamMarkNA();
			else if (intBuffer >= 0 && intBuffer <= 100)
				rec.setExamMark(intBuffer);
			else
				throw "Load Error!";

			recItr = recordsBuffer->begin();
			while (recItr != recordsBuffer->end() && rec >= *recItr) {
				if (rec == *recItr) throw "Load Error!";
				recItr++;
			}
			recItr = recordsBuffer->insert(recItr, rec);
		}

	} catch (const char* msg) {
		std::cout << msg << std::endl;
		std::cout << std::endl;
		return;
	}

	student = studentBuffer;
	course = courseBuffer;
	records = recordsBuffer;

	studentFinder.clearTable();
	courseFinder.clearTable();
	for (recItr = records->begin(); recItr != records->end(); recItr++) {
		studentFinder.putElem(recItr->getStuID(), recItr);
		courseFinder.putElem(recItr->getCorID(), recItr);
	}

	delete activeFileManager;
	recordsBuffer = 0;
	std::cout << "Database Loaded" << std::endl;
	std::cout << std::endl;
}

/*--Parsing functions*/

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

void Register::parseExamMark(recordIterator& r) {
	std::string input;
	bool state = false;
	do {
		std::getline(std::cin, input);
		state = r->setExamMark(input);
		if (!state)
			std::cout << "Invalid input, enter again [exam mark]: ";
	} while (!state);
}

/*
 * Validate the keys
 */

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
