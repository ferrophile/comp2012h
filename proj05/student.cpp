#include "student.h"

Student::Student()
: _name(""), _year(0), _gender(' ') {}

Student::Student(std::string name, int year, char gender) {
	//
}

Student::~Student() {}

bool Student::setName(std::string name) {
	int len = name.length();
	if (len < 1 || len > NAME_LEN_LIMIT)
		return false;
	_name = name;
}

bool Student::setYear(int year) {
	if (year < 1 || year > 4)
		return false;
	_year = year;
}

bool Student::setGender(char gender) {
	if (gender != 'M' && gender != 'F')
		return false;
	_gender = gender;
}
