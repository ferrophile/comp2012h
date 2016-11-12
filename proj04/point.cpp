/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.cpp
 */

#include "point.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Point::Point() {}

Point::Point(int newX, int newY) : x(newX), y(newY) {}

Point::~Point() {}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setX(int newX) {
	x = newX;
}

void Point::setY(int newY) {
	y = newY;
}

void Point::printPt() {
	cout << x << ' ' << y << endl;
}

string Point::printFormat() {
	ostringstream os;
	os << "(" << x << ", " << y << ")";
	return os.str();
}

int Point::operator^(const Point& pt) const {
	return (x*pt.getY() - y*pt.getX());
}

