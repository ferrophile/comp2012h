#include <QApplication>
#include <QKeyEvent>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tetriswindow.h"

TetrisControl::TetrisControl(QWidget *parent) : QWidget(parent), nextType(rand()%7+1), isRunning(0), coords{{0,0,0,0,0,0}, {0,1,0,2,0,-1}, {0,-1,-1,0,-1,-1}, {0,1,1,0,1,-1}, {0,-1,1,0,1,1}, {0,1,0,-1,1,-1}, {0,1,0,-1,-1,-1}, {-1,0,0,1,1,0}}, trans{{1,0,0,1},{0,1,-1,0},{-1,0,0,-1},{0,-1,1,0}} {
	int i;

	for (i=0; i<20; i++) {
		Row *tempRow = new Row();
		map[i] = tempRow;
	}
	
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move_block_down()));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_map()));
}

TetrisControl::~TetrisControl() {
	delete [] map;
}

int TetrisControl::move_block(int offX, int offY, int offDir) {
	int i, tmpX, tmpY, tmpDir;
	int empty = 1;
	
	update_blocks(0);
	
	if (curY+offY < 0) {
		empty = 0;
	} else {
		empty *= map[curY+offY]->is_empty(curX+offX);
		for (i=0; i<6; i+=2) {
			tmpDir = (curDir+offDir)%4;
			tmpY = curY + trans_y(coords[curType][i], coords[curType][i+1], tmpDir);
			tmpX = curX + trans_x(coords[curType][i], coords[curType][i+1], tmpDir);
			if (tmpY+offY < 0) {
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
	
	return empty;
}

void TetrisControl::reset_game() {
	int i;
	lvl = 1;
	score = 0;
	isRunning = 1;
	
	tetrisWindow->set_lvl_label("Level: 1");
	tetrisWindow->set_score_label("Score: 0");

	for (i=0; i<20; i++) {
		map[i]->clear_row();
	}

	srand(time(NULL));
	new_block();
	update_map();
	timer->start(1000);
}

void TetrisControl::set_tetriswindow(TetrisWindow* window) {
	tetrisWindow = window;
}

int TetrisControl::get_runningState() {
	return isRunning;
}

void TetrisControl::move_block_down() {
	int i, j;
	int rowNo = 0;
	if (!move_block(0, -1, 0)) {
		for (i=0; i<20; i++) {
			if (map[i]->is_row_empty()) break;
			if (map[i]->is_row_filled()) {
				rowNo++;
				delete map[i];
				for (j=i; j<19; j++) {
					map[j] = map[j+1];
				}
				Row *tempRow = new Row();
				map[19] = tempRow;
				i--;
			}
		}
		if (rowNo) {
			score += (rowNo * rowNo * 10);
			QString	scoreMsg;
			scoreMsg += "Score: ";
			scoreMsg += QString::number(score);
			tetrisWindow->set_score_label(scoreMsg);
		}
		if (score >= lvl*100 && lvl < 10) {
			lvl++;
			QString	lvlMsg;
			lvlMsg += "Level: ";
			lvlMsg += QString::number(lvl);
			tetrisWindow->set_lvl_label(lvlMsg);
			timer->setInterval(1000 - (lvl-1)*100);
		}
		new_block();
		update_map();
	}
}

void TetrisControl::update_map() {
	tetrisWindow->clear_window();
	for (int y=0; y<20; y++) {
		for (int x=0; x<10; x++) {
			tetrisWindow->draw_block(map[y]->get_block(x), x, y, 0);
		}		
	}
}

void TetrisControl::new_block() {
	int i, tmpX, tmpY;
	int empty = 1;

	curType = nextType;
	nextType = rand()%7+1;
	curX = 5;
	curY = 17;
	curDir = 0;

	tetrisWindow->clear_prev_window();
	tetrisWindow->draw_block(nextType, 0, 0, 1);
	for (i=0; i<6; i+=2) {
		tetrisWindow->draw_block(nextType, coords[nextType][i], coords[nextType][i+1], 1);
	}

	empty *= map[curY]->is_empty(curX);
	for (i=0; i<6; i+=2) {
		tmpY = curY + trans_y(coords[curType][i], coords[curType][i+1], curDir);
		tmpX = curX + trans_x(coords[curType][i], coords[curType][i+1], curDir);
		empty *= map[tmpY]->is_empty(tmpX);
	}

	if (empty) {
		update_blocks(curType);
	} else {
		tetrisWindow->set_lvl_label("Game Over!");
		timer->stop();
		isRunning = 0;
	}
}

void TetrisControl::update_blocks(int type) {
	int i, tmpX, tmpY;
	map[curY]->set_block(curX,type);
	for (i=0; i<6; i+=2) {
		tmpY = curY + trans_y(coords[curType][i], coords[curType][i+1], curDir);
		tmpX = curX + trans_x(coords[curType][i], coords[curType][i+1], curDir);
		map[tmpY]->set_block(tmpX,type);
	}
}

int TetrisControl::trans_x(int x, int y, int dir) {
	return trans[dir][0]*x + trans[dir][1]*y;
}

int TetrisControl::trans_y(int x, int y, int dir) {
	return trans[dir][2]*x + trans[dir][3]*y;
}
