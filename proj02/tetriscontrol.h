//COMP2012H Proj02 Tetris
//Hong Wing PANG
//tetriscontrol.h

#ifndef TETRISCONTROL_H
#define TETRISCONTROL_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>
#include <row.h>

class TetrisWindow;
class TetrisControl : public QWidget {
	Q_OBJECT
	
	public:
		TetrisControl(QWidget *parent = 0);
		~TetrisControl();
		int move_block(int offX, int offY, int offDir);
		void reset_game();
		int get_runningState();
		void set_tetriswindow(TetrisWindow* window);
 
	public slots:
		void move_block_down();
		void update_map();
		
	private:
		//GUI object
		TetrisWindow* tetrisWindow;

		//Array of Row pointers to use as a map
		Row *map[20];

		/* Game control variables */
		//Type of next block
		int nextType;
		//Type, coordinates, orientation of current block
		int curType, curX, curY, curDir;
		//Level, Score, run state of game
		int lvl, score, isRunning;

		//Timer object
		QTimer *timer;

		//2D array containing coordinates
		//Origin is set at rotation center 
		int coords[8][6];

		//2D array storing rotational matrices of 4 directions
		int trans[4][4];
		
		/* utility functions */
		void new_block();
		void update_blocks(int type);
		int check_block(int offX, int offY, int offDir);
		int trans_x(int x, int y, int dir);
		int trans_y(int x, int y, int dir);
};

#endif // TETRISCONTROL_H
