#include "proj02.h"

#include <QApplication>
#include <QKeyEvent>

Tetris::Tetris(QWidget *parent) : QWidget(parent) {
	int i;
	
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
	
	for (i=0; i<20; i++) {
		Row *tempRow = new Row();
		map[i] = tempRow;
	}
	
	//Temp blocks for debugging
	map[0]->set_block(7, 7);
	map[0]->set_block(8, 1);
	map[1]->set_block(7, 5);
	map[1]->set_block(8, 2);
	map[4]->set_block(3, 3);
	map[5]->set_block(3, 3);
	map[6]->set_block(3, 3);
	map[7]->set_block(3, 3);
	map[8]->set_block(3, 3);
	
	new_block();
	update_map();
	
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move_block_down()));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_map()));
	timer->start(1000);
}

Tetris::~Tetris() {
	delete [] map;
}

void Tetris::move_block_down() {
	move_block(0, -1, 0);
}

void Tetris::update_map() {
	int val;
	bgImage.load("background.bmp");
	for (int y=0; y<20; y++) {
		for (int x=0; x<10; x++) {
			val = map[y]->get_block(x);
			if (val) {
				QPainter qPainter(&bgImage);
				qPainter.setBrush(colors[val]);
				qPainter.setPen(Qt::black);
				qPainter.drawRect(x*20, 380-y*20, 19, 19);
				mainLabel.setPixmap(QPixmap::fromImage(bgImage));
				mainLabel.show();
			}
		}		
	}
	
    lvlLabel.setText(QString::number(curDir));
    lvlLabel.show();
}

void Tetris::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Left) {
		move_block(-1, 0, 0);
	}
	if (event->key() == Qt::Key_Right) {
		move_block(1, 0, 0);
	}
	if (event->key() == Qt::Key_Down) {
		move_block(0, -1, 0);
	}
	if (event->key() == Qt::Key_Z) {
		move_block(0, 0, 1);
	}
	if (event->key() == Qt::Key_X) {
		move_block(0, 0, 3);
	}
}

void Tetris::new_block() {
	curType = 4;
	curX = 5;
	curY = 17;
	curDir = 0;
}

void Tetris::update_blocks(int type) {
	int i, tmpX, tmpY;
	map[curY]->set_block(curX,type);
	for (i=0; i<6; i+=2) {
		tmpY = curY + trans_y(coords[curType][i], coords[curType][i+1], curDir);
		tmpX = curX + trans_x(coords[curType][i], coords[curType][i+1], curDir);
		map[tmpY]->set_block(tmpX,type);
	}
}

void Tetris::move_block(int offX, int offY, int offDir) {
	int i, tmpX, tmpY, tmpDir;
	int empty = 1;
	
	update_blocks(0);
	
	if (curY == 0) {
		empty = 0;
	} else {
		empty *= map[curY+offY]->is_empty(curX+offX);
		for (i=0; i<6; i+=2) {
			tmpDir = (curDir+offDir)%4;
			tmpY = curY + trans_y(coords[curType][i], coords[curType][i+1], tmpDir);
			tmpX = curX + trans_x(coords[curType][i], coords[curType][i+1], tmpDir);
			if (tmpY == 0) {
				empty = 0;
			} else {
				empty *= map[tmpY+offY]->is_empty(tmpX+offX);
			}
		}
	}
	
	if (empty) {
		curX += offX;
		curY += offY;
		curDir = (curDir+offDir)%4;
	}
	
	update_blocks(curType);
	update_map();
}

int Tetris::trans_x(int x, int y, int dir) {
	return trans[dir][0]*x + trans[dir][1]*y;
}

int Tetris::trans_y(int x, int y, int dir) {
	return trans[dir][2]*x + trans[dir][3]*y;
}
