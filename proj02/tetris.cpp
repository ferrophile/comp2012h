#include "proj02.h"

#include <QApplication>
#include <QKeyEvent>

Tetris::Tetris(QWidget *parent) : QWidget(parent) {
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
	
	for (int i=0; i<20; i++) {
		Row *tempRow = new Row();
		map[i] = tempRow;
	}
	
	//map[1]->set_block(5, 7);
	//lvlLabel.setText(QString::number(map[1]->get_block(5)));
	//lvlLabel.show();
}

Tetris::~Tetris() {
	delete [] map;
}
