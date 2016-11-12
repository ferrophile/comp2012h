/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.cpp
 */

#include "point.h"

Point::Point() {}

Point::Point(int newX, int newY) : x(newX), y(newY) {}

Point::~Point() {}

int Point::getX() {
	return x;
}

int Point::getY() {
	return x;
}

void Point::setX(int newX) {
	x = newX;
}

void Point::setY(int newY) {
	y = newY;
}
