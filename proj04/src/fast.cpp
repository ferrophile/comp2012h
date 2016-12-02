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

//Default constructor
Fast::Fast() : Algorithm() {}

//Type conversion constructor
Fast::Fast(const vector<Point> list) : Algorithm(list) {}

//Destructor
Fast::~Fast() {}

//Get collinear points using faster algorithm
vector< vector<Point> > Fast::getCollinearPoints() {
	int size = points.size();
	vector<Pair> angles;
	vector<Point> line;
	vector< vector<Point> > rawLines, lines;

	Pair tmpPair;

	for (int i=0; i < size; i++) {
		angles.clear();
		for (int j=0; j < size; j++) {
			if (j==i) continue;

			//Get angle for comparing, and id of Point as handle to access it later
			//Angle in radians; get same value for opposite (180 deg apart) directions
			tmpPair.angle = points[i].getRadian(points[j]);
			tmpPair.id = j;
			angles.push_back(tmpPair);
		}
		//Sort the pairs by angles
		//Angles corresponding to collinear points will be put together
		sort(angles.begin(), angles.end());

		//Find adjacent angles with same value
		line.clear();
		vector<Pair>::iterator itr;
		for (itr = angles.begin(); itr < angles.end(); itr++) {
			if (itr->angle == (itr+1)->angle) {
				//Same value; continuing building
				line.push_back(points[itr->id]);
			} else {
				//Diff value, examine if got 3 angles in a row now
				if (line.size() >= 2) {
					line.push_back(points[itr->id]); //Push current Point
					line.push_back(points[i]); //Push origin Point
					rawLines.push_back(line); //Push line to list of lines
				}
				line.clear();
			}
		}
	}

	//Sort Points in each line in ascending order
	vector< vector<Point> >::iterator itr;
	for (itr = rawLines.begin(); itr < rawLines.end(); itr++) {
		sort(itr->begin(), itr->end());
	}
	sort(rawLines.begin(), rawLines.end());

	//Sort the list of lines in ascending order to group duplicates together
	itr = rawLines.begin();
	while (itr < rawLines.end()) {
		printLine(*itr); //Print out each unique line
		lines.push_back(*itr); //Push for a final list of unique lines
		itr += itr->size(); //Skip duplicates
	}

	//Return list of lines to PointPlotter (if needed)
	return lines;
}
