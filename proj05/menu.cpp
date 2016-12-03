#include "menu.h"

Menu* Menu::activeMenu = 0;

Menu::Menu() : size(0) {}

Menu::~Menu() {}

void Menu::addItem(std::string d, std::function<void()> a) {
	++size;
	struct MenuItem item;
	item.desc = d;
	item.action = a;
	items.push_back(item);
}

void Menu::show() {
	std::vector<MenuItem>::iterator itr;
	int count = 1;
	int option = 0;

	for(itr = items.begin(); itr != items.end(); ++itr) {
		std::cout << count << ": ";
		std::cout << itr->desc << std::endl;
		count++;
	}

	std::cout << "Select your option:" << std::endl;
	std::cin >> option;
	items[--option].action();
}

void Menu::setActiveMenu(Menu* m) {
	activeMenu = m;
}

void Menu::showActiveMenu() {
	activeMenu->show();
}
