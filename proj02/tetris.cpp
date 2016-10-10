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
	
	map[0]->set_block(7, 7);
	map[0]->set_block(8, 1);
	map[1]->set_block(7, 5);
	map[1]->set_block(8, 2);
	
	curType = 4;
	curX = 5;
	curY = 17;
	
	map[curY]->set_block(curX,curType);
	for (i=0; i<6; i+=2)
		map[curY+coords[curType][i+1]]->set_block(curX+coords[curType][i],curType);
	
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move_block_down()));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_map()));
	timer->start(1000);
}

Tetris::~Tetris() {
	delete [] map;
}

void Tetris::move_block_down() {
	update_blocks(0);
	if (check_blocks(-1))
		curY--;
	update_blocks(curType);
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
}

void Tetris::keyPressEvent(QKeyEvent *event) {
	if(event->key() == Qt::Key_Left) {
		update_blocks(0);
		if (check_blocks(-1))
			curX--;
		update_blocks(curType);
		update_map();
	}
}


void Tetris::update_blocks(int type) {
	int i, tmpX, tmpY;
	map[curY]->set_block(curX,type);
	for (i=0; i<6; i+=2) {
		tmpY = curY+coords[curType][i+1];
		tmpX = curX+coords[curType][i];
		map[tmpY]->set_block(tmpX,type);
	}
}

int Tetris::check_blocks(int offY) {
	int i, tmpX, tmpY;
	int empty = 1;
	
	if (curY == 0) return 0;
	empty *= map[curY+offY]->is_empty(curX);
	for (i=0; i<6; i+=2) {
		tmpY = curY+coords[curType][i+1];
		tmpX = curX+coords[curType][i];
		if (tmpY == 0) return 0;
		empty *= map[tmpY+offY]->is_empty(tmpX);
	}
	return empty;
}
