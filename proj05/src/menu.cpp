/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * menu.cpp
 */

#include "menu.h"

Menu* Menu::activeMenu = 0;

bool Menu::running = true;

//Default constructor
Menu::Menu() : size(0), title("") {}

//Constructor with menu title
Menu::Menu(std::string t) : size(0), title(t) {}

Menu::~Menu() {}

//Add item (function) to menu
void Menu::addItem(std::string d, std::function<void()> a) {
	++size;
	struct MenuItem item;
	item.desc = d;
	item.action = a;
	items.push_back(item);
}

//Add link to another menu
void Menu::addChild(std::string d, Menu* m) {
	addItem(d, std::bind(Menu::setActiveMenu, m));
}

//Show the menu
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

	//Parse user input
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

	//Run the action specified by menu item
	items[--option].action();
}

//Set active menu
void Menu::setActiveMenu(Menu* m) {
	activeMenu = m;
}

//Show active menu, to be run in an infinite loop
void Menu::showActiveMenu() {
	activeMenu->show();
}

//Checking condition if program terminates
void Menu::exitMenu() {
	Menu::running = false;
}

//Returns if menu is stil running
bool Menu::isRunning() {
	return Menu::running;
}
