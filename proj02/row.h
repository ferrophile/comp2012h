//COMP2012H Proj02 Tetris
//Hong Wing PANG
//row.h

#ifndef ROW_H
#define ROW_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>

class Row {
	public:
		Row();
		int get_block(int id);
		int is_empty(int id);
		void set_block(int id, int type);
		void clear_row();
		int is_row_filled();
		int is_row_empty();

	private:
		//Array storing the blocks
		int blocks[10];
};

#endif // ROW_H
