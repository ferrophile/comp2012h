#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>
#include "hashTable.h"
#include "student.h"
#include "course.h"
#include "menu.h"

class Register {
private:
	//Hash tables
	HashTable<int, Student> student;
	HashTable<std::string, Course> course;

	//Menus
	Menu rootMenu;
	Menu studentMenu;
	Menu courseMenu;
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

	//Parsers
	void parseStuID(int* stuID);
	void parseStuName(Student& s);
	void parseStuYear(Student& s);
	void parseStuGender(Student& s);

	void parseCourseID(std::string* courseID);
	void parseCourseName(Course& c);
	void parseCourseCredit(Course& c);

	//Validators
	bool validateStuID(std::string input, int* res);
	bool validateCourseID(std::string input, std::string* res);

	void debug();
	void foobar();
};

#endif
