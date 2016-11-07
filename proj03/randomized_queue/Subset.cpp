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

	//If no arguments passed, print error
	if (argc < 2) {
   		fprintf(stderr,"usage %s charno\n", argv[0]);
		exit(0);
	}

	int size = atoi(argv[1]); //Get subset size
	string str = "";
	char buf;
	RandomizedQueue<string> q;

	//Load strings into queue
	while ((buf = getchar()) != '\n') {
		if (buf == ' ') {
			if (str != "") { //if first space, load accumulated string to queue
				q.enqueue(str);
				str = "";
			}
		} else {
			//accumulate the next string
			str += buf;
		}
	}
	//Enqueue final string
	q.enqueue(str);

	//Dequeue random strings to create unique subset
	for (int i=0; i<size; i++) {
		cout << q.dequeue() << endl;
	}

	return 0;
}
