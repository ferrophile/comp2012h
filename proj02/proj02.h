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
		int get_block(int id);
		int is_empty(int id);
		void set_block(int id, int type);
		int is_row_filled();
		int is_row_empty();
};

class Tetris : public QWidget
{
	Q_OBJECT
	
	public:
		Tetris(QWidget *parent = 0);
		~Tetris();
 
	public slots:
		void move_block_down();
		void update_map();
		
	protected:
		void keyPressEvent(QKeyEvent *);
		
	private:
		QImage bgImage;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QVBoxLayout mainLayout;
		
		Row *map[20];
		int curType, curX, curY, curDir;
		int lvl, score;
		QTimer *timer;
		
		QBrush colors[8] = {Qt::NoBrush, Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::white, Qt::magenta};
		int coords[8][6] = {{0,0,0,0,0,0}, {0,1,0,2,0,-1}, {0,-1,-1,0,-1,-1}, {0,1,1,0,1,-1}, {0,-1,1,0,1,1}, {0,1,0,-1,1,-1}, {0,1,0,-1,-1,-1}, {-1,0,0,1,1,0}};
		int trans[4][4] = {{1,0,0,1},{0,1,-1,0},{-1,0,0,-1},{0,-1,1,0}};
		
		//utility functions
		void new_block();
		void update_blocks(int type);
		int move_block(int offX, int offY, int offDir);
		int trans_x(int x, int y, int dir);
		int trans_y(int x, int y, int dir);
};

#endif // PROJ02_H
