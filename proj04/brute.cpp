/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * brute.cpp
 */

#include "brute.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

Brute::Brute() : Algorithm() {}

Brute::Brute(const vector<Point> list) : Algorithm(list) {}

Brute::~Brute() {}

vector< vector<Point> > Brute::getCollinearPoints() {
	int size = points.size();
	int cross;
	//Point = p1, p2;
	vector<Point> line;
	vector< vector<Point> > lines;

	for (int x1=0; x1 < size; x1++) {
		for (int x2=x1+1; x2 < size; x2++) {
			for (int x3=x2+1; x3 < size; x3++) {
				for (int x4=x3+1; x4 < size; x4++) {
					cross = Vector2D::crossProduct((points[x2] - points[x1]), (points[x3] - points[x1]));
					cross |= Vector2D::crossProduct((points[x2] - points[x1]), (points[x4] - points[x1]));

					if (cross == 0) {
						line.clear();
						line.push_back(points[x1]);
						line.push_back(points[x2]);
						line.push_back(points[x3]);
						line.push_back(points[x4]);
						sort(line.begin(), line.end());
						printLine(line);
						lines.push_back(line);
					}
				}
			}
		}
	}

	return lines;
}
