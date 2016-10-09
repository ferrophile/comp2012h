#include <QtGui>
#include "notepad.h"
 
// TODO: code up the main program by modifying the previous main program

int main(int argv, char **args)
{
	QApplication app(argv, args);

	Notepad notepad;
	notepad.show();

	return app.exec();
}
