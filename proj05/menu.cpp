#include "menu.h"

Menu* Menu::activeMenu = 0;

bool Menu::running = true;

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
	std::string input;
	int count = 1;
	int option = 0;

	std::cout << title << std::endl;
	for (int i=0; i < title.length(); i++)
		std::cout << "-";
	std::cout << std::endl;

	for (itr = items.begin(); itr != items.end(); ++itr) {
		std::cout << count << ": ";
		std::cout << itr->desc << std::endl;
		count++;
	}

	std::cout << "Select your option (1-" << size << "): ";
	bool state = false;

	do {
		std::getline(std::cin, input);
		try {
			option = std::stoi(input);
		} catch (...) {
			state = false;
		}
		state = (option > 0 && option <= size);
		if (!state)
			std::cout << "Invalid input, input again: ";
	} while (!state);

	std::cout << std::endl;
	items[--option].action();
}

void Menu::setActiveMenu(Menu* m) {
	activeMenu = m;
}

void Menu::showActiveMenu() {
	activeMenu->show();
}

void Menu::exitMenu() {
	Menu::running = false;
}

bool Menu::isRunning() {
	return Menu::running;
}
