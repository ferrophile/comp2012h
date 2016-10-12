//COMP2012H Proj02 Tetris
//Hong Wing PANG
//main.cpp

#include <QtGui>
#include "tetriswindow.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	
	TetrisWindow *w = new TetrisWindow();
	w->show();
	
	return a.exec();
}
