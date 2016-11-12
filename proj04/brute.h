/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * brute.h
 */

#ifndef BRUTE_H
#define BRUTE_H

#include "point.h"
#include <vector>

using namespace std;

class Brute {
public:
	Brute();
	Brute(const vector<Point> list);
	~Brute();

	void getCollinearPoints();

private:
	bool isStandalone;
	vector<Point> points;

	bool checkCollinear(const Point& pt1, const Point& pt2, const Point& pt3);
	bool printLine(vector<Point> line);
};

#endif //BRUTE_H
