/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * main.cpp
 */

#include <string>
#include <iostream>
#include "register.h"

int main(int argc, char** argv) {
	Register r;
	
	while(Menu::isRunning()) {
		Menu::showActiveMenu();
	}

	return 0;
}
