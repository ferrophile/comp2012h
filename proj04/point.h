/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * point.h
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(int newX, int newY);
	~Point();

	int getX();
	int getY();

	void setX(int newX);
	void setY(int newY);

private:
	int x;
	int y;
};

#endif // POINT_H
