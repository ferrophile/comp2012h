#include "menu.h"

Menu* Menu::activeMenu = 0;

Menu::Menu() : size(0), title("") {}

Menu::Menu(std::string t) : size(0), title(t) {}

Menu::~Menu() {}

void Menu::addItem(std::string d, std::function<void()> a) {
	++size;
	struct MenuItem item;
	item.desc = d;
	item.action = a;
	items.push_back(item);
}

void Menu::addChild(std::string d, Menu* m) {
	addItem(d, std::bind(Menu::setActiveMenu, m));
}

void Menu::show() {
	std::vector<MenuItem>::iterator itr;
	int count = 1;
	int option = 0;

	std::cout << title << std::endl;
	for (int i=0; i < title.length(); i++)
		std::cout << "-";
	std::cout << std::endl;

	for(itr = items.begin(); itr != items.end(); ++itr) {
		std::cout << count << ": ";
		std::cout << itr->desc << std::endl;
		count++;
	}

	std::cout << "Select your option:" << std::endl;
	std::cin >> option;
	std::cout << std::endl;

	items[--option].action();
}

void Menu::setActiveMenu(Menu* m) {
	activeMenu = m;
}

void Menu::showActiveMenu() {
	activeMenu->show();
}
