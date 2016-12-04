#ifndef _COURSE_H
#define _COURSE_H

#define COR_NAME_LEN_LIMIT 50

#include <string>
#include <iostream>

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

#endif
