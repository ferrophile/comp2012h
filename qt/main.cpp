#include <QApplication>
#include <QTextEdit>
#include "notepad.h"

int main(int argv, char **args) {
	QApplication app(argv, args);
	
	Notepad notepad;
	notepad.show();
	
	return app.exec();
}
