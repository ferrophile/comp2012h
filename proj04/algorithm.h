/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * algorithm.h
 */

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "point.h"
#include <vector>

using namespace std;

class Algorithm {
public:
	Algorithm();
	Algorithm(const vector<Point> list);
	~Algorithm();

	virtual void getCollinearPoints() = 0;

protected:
	bool isStandalone;
	vector<Point> points;

	bool printLine(vector<Point> line);
};

#endif //FAST_H
