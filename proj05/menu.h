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
	std::vector<struct MenuItem> items;
	static Menu* activeMenu;
public:
	Menu();
	~Menu();

	void addItem(std::string d, std::function<void()> a);
	void show();

	static void setActiveMenu(Menu* m);
	static void showActiveMenu();
};

#endif
