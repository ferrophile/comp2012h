//COMP2012H Proj02 Tetris
//Hong Wing PANG
//tetriswindow.h

#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>
#include <row.h>
#include <tetriscontrol.h>

class TetrisWindow : public QWidget {
	public:
		TetrisWindow(QWidget *parent = 0);
		void draw_block(int type, int x, int y, int isPrev);
		void clear_window();
		void clear_prev_window();
		void set_lvl_label(QString text);
		void set_score_label(QString text);
		
	protected:
		void keyPressEvent(QKeyEvent *);

	private:
		//GUI Qt Objects
		QImage bgImage, prevBg;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QHBoxLayout mainLayout;
		QVBoxLayout sideLayout;

		//Controller object
		TetrisControl* tetrisControl;

		//Array storing colors to be used
		QBrush colors[8];
};

#endif // TETRISWINDOW_H
