#include <QtGui>
#include "proj02.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	
	Tetris *tetris = new Tetris();
	tetris->show();
	
	return a.exec();
}
