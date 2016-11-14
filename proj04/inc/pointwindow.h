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

#define WIN_X 600
#define WIN_Y 600
#define MAX_X 32768
#define MAX_Y 32768
#define SCALE_X WIN_X/MAX_X
#define SCALE_Y WIN_Y/MAX_Y
#define SIZE 5

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
	int size;
	vector<Point> points;

	QLabel *plotArea;
	QImage *background;
	QPainter *painter;

	QMenu *fileMenu;
	QAction *bruteAct;
	QAction *fastAct;
	QAction *exitAct;
	QAction *aboutAct;
	QElapsedTimer *timer;

	void guiDrawPoint(const Point &pt) const;
	void guiDrawLine(const Point &pt1, const Point &pt2) const;
	void paintLines(const vector< vector<Point> > &lines) const;
	void createMsgBox(QString title, QString msg) const;
	QPointF convertPoint(const Point &pt) const;

	void loadPoints();
	void createActions();
	void createMenus();
};

#endif //POINTWINDOW_H
