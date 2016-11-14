/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.cpp
 */

#include "point.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

//Default constructor
Point::Point() : Vector2D() {}

//Initialization constructor
Point::Point(int newX, int newY) : Vector2D(newX, newY) {}

//Destructor
Point::~Point() {}

/*-- Member functions --*/

//Print out coordinates for debugging use
void Point::printPt() {
	cout << this->getX() << ' ' << this->getY() << endl;
}

//Return stream with formatted output
string Point::printFormat() {
	ostringstream os;
	os << "(" << this->getX() << ", " << this->getY() << ")";
	return os.str();
}

//Get angle, in radians, with reference to another point
double Point::getRadian(const Point& pt) const {
	if (this->getX() == pt.getX()) return 2.0; //Return 2.0 to represent undefined value
	return atan((double)(pt.getY() - this->getY())/(double)(pt.getX() - this->getX()));
}
