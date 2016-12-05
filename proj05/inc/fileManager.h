/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * fileManager.h
 */

#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#define READ_ERROR "Load Error!"

class FileManager {
private:
	std::string name;
	std::fstream file;
public:
	FileManager();
	FileManager(std::string);
	~FileManager();

	void openOutFile();
	void openInFile();
	bool isFileOpen();

	void writeInt(int i);
	void writeString(std::string str);

	int charToHex(char c); 
	int readNum(int maxVal = 0xFF);
	void checkValue(int val);
	std::string readString(int len);
};

#endif
