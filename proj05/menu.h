#ifndef _MENU_H
#define _MENU_H

#include <vector>
#include <string>
#include <iostream>
#include <functional>

class Menu {
	struct MenuItem {
		std::string desc;
		std::function<void()> action;
	};
private:
	int size;
	std::string title;
	std::vector<struct MenuItem> items;
	static Menu* activeMenu;
	static bool running;
public:
	Menu();
	Menu(std::string t);
	~Menu();

	void addItem(std::string d, std::function<void()> a);
	void addChild(std::string d, Menu* m);
	void show();

	static void setActiveMenu(Menu* m);
	static void showActiveMenu();
	static void exitMenu();
	static bool isRunning();
};

#endif
