#ifndef ROW_H
#define ROW_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>

class Row {
	private:
		int blocks[10];
		
	public:
		Row();
		int get_block(int id);
		int is_empty(int id);
		void set_block(int id, int type);
		void clear_row();
		int is_row_filled();
		int is_row_empty();
};

#endif // ROW_H
