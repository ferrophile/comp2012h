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
	vector<Point> list;
	points = list;

	string str;
	getline(cin, str);
	int n = atoi(str.c_str());
	for (int i=0; i<n; i++) {
		getline(cin, str);
		cout << str << endl;
		//points.push_back(str)
	}
}

Brute::Brute(const vector<Point> list) : isStandalone(false), points(list) {}

Brute::~Brute() {

}

void Brute::getCollinearPoints() {

}

int main(int argc, char ** argv) {
	Brute bruteObj;

	return 0;
}
