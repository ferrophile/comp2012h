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
};

#endif //BRUTE_H
