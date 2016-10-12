//COMP2012H Proj02 Tetris
//Hong Wing PANG
//tetriswindow.cpp

#include <QApplication>
#include <QKeyEvent>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tetriswindow.h"

/*--- Constructor ---*/
TetrisWindow::TetrisWindow(QWidget *parent) : QWidget(parent), colors{Qt::NoBrush, Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, QBrush(QColor(255,127,0)), Qt::magenta} {
	//Set layout of GUI
	mainLayout.addWidget(&mainLabel);
	sideLayout.addWidget(&prevLabel);
	sideLayout.addWidget(&lvlLabel);
	sideLayout.addWidget(&scoreLabel);
	mainLayout.addLayout(&sideLayout);
	setLayout(&mainLayout);
	
	prevBg = QImage(100, 150, QImage::Format_RGB32);
	clear_window();
	clear_prev_window();

	lvlLabel.setText("Level: 1");
	lvlLabel.show();
	
	scoreLabel.setText("Score: 0");
	scoreLabel.show();

	//Create tetrisControl
	tetrisControl = new TetrisControl();
	tetrisControl->set_tetriswindow(this);
}

/*--- Keypress Events ---*/
void TetrisWindow::keyPressEvent(QKeyEvent *event) {
	if (tetrisControl->get_runningState()) {
		if (event->key() == Qt::Key_Left) {
			//Move block to left
			tetrisControl->move_block(-1, 0, 0);
		}
		if (event->key() == Qt::Key_Right) {
			//Move block to right
			tetrisControl->move_block(1, 0, 0);
		}
		if (event->key() == Qt::Key_Down) {
			//Move block downwards
			tetrisControl->move_block(0, -1, 0);
		}
		if (event->key() == Qt::Key_Z) {
			//Rotate clockwise
			tetrisControl->move_block(0, 0, 1);
		}
		if (event->key() == Qt::Key_X) {
			//Rotate counter-clockwise
			tetrisControl->move_block(0, 0, 3);
		}
	} else {
		if (event->key() == Qt::Key_Up) {
			//Starts or re-start
			tetrisControl->reset_game();
		}
	}
}

/*--- GUI Class methods ---*/
//Draws one block on screen.
void TetrisWindow::draw_block(int type, int x, int y, int isPrev) {
	if (!type) return;

	if (isPrev) {	//if draw on preview board
		QPainter qPainter(&o);
		qPainter.setBrush(colors[type]);
		qPainter.setPen(Qt::black);
		qPainter.drawRect(x*20+40, 70-y*20, 19, 19);
		prevLabel.setPixmap(QPixmap::fromImage(prevBg));
		prevLabel.show();
	} else {	//if draw on main board
		QPainter qPainter(&bgImage);
		qPainter.setBrush(colors[type]);
		qPainter.setPen(Qt::black);
		qPainter.drawRect(x*20, 380-y*20, 19, 19);
		mainLabel.setPixmap(QPixmap::fromImage(bgImage));
		mainLabel.show();
	}
}

//Clears main window
void TetrisWindow::clear_window() {
	bgImage.load("background.bmp");
	mainLabel.setPixmap(QPixmap::fromImage(bgImage));
	mainLabel.show();
}

//Clears preview window
void TetrisWindow::clear_prev_window() {
	QPainter painter(&prevBg);
	painter.setBrush(Qt::white);
	painter.drawRect(0,0,100,150);
	prevLabel.setPixmap(QPixmap::fromImage(prevBg));
	prevLabel.show();
}

//Sets the content of the level QLabel
void TetrisWindow::set_lvl_label(QString text) {
	lvlLabel.setText(text);
	lvlLabel.show();
}

//Sets the content of the score QLabel
void TetrisWindow::set_score_label(QString text) {
	scoreLabel.setText(text);
	scoreLabel.show();
}
