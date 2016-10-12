#include "proj02.h"

#include <QApplication>
#include <QKeyEvent>

Row::Row() {
	clear_row();
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

void Row::clear_row() {
	for (int i=0; i<10; i++)
		blocks[i] = 0;
}

int Row::is_row_filled() {
	for (int i=0; i<10; i++) {
		if (!blocks[i])
			return 0;
	}
	return 1;
}

int Row::is_row_empty() {
	for (int i=0; i<10; i++) {
		if (blocks[i])
			return 0;
	}
	return 1;
}
