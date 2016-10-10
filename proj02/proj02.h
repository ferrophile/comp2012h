#ifndef PROJ02_H
#define PROJ02_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>

class Row {
	private:
		int blocks[10];
		
	public:
		Row();
		int check_row_filled();	
		int check_space_filled(int pos); //used for checking before moving
		int get_block(int id);
		void set_block(int id, int type);
};

class Tetris : public QWidget
{
	Q_OBJECT
	
	public:
		Tetris(QWidget *parent = 0);
		~Tetris();
		void new_block();
 
	public slots:
		void move_block_down();
		void update_map();
		
	//protected:
		//void keyPressEvent(QKeyEvent *);
		
	private:
		QImage bgImage;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QVBoxLayout mainLayout;
		
		Row *map[20];
		int curType, curX, curY;
		QTimer *timer;
		
		QBrush colors[8] = {Qt::NoBrush, Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::white, Qt::magenta};
		int coords[8][6] = {{0,0,0,0,0,0}, {0,1,0,2,0,-1}, {0,-1,-1,0,-1,-1}, {0,1,1,0,1,-1}, {0,-1,1,0,1,1}, {0,1,0,-1,1,-1}, {0,1,0,-1,-1,-1}, {-1,0,0,1,1,0}};
};

#endif // PROJ02_H
