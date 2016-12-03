#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>
#include "hashTable.h"
#include "student.h"
#include "menu.h"

class Register {
private:
	//Hash tables
	HashTable<int, Student> student;
	HashTable<std::string, std::string> course;

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
	//void studentDeleteEntry();
	//void studentQueryEntry();

	bool validateStuID(std::string input, int* res);

	void debug();
	void foobar();
};

#endif
