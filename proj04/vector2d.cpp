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

Vector2D Vector2D::operator+(const Vector2D& v) const {
	return Vector2D(x+v.getX(), y+v.getY());
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
	return Vector2D(x-v.getX(), y-v.getY());
}

int Vector2D::crossProduct(const Vector2D& v1, const Vector2D& v2) {
	return (v1.getX()*v2.getY() - v1.getY()*v2.getX());
}

bool Vector2D::operator==(const Vector2D& v) const {
	return x == v.getX() && y == v.getY();
}

bool Vector2D::operator!=(const Vector2D& v) const {
	return !(*this == v);
}

bool Vector2D::operator<(const Vector2D& v) const {
	if (x == v.getX())
		return (y < v.getY());
	else
		return (x < v.getX());
}

bool Vector2D::operator>(const Vector2D& v) const {
	if (x == v.getX())
		return (y > v.getY());
	else
		return (x > v.getX());
}
