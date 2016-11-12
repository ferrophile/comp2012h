/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.h
 */

#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;

class Point {
public:
	Point();
	Point(int newX, int newY);
	~Point();

	int getX() const;
	int getY() const;

	void setX(int newX);
	void setY(int newY);

	void printPt();
	string printFormat();

	bool operator==(const Point& pt) const;
	bool operator!=(const Point& pt) const;
	bool operator<(const Point& pt) const;
	bool operator>(const Point& pt) const;

	int operator^(const Point& pt) const;

private:
	int x;
	int y;
};

#endif // POINT_H
