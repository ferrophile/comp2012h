#include <qapplication.h>
#include <stdlib.h>

#include "my_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
//atoi(argv[1])
	QWidget* w = new MyMainWindow();
	a.setMainWidget(w);
	w->show();
	return a.exec();
};
