/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * fast.h
 */

#ifndef FAST_H
#define FAST_H

#include "algorithm.h"
#include "point.h"
#include <vector>

using namespace std;

class Fast : public Algorithm {
public:
	Fast();
	Fast(const vector<Point> list);
	~Fast();

	virtual vector< vector<Point> > getCollinearPoints();

	struct Pair {
		double angle;
		int id;

		bool operator<(const Pair &p) { return (angle < p.angle); }
		bool operator>(const Pair &p) { return (angle > p.angle); }
	};
};

#endif //FAST_H
