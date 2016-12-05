#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>
#include "hashTable.h"
#include "registerEntities.h"
#include "reportGenerator.h"
#include "fileManager.h"
#include "menu.h"

#define STUD_BUCKET_NO 29
#define COR_BUCKET_NO 17

#define NEW_ENTRY_FLAG 0x80
#define NEW_TABLE_FLAG 0x8A

typedef std::list<Record>::iterator recordIterator;

class Register {
private:
	//Hash tables
	HashTable<int, Student> student;
	HashTable<std::string, Course> course;
	HashTable<int, recordIterator> studentFinder;
	HashTable<std::string, recordIterator> courseFinder;

	//List
	std::list<Record> records;

	//Utilities
	ReportGenerator* activeGenerator;
	FileManager* activeFileManager;

	//Menus
	Menu rootMenu;
	Menu studentMenu;
	Menu courseMenu;
	Menu regCourseMenu;
	Menu reportMenu;
	Menu fileMenu;
	
public:
	Register();
	~Register();

	//Actions
	void studentInsertEntry();
	void studentModifyEntry();
	void studentDeleteEntry();
	void studentQueryEntry();

	void courseInsertEntry();
	void courseModifyEntry();
	void courseDeleteEntry();
	void courseQueryEntry();

	void recordAddCourse();
	void recordDropCourse();
	void recordModifyMark();
	void recordQueryEntry();

	void genStudentReport();
	void genCourseReport();
	void genStudentCourseReport();
	void genCourseStudentReport();

	void saveDatabase();
	void loadDatabase();

	//Parsers
	void parseStuID(int* stuID);
	void parseStuName(Student& s);
	void parseStuYear(Student& s);
	void parseStuGender(Student& s);

	void parseCourseID(std::string* courseID);
	void parseCourseName(Course& c);
	void parseCourseCredit(Course& c);

	void parseExamMark(recordIterator& r);

	//Validators
	bool validateStuID(std::string input, int* res);
	bool validateCourseID(std::string input, std::string* res);

	void debug();
	void foobar();
};

#endif
