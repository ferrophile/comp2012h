/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * readme.txt
 */

The project consists of the below files:

main.cpp
Entry point.

menu.cpp / menu.h
A menu system that I developed for this project. Each menu item is linked to either another menu or a function, the latter implemented via std::bind and std::function.

register.cpp / register.h
The main part of the system, which provides a hell lot of callback functions for the menu actions. The register class has menus, the 4 hash tables and 1 doubly linked list, as well as the report generator and file manager (introduced below) as data members. The member functions then work on these data members to do work. A downside of this is that there is many repetitive code within the functions of this class making it quite bulky.

hashtable.h
The hash table implementation uses templates so that one class is used for all hash tables. There are two formal arguments, Key and Value, so that:
Student table - <int, Student>
Course table - <string, Course>
Student index - <int, Record iterator>
Course index - <string, Record iterator>

the keys are student ID (int) and course code (string); Student, Course and Record are classes that contains other values in each entry of the hash table.
iterators are used in place of pointers because I used std::list.

registerEntities.cpp / registerEntities.h
Student, Class and Record classes as mentioned above.

fileManager.cpp / fileManager.h
reportGenerator.cpp / reportGenerator.h
2 utility class that does what their name suggests.

Other notes:
the doubly linked list is done by std::list to save time.
Also the documentation and comments are incomplete because some parts are self explanatory and also I am only minutes from the deadline. Sorry =(