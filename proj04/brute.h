/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * brute.h
 */

#ifndef BRUTE_H
#define BRUTE_H

#include "algorithm.h"
#include "point.h"
#include <vector>

using namespace std;

class Brute : public Algorithm {
public:
	Brute();
	Brute(const vector<Point> list);
	~Brute();

	virtual void getCollinearPoints();

private:
	bool checkCollinear(const Point& pt1, const Point& pt2, const Point& pt3);
};

#endif //BRUTE_H
