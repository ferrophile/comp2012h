#ifndef _STUDENT_H
#define _STUDENT_H

#define NAME_LEN_LIMIT 32

#include <string>
#include <iostream>

class Student {
private:
	std::string _name;
	int _year;
	std::string _gender;
public:
	Student();
	Student(std::string, int, std::string);
	~Student();

	bool setName(std::string);
	bool setYear(int);
	bool setYear(std::string);
	bool setGender(std::string);

	std::string getName();
	int getYear();
	std::string getGender();

	friend std::ostream& operator<< (std::ostream& os, const Student& stud);
};

#endif
