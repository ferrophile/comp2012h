#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>
#include <row.h>
#include <tetriscontrol.h>

class TetrisWindow : public QWidget {
	private:	
		QImage bgImage;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QVBoxLayout mainLayout;
		TetrisControl* tetrisControl;

		QBrush colors[8];
		
	protected:
		void keyPressEvent(QKeyEvent *);

	public:
		TetrisWindow(QWidget *parent = 0);
		void draw_block(int type, int x, int y);
		void clear_window();
		void set_lvl_label(QString text);
		void set_score_label(QString text);
};

#endif // TETRISWINDOW_H
