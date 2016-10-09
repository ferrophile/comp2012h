#include "proj02.h"

#include <QApplication>
#include <QKeyEvent>

Row::Row() {
	for (int i=0; i<10; i++)
		blocks[i] = 0;
}

int Row::get_block(int id) {
	return blocks[id];
}

void Row::set_block(int id, int type) {
	if (type < 0 || type > 7)
		return;
	blocks[id] = type;
}
