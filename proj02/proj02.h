#ifndef PROJ02_H
#define PROJ02_H

#include <QtGui>
#include <QLabel>

class Row {
	private:
		int blocks[10];
		
	public:
		int check_row_filled();	
		int check_space_filled(int pos); //used for checking before moving
};

class Tetris : public QWidget
{
	Q_OBJECT
	
	public:
		Tetris(QWidget *parent = 0);
		void move_block_down(); //run every second
		void update_map(); //run every second, refresh map
		void new_block();
 
	//protected:
		//void keyPressEvent(QKeyEvent *);
		
	private:
		QImage bgImage;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QVBoxLayout mainLayout;
		
		Row map[20];
		int cur_block_type, cur_block_x, cur_block_y;
};

#endif // PROJ02_H
