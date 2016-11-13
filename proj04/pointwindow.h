/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * pointwindow.h
 */

#ifndef POINTWINDOW_H
#define POINTWINDOW_H

#include <QtGui>
#include <vector>
#include "point.h"

using namespace std;

class PointWindow : public QMainWindow {
Q_OBJECT

public:
	PointWindow();
	PointWindow(char *filename);
	~PointWindow();

public slots:
	void loadBruteAlgo();
	void loadFastAlgo();
	void exitPlotter();
	void aboutPlotter();

private:
	char *file;
	vector<Point> points;

	QImage *background;
	QPainter *painter;

	QMenu *fileMenu;
	QAction *bruteAct;
	QAction *fastAct;
	QAction *exitAct;
	QAction *aboutAct;

	void createActions();
	void createMenus();
};

#endif //POINTWINDOW_H
