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

Algorithm::Algorithm() : isStandalone(true) {
	vector<Point> tmpList;
	points = tmpList;

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

Algorithm::Algorithm(const vector<Point> list) : isStandalone(false), points(list) {}

Algorithm::~Algorithm() {}

void Algorithm::printLine(vector<Point> line) {
	int size = line.size();
	cout << size << ": ";
	for (int i=0; i < size-1; i++) {
		cout << line[i].printFormat() << " -> ";
	}
	cout << line[size-1].printFormat() << endl;
}
