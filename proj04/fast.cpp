/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * fast.cpp
 */

#include "fast.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

Fast::Fast() : Algorithm() {}

Fast::Fast(const vector<Point> list) : Algorithm(list) {}

Fast::~Fast() {}

vector< vector<Point> > Fast::getCollinearPoints() {
	int size = points.size();
	vector<Pair> angles;
	vector<Point> line;
	vector< vector<Point> > rawLines, lines;

	Pair tmpPair;
	int id;

	for (int i=0; i < size; i++) {
		angles.clear();
		for (int j=0; j < size; j++) {
			if (j==i) continue;

			tmpPair.angle = points[i].getRadian(points[j]);
			tmpPair.id = j;
			angles.push_back(tmpPair);
		}
		sort(angles.begin(), angles.end());

		line.clear();
		vector<Pair>::iterator itr;
		for (itr = angles.begin(); itr < angles.end(); itr++) {
			if (itr->angle == (itr+1)->angle) {
				line.push_back(points[itr->id]);
			} else {
				if (line.size() >= 2) {
					line.push_back(points[itr->id]);
					line.push_back(points[i]);
					rawLines.push_back(line);
				}
				line.clear();
			}
		}
	}

	vector< vector<Point> >::iterator itr;
	for (itr = rawLines.begin(); itr < rawLines.end(); itr++) {
		sort(itr->begin(), itr->end());
	}
	sort(rawLines.begin(), rawLines.end());
	itr = rawLines.begin();
	while (itr < rawLines.end()) {
		printLine(*itr);
		lines.push_back(*itr);
		itr += itr->size();
	}

	return lines;
}
