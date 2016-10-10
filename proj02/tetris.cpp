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
	
	map[1]->set_block(4, 7);
	map[1]->set_block(5, 1);
	map[2]->set_block(4, 5);
	map[2]->set_block(5, 2);
	//lvlLabel.setText(QString::number(map[1]->get_block(5)));
	//lvlLabel.show();
	
	curType = 4;
	curX = 17;
	curY = 5;
	
	map[curY]->set_block(curX,curType);
	for (i=0; i<6; i+=2)
		map[curY+coords[curType][i+1]]->set_block(curX+coords[curType][i],curType);
	
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_map()));
	timer->start(1000);
}

Tetris::~Tetris() {
	delete [] map;
}

void Tetris::move_block_down() {
	
}

void Tetris::update_map() {
	int val;
	for (int y=0; y<20; y++) {
		for (int x=0; x<10; x++) {
			val = map[y]->get_block(x);
			if (val) {	
				QPainter qPainter(&bgImage);
				qPainter.setBrush(colors[val]);
				qPainter.setPen(Qt::black);
				qPainter.drawRect(x*20, 400-y*20, 19, 19);
				mainLabel.setPixmap(QPixmap::fromImage(bgImage));
				mainLabel.show();
			}
		}		
	}
}
