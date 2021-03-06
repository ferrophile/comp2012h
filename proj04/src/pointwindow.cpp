/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * pointwindow.cpp
 */

#include "pointwindow.h"
#include "brute.h"
#include "fast.h"
#include <QtGui>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

//Default constructor
PointWindow::PointWindow() {}

//Type conversion constructor
//Initializes filename and size
PointWindow::PointWindow(char *filename) : file(filename), size(0) {
	//Setup plot area and painter
	plotArea = new QLabel;	
	background = new QImage(600, 600, QImage::Format_RGB32);
	painter = new QPainter(background);

	plotArea->setMinimumSize(300, 300);
	plotArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	plotArea->setScaledContents(true);
	plotArea->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
	plotArea->setAlignment(Qt::AlignCenter);

	painter->setBrush(Qt::white);
	painter->drawRect(0,0,600,600);

	plotArea->setPixmap(QPixmap::fromImage(*background));
	plotArea->show();

	//Setup window layout
	QWidget *widget = new QWidget;
	setCentralWidget(widget);

	QWidget *topFiller = new QWidget;
	topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QWidget *bottomFiller = new QWidget;
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin(5);
	layout->addWidget(topFiller);
	layout->addWidget(plotArea);
	layout->addWidget(bottomFiller);
	widget->setLayout(layout);

	loadPoints(); //Read in points from file and draw them
	createActions(); //Initialize actions for menu options
	createMenus(); //Initialize the menu itself

	setWindowTitle(tr("COMP2012H Project 4"));

	timer = new QElapsedTimer();
}

//Destructor
PointWindow::~PointWindow() {
	delete background;
	delete painter;	
	delete timer;
}

/*-- Menu events --*/

//Load Brute algorithm
void PointWindow::loadBruteAlgo() {
	Brute bruteObj(points);
	timer->start();
	paintLines(bruteObj.getCollinearPoints());
	createMsgBox("Timer", QString::number(timer->elapsed())+" msec");
}

//Load Fast algorithm
void PointWindow::loadFastAlgo() {
	Fast fastObj(points);
	timer->start();
	paintLines(fastObj.getCollinearPoints());
	createMsgBox("Timer", QString::number(timer->elapsed())+" msec");
}

//Quit program
void PointWindow::exitPlotter() {
	close();
}

//Create About message box
void PointWindow::aboutPlotter() {
	createMsgBox("About", "COMP2012H Proj04\nPointPlotter\nHong Wing PANG");
}

/*-- Utility functions --*/

//Plot a Point in plot area
void PointWindow::guiDrawPoint(const Point &pt) const {
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setBrush(QColor(200, 200, 200));
	painter->setPen(Qt::black);
	painter->drawEllipse(convertPoint(pt), SIZE, SIZE);
}

//Plot a line from one Point to another in plot area
void PointWindow::guiDrawLine(const Point &pt1, const Point &pt2) const {
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(QPen(Qt::black, 1));
	painter->drawLine(convertPoint(pt1), convertPoint(pt2));
}

//Draw list of lines
void PointWindow::paintLines(const vector< vector<Point> > &lines) const {	
	for (int i=0; i < (int)lines.size(); i++)
		guiDrawLine(*(lines[i].begin()), *(lines[i].end()-1));
	for (int i=0; i < size; i++)
		guiDrawPoint(points[i]); //Redraw points so that it looks better lol
	plotArea->setPixmap(QPixmap::fromImage(*background));
	plotArea->show();
}

//Show message box
void PointWindow::createMsgBox(QString title, QString msg) const {
	QMessageBox msgBox;
	msgBox.setWindowTitle(title);
	msgBox.setText(msg);
	msgBox.exec();
}

//Convert Point to QPointF object with coordinates scaled to fit window
QPointF PointWindow::convertPoint(const Point &pt) const {
	int x = pt.getX()*SCALE_X;
	int y = WIN_Y - pt.getY()*SCALE_Y;
	return QPointF(x, y);
}

//Read Points from file
void PointWindow::loadPoints() {
	ifstream fs(file);
	string str;
	int tmpX, tmpY;

	getline(fs, str);
	int n = atoi(str.c_str());
	size = n;
	for (int i=0; i<n; i++) {
		getline(fs, str, ' ');
		tmpX = atoi(str.c_str());
		getline(fs, str, '\n');
		tmpY = atoi(str.c_str());
		points.push_back(Point(tmpX, tmpY));
	}

	for (int i=0; i < size; i++)
		guiDrawPoint(points[i]);
	plotArea->setPixmap(QPixmap::fromImage(*background));
	plotArea->show();
}

//Initialize actions for menu options
void PointWindow::createActions() {
	bruteAct = new QAction(tr("&Brute"), this);
	bruteAct->setStatusTip(tr("Load brute algorithm"));
	connect(bruteAct, SIGNAL(triggered()), this, SLOT(loadBruteAlgo()));

	fastAct = new QAction(tr("&Fast"), this);
	fastAct->setStatusTip(tr("Load fast algorithm"));
	connect(fastAct, SIGNAL(triggered()), this, SLOT(loadFastAlgo()));

	exitAct = new QAction(tr("&Exit"), this);
	exitAct->setStatusTip(tr("Exit plotter"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(exitPlotter()));

	aboutAct = new QAction(tr("&About"), this);
	aboutAct->setStatusTip(tr("About plotter"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutPlotter()));
}

//Initialize the menu itself
void PointWindow::createMenus() {
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(bruteAct);
	fileMenu->addAction(fastAct);
	fileMenu->addAction(exitAct);

	fileMenu = menuBar()->addMenu(tr("&Help"));
	fileMenu->addAction(aboutAct);
}
