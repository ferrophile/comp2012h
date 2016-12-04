#include "registerEntities.h"

/*
 *Student class member functions
 */

Student::Student()
: _name(""), _year(0), _gender("") {}

Student::Student(std::string name, int year, std::string gender) {
	if (!setName(name) || !setYear(year) || !setGender(gender)) {
		Student();
	}
}

Student::~Student() {}

bool Student::setName(std::string name) {
	int len = name.length();
	if (len < 1 || len > STUD_NAME_LEN_LIMIT)
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

bool Student::setYear(std::string year) {
	int temp = 0;
	try {
		temp = std::stoi(year);
	} catch (...) {
		return false;
	}
	setYear(temp);
}

bool Student::setGender(std::string gender) {
	if (gender != "M" && gender != "F")
		return false;
	_gender = gender;
	return true;
}

std::string Student::getName() const {
	return _name;
}

int Student::getYear() const {
	return _year;
}

std::string Student::getGender() const {
	return _gender;
}

Student& Student::operator=(const Student& s) {
	_name = s.getName();
	_year = s.getYear();
	_gender = s.getGender();
}

std::ostream& operator<<(std::ostream& os, const Student& stud) {
	os << stud._name << ", ";
	os << stud._year << ", ";
	os << stud._gender;
	return os;
}

/*
 *Course class member functions
 */

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

/*
 *Record class member functions
 */

Record::Record()
: _stuID(0), _corID(""), _examMark(-1) {}

Record::Record(int stuID, std::string corID) : _examMark(-1) {
	setStuID(stuID);
	setCorID(corID);
}

Record::~Record() {}

void Record::setStuID(int stuID) {
	_stuID = stuID;
}

void Record::setCorID(std::string corID) {
	_corID = corID;
}

bool Record::setExamMark(int examMark) {
	if (examMark < 0 || examMark > 100)
		return false;
	_examMark = examMark;
	return true;
}

int Record::getStuID() const {
	return _stuID;
}

std::string Record::getCorID() const {
	return _corID;
}

int Record::getExamMark() const {
	return _examMark;
}

bool Record::operator==(const Record& r) {
	return (_stuID == r.getStuID() && _corID == r.getCorID());
}

bool Record::operator!=(const Record& r) {
	return !(*this == r);
}

bool Record::operator<(const Record& r) {
	if (_stuID == r.getStuID())
		return (_corID < r.getCorID());
	return (_stuID < r.getStuID());
}

bool Record::operator<=(const Record& r) {
	return (*this < r || *this == r);
}

bool Record::operator>(const Record& r) {
	if (_stuID == r.getStuID())
		return (_corID > r.getCorID());
	return (_stuID > r.getStuID());
}

bool Record::operator>=(const Record& r) {
	return (*this > r || *this == r);
}
