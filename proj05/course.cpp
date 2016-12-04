#include "course.h"

Course::Course()
: _name(""), _credit(0) {}

Course::Course(std::string name, int credit) {
	if (!setName(name) || !setCredit(credit)) {
		Course();
	}
}

Course::~Course() {}

bool Course::setName(std::string name) {

	int len = name.length();
	if (len < 1 || len > COR_NAME_LEN_LIMIT)
		return false;
	_name = name;
	return true;
}

bool Course::setCredit(int credit) {
	if (credit < 0 || credit > 5)
		return false;
	_credit = credit;
	return true;
}

bool Course::setCredit(std::string credit) {
	int temp = 0;
	try {
		temp = std::stoi(credit);
	} catch (...) {
		return false;
	}
	setCredit(temp);
}

std::string Course::getName() const {
	return _name;
}

int Course::getCredit() const {
	return _credit;
}

Course& Course::operator=(const Course& c) {
	_name = c.getName();
	_credit = c.getCredit();
}

std::ostream& operator<<(std::ostream& os, const Course& cor) {
	os << cor._name << ", ";
	os << cor._credit;
}
