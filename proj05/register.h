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
	static void studentAddEntry();
	//static void studentModifyEntry();
	//static void studentDeleteEntry();
	//static void studentQueryEntry();

	static bool validateStuID(std::string input, int* res);

	static void debug();
	static void foobar();
};

#endif
