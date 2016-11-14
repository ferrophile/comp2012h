/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * plotter_main.cpp
 */

#include "pointwindow.h"
#include <QtGui>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char ** argv) {
	QApplication a(argc, argv);

	//If no arguments passed, print error
	if (argc < 2) {
   		fprintf(stderr,"usage %s filename\n", argv[0]);
		exit(0);
	}

	PointWindow *p = new PointWindow(argv[1]);
	p->show();

	return a.exec();
}
