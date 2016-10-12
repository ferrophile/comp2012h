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
		TetrisWindow* tetrisWindow;
		Row *map[20];
		int curType, curX, curY, curDir;
		int lvl, score, isRunning;
		QTimer *timer;

		int coords[8][6];
		int trans[4][4];
		
		//utility functions
		void new_block();
		void update_blocks(int type);
		int check_block(int offX, int offY, int offDir);
		int trans_x(int x, int y, int dir);
		int trans_y(int x, int y, int dir);
};

#endif // TETRISCONTROL_H
