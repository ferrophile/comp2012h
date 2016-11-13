/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.h
 */

#ifndef POINT_H
#define POINT_H

#include "vector2d.h"
#include <string>

using namespace std;

class Point : public Vector2D {
public:
	Point();
	Point(int newX, int newY);
	~Point();

	void printPt();
	string printFormat();

	double getRadian(const Point& pt) const;
};

#endif // POINT_H
