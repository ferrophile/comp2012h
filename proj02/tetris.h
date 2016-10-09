#ifndef TETRIS_H
#define TETRIS_H

#include <QtGui>
#include <QLabel>

class Tetris : public QWidget
{
	Q_OBJECT
	
	public:
		Tetris(QWidget *parent = 0);
		
	//private slots:
	//	void quit();
		
	private:
		QImage bgImage;
		QLabel mainLabel, prevLabel, lvlLabel, scoreLabel;
		QVBoxLayout mainLayout;
};

#endif // TETRIS_H
