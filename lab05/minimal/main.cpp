#include <qapplication.h>
#include <stdlib.h>
#include <stdio.h>

#include "minimal.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("usage %s [time]\n", argv[0]);
		return 0;
	}
	
	QApplication a(argc, argv);
	Minimal *w = new Minimal(atoi(argv[1]));
	w->show();
	return a.exec();
}
