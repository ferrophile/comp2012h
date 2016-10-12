#include <QApplication>
#include <QKeyEvent>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tetriswindow.h"

TetrisWindow::TetrisWindow(QWidget *parent) : QWidget(parent), colors{Qt::NoBrush, Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, QBrush(QColor(255,127,0)), Qt::magenta} {
	mainLayout.addWidget(&mainLabel);
	mainLayout.addWidget(&prevLabel);
	mainLayout.addWidget(&lvlLabel);
	mainLayout.addWidget(&scoreLabel);
	setLayout(&mainLayout);
	
	bgImage.load("background.bmp");
	mainLabel.setPixmap(QPixmap::fromImage(bgImage));
	mainLabel.show();

	lvlLabel.setText("Level: 1");
	lvlLabel.show();
	
	scoreLabel.setText("Score: 0");
	scoreLabel.show();

	tetrisControl = new TetrisControl();
	tetrisControl->set_tetriswindow(this);
}

void TetrisWindow::keyPressEvent(QKeyEvent *event) {
	if (tetrisControl->get_runningState()) {
		if (event->key() == Qt::Key_Left) {
			tetrisControl->move_block(-1, 0, 0);
		}
		if (event->key() == Qt::Key_Right) {
			tetrisControl->move_block(1, 0, 0);
		}
		if (event->key() == Qt::Key_Down) {
			tetrisControl->move_block(0, -1, 0);
		}
		if (event->key() == Qt::Key_Z) {
			tetrisControl->move_block(0, 0, 1);
		}
		if (event->key() == Qt::Key_X) {
			tetrisControl->move_block(0, 0, 3);
		}
	} else {
		if (event->key() == Qt::Key_Up) {
			tetrisControl->reset_game();
		}
	}
}

void TetrisWindow::draw_block(int type, int x, int y) {
	if (!type) return;
	QPainter qPainter(&bgImage);
	qPainter.setBrush(colors[type]);
	qPainter.setPen(Qt::black);
	qPainter.drawRect(x*20, 380-y*20, 19, 19);
	mainLabel.setPixmap(QPixmap::fromImage(bgImage));
	mainLabel.show();
}

void TetrisWindow::clear_window() {
	bgImage.load("background.bmp");
}

void TetrisWindow::set_lvl_label(QString text) {
	lvlLabel.setText(text);
	lvlLabel.show();
}

void TetrisWindow::set_score_label(QString text) {
	scoreLabel.setText(text);
	scoreLabel.show();
}
