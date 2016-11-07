/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * PointPlotter.cpp
 */

#include <QtGui>

using namespace std;

int main(int argc, char ** argv) {
	QApplication a(argc, argv);

	Point *p = new Point();
	p->show();

	return a.exec();
}
