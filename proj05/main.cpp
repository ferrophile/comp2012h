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
