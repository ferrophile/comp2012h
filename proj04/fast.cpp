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
	vector<Pair> angles, subset;
	vector<Point> line;
	vector< vector<Point> > lines;

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

		subset.clear();
		subset.push_back(angles[0]);
		for (int j=1; j < size; j++) {
			if (angles[j].angle != angles[j-1].angle) {
				if (subset.size() >= 3) {
					line.clear();
					for (int k=0; k < subset.size(); k++) {
						id = subset[k].id;
						line.push_back(points[id]);
					}
					line.push_back(points[i]);
					sort(line.begin(), line.end());
					lines.push_back(line);
				}
				subset.clear();
			}
			subset.push_back(angles[j]);
		}
	}

	cout << lines.size() << endl;
	for (int i=0; i < lines.size(); i++)
		printLine(lines[i]);

	return lines;
}
