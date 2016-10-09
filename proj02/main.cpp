#include <QtGui>
#include "tetris.h"

ing main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	
	Tetris *tetris = new Tetris();
	tetris->show();
	
	return a.exec();
}
