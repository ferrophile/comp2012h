#include "deque.h"
#include <iostream>
#include <cstdio>

using namespace std;


int main(int argc, char ** argv){
	Deque<char> q;
	char buf;
	char a, b;
	bool ispal = false;

	while (cin >> buf) {
		if (buf != 'A' && buf != 'T' && buf != 'C' && buf != 'G') {
			cout << "false" << endl;
			return 0;
		}
		q.addLast(buf);
	}

	if (!(q.size() % 2)) {
		ispal = true;
		while(q.size()) {
			a = q.removeFirst();
			b = q.removeLast();
			if ((a+b != 'A'+'T') && (a+b != 'C'+'G')) {
				ispal = false;
				break;
			}
		}
	}

	cout << (ispal ? "true" : "false") << endl;

	return 0;
}
