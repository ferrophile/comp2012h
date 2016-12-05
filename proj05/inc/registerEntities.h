/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * registerEntities.h
 */

#ifndef _REGISTERENTITIES_H
#define _REGISTERENTITIES_H

#define STUD_NAME_LEN_LIMIT 32
#define COR_NAME_LEN_LIMIT 50

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

	std::string getName() const;
	int getYear() const;
	std::string getGender() const;

	Student& operator=(const Student&);
	friend std::ostream& operator<<(std::ostream& os, const Student& stud);
};

class Course {
private:
	std::string _name;
	int _credit;
public:
	Course();
	Course(std::string, int);
	~Course();

	bool setName(std::string);
	bool setCredit(int);
	bool setCredit(std::string);

	std::string getName() const;
	int getCredit() const;

	Course& operator=(const Course&);
	friend std::ostream& operator<<(std::ostream& os, const Course& cor);
};

class Record {
private:
	int _stuID;
	std::string _corID;
	int _examMark;
public:
	Record();
	Record(int, std::string);
	~Record();

	void setStuID(int);
	void setCorID(std::string);
	bool setExamMark(int);
	bool setExamMark(std::string);
	void setExamMarkNA();

	int getStuID() const;
	std::string getCorID() const;
	int getExamMark() const;

	std::string showExamMark() const;

	bool operator==(const Record&);
	bool operator!=(const Record&);
	bool operator<(const Record&);
	bool operator<=(const Record&);
	bool operator>(const Record&);
	bool operator>=(const Record&);
};

#endif
