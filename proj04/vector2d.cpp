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

Vector2D::Vector2D() {}

Vector2D::Vector2D(int newX, int newY) : x(newX), y(newY) {}

Vector2D::~Vector2D() {}

int Vector2D::getX() const {
	return x;
}

int Vector2D::getY() const {
	return y;
}

void Vector2D::setX(int newX) {
	x = newX;
}

void Vector2D::setY(int newY) {
	y = newY;
}

bool Vector2D::operator==(const Vector2D& pt) const {
	return x == pt.getX() && y == pt.getY();
}

bool Vector2D::operator!=(const Vector2D& pt) const {
	return !(*this == pt);
}

bool Vector2D::operator<(const Vector2D& pt) const {
	if (x == pt.getX())
		return (y < pt.getY());
	else
		return (x < pt.getX());
}

bool Vector2D::operator>(const Vector2D& pt) const {
	if (x == pt.getX())
		return (y > pt.getY());
	else
		return (x > pt.getX());
}
