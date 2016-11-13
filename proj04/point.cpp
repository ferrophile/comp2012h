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

Point::Point() : Vector2D() {}

Point::Point(int newX, int newY) : Vector2D(newX, newY) {}

Point::~Point() {}

void Point::printPt() {
	cout << x << ' ' << y << endl;
}

string Point::printFormat() {
	ostringstream os;
	os << "(" << x << ", " << y << ")";
	return os.str();
}

double Point::getRadian(const Point& pt) const {
	if (x == pt.getX()) return 2.0;
	return atan((double)(pt.getY() - y)/(double)(pt.getX() - x));
}
