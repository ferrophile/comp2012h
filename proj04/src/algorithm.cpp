/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * algorithm.cpp
 */

#include "algorithm.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

//Default base class constructor
//Used when standalone client is run
Algorithm::Algorithm() : isStandalone(true) {
	vector<Point> tmpList;
	points = tmpList;

	//Build list of Points by reading file from cin stream
	string str;
	int tmpX, tmpY;
	getline(cin, str);
	int n = atoi(str.c_str());
	for (int i=0; i<n; i++) {
		getline(cin, str, ' ');
		tmpX = atoi(str.c_str());
		getline(cin, str, '\n');
		tmpY = atoi(str.c_str());
		points.push_back(Point(tmpX, tmpY));
	}
}

//Type conversion base class constructor
//Used when called from PointPlotter
Algorithm::Algorithm(const vector<Point> list) : isStandalone(false), points(list) {}

//Destructor
Algorithm::~Algorithm() {}

/*-- Member functions --*/

//Print a list of Points in specified format
void Algorithm::printLine(vector<Point> line) {
	int size = line.size();
	cout << size << ": ";
	for (int i=0; i < size-1; i++) {
		cout << line[i].printFormat() << " -> ";
	}
	cout << line[size-1].printFormat() << endl;
}
