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

//Default constructor
Brute::Brute() : Algorithm() {}

//Type conversion constructor
Brute::Brute(const vector<Point> list) : Algorithm(list) {}

//Destructor
Brute::~Brute() {}

/*-- Member functions --*/

//Get collinear points using brute force
//Examining 4 points every time
vector< vector<Point> > Brute::getCollinearPoints() {
	int size = points.size();
	int cross;
	vector<Point> line;
	vector< vector<Point> > lines;

	for (int x1=0; x1 < size; x1++) {
		for (int x2=x1+1; x2 < size; x2++) {
			for (int x3=x2+1; x3 < size; x3++) {
				for (int x4=x3+1; x4 < size; x4++) {
					//Checks Points are collinear by seeing if cross product is zero
					cross = Vector2D::crossProduct((points[x2] - points[x1]), (points[x3] - points[x1]));
					cross |= Vector2D::crossProduct((points[x2] - points[x1]), (points[x4] - points[x1]));

					if (cross == 0) {
						line.clear();
						line.push_back(points[x1]);
						line.push_back(points[x2]);
						line.push_back(points[x3]);
						line.push_back(points[x4]);
						lines.push_back(line);
					}
				}
			}
		}
	}

	//Sort each line and print out
	vector< vector<Point> >::iterator itr;
	for (itr = lines.begin(); itr < lines.end(); itr++) {
		sort(itr->begin(), itr->end());
		printLine(*itr);
	}

	//Return list of lines to PointPlotter (if needed)
	return lines;
}
