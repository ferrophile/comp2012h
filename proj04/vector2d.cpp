/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * vector2d.cpp
 */

#include "point.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

//Default constructor
Vector2D::Vector2D() : x(0), y(0) {}

//Initialization constructor
Vector2D::Vector2D(int newX, int newY) : x(newX), y(newY) {}

//Destructor
Vector2D::~Vector2D() {}

//Getter functions
int Vector2D::getX() const {
	return x;
}

int Vector2D::getY() const {
	return y;
}

//Setter functions
void Vector2D::setX(int newX) {
	x = newX;
}

void Vector2D::setY(int newY) {
	y = newY;
}

/*-- Overloaded operators --*/

//Vector addition
Vector2D Vector2D::operator+(const Vector2D& v) const {
	return Vector2D(x+v.getX(), y+v.getY());
}

//Vector subtraction
Vector2D Vector2D::operator-(const Vector2D& v) const {
	return Vector2D(x-v.getX(), y-v.getY());
}

//Compare if two vectors are equal
bool Vector2D::operator==(const Vector2D& v) const {
	return x == v.getX() && y == v.getY();
}

//Compare if two vectors are not equal
bool Vector2D::operator!=(const Vector2D& v) const {
	return !(*this == v);
}

//Find smaller vector, ranked by x followed by y
bool Vector2D::operator<(const Vector2D& v) const {
	if (x == v.getX())
		return (y < v.getY());
	else
		return (x < v.getX());
}

//Find larger vector, ranked by x followed by y
bool Vector2D::operator>(const Vector2D& v) const {
	if (x == v.getX())
		return (y > v.getY());
	else
		return (x > v.getX());
}

/*-- Utility functions --*/

//Returns (the magnitude) of the cross product of two vectors
int Vector2D::crossProduct(const Vector2D& v1, const Vector2D& v2) {
	return (v1.getX()*v2.getY() - v1.getY()*v2.getX());
}
