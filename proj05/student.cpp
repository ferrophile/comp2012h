#include "student.h"

Student::Student()
: _name(""), _year(0), _gender(' ') {}

Student::Student(std::string name, int year, char gender) {
	if (!setName(name) || !setYear(year) || !setGender(gender)) {
		Student();
	}
}

Student::~Student() {}

bool Student::setName(std::string name) {
	int len = name.length();
	if (len < 1 || len > NAME_LEN_LIMIT)
		return false;
	_name = name;
	return true;
}

bool Student::setYear(int year) {
	if (year < 1 || year > 4)
		return false;
	_year = year;
	return true;
}

bool Student::setGender(char gender) {
	if (gender != 'M' && gender != 'F')
		return false;
	_gender = gender;
	return true;
}

std::string Student::getName() {
	return _name;
}

int Student::getYear() {
	return _year;
}

char Student::getGender() {
	return _gender;
}

std::ostream& operator<< (std::ostream& os, const Student& stud) {
	os << stud._name << ", ";
	os << stud._year << ", ";
	os << stud._gender;
	return os;
}
