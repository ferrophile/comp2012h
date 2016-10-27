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
	bool ispal = false;

	string line;
	getline(cin, line);

	for (int i=0; i<line.length(); i++) {
		buf = line[i];
		if (buf != 'A' && buf != 'T' && buf != 'C' && buf != 'G') {
			cout << "false" << endl;
			return 0;
		}
		q.addLast(buf);
	}

	if (!(q.size() % 2)) {
		ispal = true;
		while(q.size()) {
			f = q.removeFirst();
			l = q.removeLast();
			if ((f+l != 'A'+'T') && (f+l != 'C'+'G')) {
				ispal = false;
				break;
			}
		}
	}

	cout << (ispal ? "true" : "false") << endl;

	return 0;
}
