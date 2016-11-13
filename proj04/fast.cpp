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

Fast::Fast() : isStandalone(true) {
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

Fast::Fast(const vector<Point> list) : isStandalone(false), points(list) {}

Fast::~Fast() {}

void Fast::getCollinearPoints() {
	int size = points.size();
	vector<double> angles, line;
	vector< vector<double> > lines;

	for (int i=0; i < size; i++) {
		angles.clear();
		for (int j=0; j < size; j++) {
			if (j==i) continue;
			angles.push_back(points[i].getRadian(points[j]));
		}
		sort(angles.begin(), angles.end());

		line.clear();
		line.push_back(angles[0]);
		for (int j=1; j < size; j++) {
			if (angles[j] != angles[j-1]) {
				if (line.size() >= 3) lines.push_back(line);
				line.clear();
			}
			line.push_back(angles[j]);
		}
	}

	cout << lines.size() << endl;
	for (int i=0; i < lines.size(); i++) {
		for (int j=0; j < lines[i].size(); j++)
			cout << lines[i][j] << ' ';
		cout << endl;
	}
}

bool Fast::printLine(vector<Point> line) {
	int size = line.size();
	cout << size << ": ";
	for (int i=0; i < size-1; i++) {
		cout << line[i].printFormat() << " -> ";
	}
	cout << line[size-1].printFormat() << endl;
}

int main(int argc, char ** argv) {
	Fast fastObj;
	fastObj.getCollinearPoints();
	return 0;
}
