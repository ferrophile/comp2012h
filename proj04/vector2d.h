/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * vector2d.h
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>

using namespace std;

class Vector2D {
public:
	Vector2D();
	Vector2D(int newX, int newY);
	~Vector2D();

	int getX() const;
	int getY() const;

	void setX(int newX);
	void setY(int newY);

	bool operator==(const Vector2D& pt) const;
	bool operator!=(const Vector2D& pt) const;
	bool operator<(const Vector2D& pt) const;
	bool operator>(const Vector2D& pt) const;

protected:
	int x;
	int y;
};

#endif // VECTOR2D_H
