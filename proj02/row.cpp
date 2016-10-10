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

int Row::is_empty(int id) {
	if ((id < 0) || (id >= 20) || blocks[id])
		return 0;
	return 1;
}

void Row::set_block(int id, int type) {
	if (type < 0 || type > 7)
		return;
	blocks[id] = type;
}
