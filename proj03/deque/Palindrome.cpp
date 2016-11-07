/*
 * COMP2012H Project 3
 * Hong Wing PANG 20315504
 * Palindrome.cpp
 */

#include <iostream>
#include <cstdio>
#include <string>
#include "deque.h"

using namespace std;

int main(int argc, char ** argv) {
	Deque<char> q;
	char buf;
	char f, l;
	//Default state is false
	bool ispal = false;

	//Get palindrome line
	string line;
	getline(cin, line);

	for (int i=0; i<line.length(); i++) {
		buf = line[i];
		//If not the 4 characters, return false
		if (buf != 'A' && buf != 'T' && buf != 'C' && buf != 'G') {
			cout << "false" << endl;
			return 0;
		}
		//Else add char to deque
		q.addLast(buf);
	}

	//Skip and return false if size is odd number
	if (!(q.size() % 2)) {
		ispal = true;
		while(q.size()) {
			//Retrieve end characters pair by pair
			f = q.removeFirst();
			l = q.removeLast();

			//If not match, return false and break while loop
			if ((f+l != 'A'+'T') && (f+l != 'C'+'G')) {
				ispal = false;
				break;
			}
		}
	}

	cout << (ispal ? "true" : "false") << endl;

	return 0;
}
