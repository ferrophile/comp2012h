//COMP2012H Proj02 Tetris
//Hong Wing PANG
//row.cpp

#include <QApplication>
#include <QKeyEvent>
#include "tetriswindow.h"

/*--- Constructor ---*/
//Creates new empty row
Row::Row() {
	clear_row();
}

/*--- Interface methods ---*/
//Return map value
int Row::get_block(int id) {
	return blocks[id];
}

//Check if map cell has block or not
int Row::is_empty(int id) {
	if ((id < 0) || (id >= 20) || blocks[id])
		return 0;
	return 1;
}

//Sets map cell to certain value
void Row::set_block(int id, int type) {
	if (type < 0 || type > 7)
		return;
	blocks[id] = type;
}

//Sets all map cell values to 0
void Row::clear_row() {
	for (int i=0; i<10; i++)
		blocks[i] = 0;
}

//Check if row is filled
int Row::is_row_filled() {
	for (int i=0; i<10; i++) {
		if (!blocks[i])
			return 0;
	}
	return 1;
}

//Check if row is empty
int Row::is_row_empty() {
	for (int i=0; i<10; i++) {
		if (blocks[i])
			return 0;
	}
	return 1;
}
