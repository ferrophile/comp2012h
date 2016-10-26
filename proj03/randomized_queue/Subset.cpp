/*
 * COMP2012H Project 3
 * Hong Wing PANG 20315504
 * Subset.cpp
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "randomized_queue.h"

using namespace std;

int main(int argc, char ** argv) {
	srand(time(0));

	int size = atoi(argv[1]);
	string str = "";
	char buf;
	RandomizedQueue<string> q;

	while ((buf = getchar()) != '\n') {
		if (buf == ' ') {
			q.enqueue(str);
			str = "";
		} else {
			str += buf;
		}
	}
	q.enqueue(str);

	for (int i=0; i<size; i++) {
		cout << q.dequeue() << endl;
	}

	return 0;
}
