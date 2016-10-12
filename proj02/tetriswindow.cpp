#include <QApplication>
#include <QKeyEvent>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tetriswindow.h"

TetrisWindow::TetrisWindow(QWidget *parent) : QWidget(parent), colors{Qt::NoBrush, Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, QBrush(QColor(255,127,0)), Qt::magenta} {
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

void TetrisWindow::draw_block(int type, int x, int y, int isPrev) {
	if (!type) return;

	if (isPrev) {
		QPainter qPainter(&prevBg);
		qPainter.setBrush(colors[type]);
		qPainter.setPen(Qt::black);
		qPainter.drawRect(x*20+40, 70-y*20, 19, 19);
		prevLabel.setPixmap(QPixmap::fromImage(prevBg));
		prevLabel.show();
	} else {
		QPainter qPainter(&bgImage);
		qPainter.setBrush(colors[type]);
		qPainter.setPen(Qt::black);
		qPainter.drawRect(x*20, 380-y*20, 19, 19);
		mainLabel.setPixmap(QPixmap::fromImage(bgImage));
		mainLabel.show();
	}
}

void TetrisWindow::clear_window() {
	bgImage.load("background.bmp");
	mainLabel.setPixmap(QPixmap::fromImage(bgImage));
	mainLabel.show();
}

void TetrisWindow::clear_prev_window() {
	QPainter painter(&prevBg);
	painter.setBrush(Qt::white);
	painter.drawRect(0,0,100,150);
	prevLabel.setPixmap(QPixmap::fromImage(prevBg));
	prevLabel.show();
}

void TetrisWindow::set_lvl_label(QString text) {
	lvlLabel.setText(text);
	lvlLabel.show();
}

void TetrisWindow::set_score_label(QString text) {
	scoreLabel.setText(text);
	scoreLabel.show();
}
