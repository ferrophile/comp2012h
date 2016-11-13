/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * pointwindow.cpp
 */

#include "pointwindow.h"
#include <QtGui>

PointWindow::PointWindow() : PointWindow("") {}

PointWindow::PointWindow(char *filename) : file(filename) {
	QLabel *plotArea = new QLabel;	
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

	createActions();
	createMenus();

	setWindowTitle(tr("COMP2012H Project 4"));
}

PointWindow::~PointWindow() {
	delete background;
	delete painter;	
}

void PointWindow::loadBruteAlgo() {

}

void PointWindow::loadFastAlgo() {

}

void PointWindow::exitPlotter() {

}

void PointWindow::aboutPlotter() {

}

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

void PointWindow::createMenus() {
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(bruteAct);
	fileMenu->addAction(fastAct);
	fileMenu->addAction(exitAct);

	fileMenu = menuBar()->addMenu(tr("&Help"));
	fileMenu->addAction(aboutAct);
}
