/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * brute.cpp
 */

#include "brute.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Brute::Brute() : isStandalone(true) {
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

Brute::Brute(const vector<Point> list) : isStandalone(false), points(list) {}

Brute::~Brute() {}

void Brute::getCollinearPoints() {
	int size = points.size();
	vector<Point> line;
	for (int x1=0; x1 < size; x1++) {
		for (int x2=x1+1; x2 < size; x2++) {
			for (int x3=x2+1; x3 < size; x3++) {
				for (int x4=x3+1; x4 < size; x4++) {
					bool check = checkCollinear(points[x1], points[x2], points[x3]);
					check = check && checkCollinear(points[x1], points[x2], points[x4]);
					if (check) {
						line.clear();
						line.push_back(points[x1]);
						line.push_back(points[x2]);
						line.push_back(points[x3]);
						line.push_back(points[x4]);
						printLine(line);
					}
				}
			}
		}
	}
}

bool Brute::checkCollinear(const Point& pt1, const Point& pt2, const Point& pt3) {
	int det = pt1.getX()*(pt2.getY() - pt3.getY());
	det += pt2.getX()*(pt3.getY() - pt1.getY());
	det += pt3.getX()*(pt1.getY() - pt2.getY());
	return (det == 0);
}

bool Brute::printLine(vector<Point> line) {
	int size = line.size();
	cout << size << ": ";
	for (int i=0; i < size-1; i++) {
		cout << line[i].printFormat() << " -> ";
	}
	cout << line[size-1].printFormat() << endl;
}

int main(int argc, char ** argv) {
	Brute bruteObj;
	bruteObj.getCollinearPoints();
	return 0;
}
