#ifndef _STUDENT_H
#define _STUDENT_H

#define NAME_LEN_LIMIT 32

#include <string>

class Student {
private:
	std::string _name;
	int _year;
	char _gender;
public:
	Student();
	Student(std::string, int, char);
	~Student();

	bool setName(std::string);
	bool setYear(int);
	bool setGender(char);
};

#endif
