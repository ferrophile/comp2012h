/*
 * COMP2012H Project 5
 * Hong Wing PANG 20315504
 * fileManager.cpp
 */

//FileManager class

#include "fileManager.h"

//Default constructor
FileManager::FileManager() {}

//Constructor initializing the filename
FileManager::FileManager(std::string fn) : name(fn) {}

//Destructor
FileManager::~FileManager() {
	if(this->isFileOpen())
		file.close();
}

//Sets file as output mode
void FileManager::openOutFile() {
	file.open(name, std::fstream::out);
}

//Sets file as input mode
void FileManager::openInFile() {
	file.open(name, std::fstream::in);
}

//Check if file is open
bool FileManager::isFileOpen() {
	return file.is_open();
}

/*
 *Output functions
 */

//Write an integer (0-255) as hex form, 2 characters
void FileManager::writeInt(int i) {
	i = (i > 255) ? 255 : i;
	file << std::hex << std::setw(2) << std::setfill('0') << i;
}

//Write a string in hex form ASCII code
void FileManager::writeString(std::string str) {
	int len = str.length();
	for (int i=0; i < len; i++) {
		writeInt(int(str[i]));
	}
}

/*
 *Input functions
 */

//Convert char (0-F) to int value for parsing
int FileManager::charToHex(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	else
		throw READ_ERROR;
}

//Read a number (0-255) from the file
int FileManager::readNum(int maxVal) {
	char c;
	int num = 0;

	if (file.eof()) throw READ_ERROR;
	file.get(c);
	num += charToHex(c)*16;

	if (file.eof()) throw READ_ERROR;
	file.get(c);
	num += charToHex(c);

	//max value (if not specified, set to 255) for checking validity of some parts of file
	if (num > maxVal) throw READ_ERROR;
	return num;
}

//Check value matches or not
void FileManager::checkValue(int val) {
	int num = readNum();
	if (num != val) throw READ_ERROR;
}

//Read string from file
std::string FileManager::readString(int len) {
	int temp;
	std::string str = "";

	for (int i=0; i<len; i++) {
		temp = readNum();
		if (temp < 0 || temp > 127) throw READ_ERROR;
		str += (char)temp;
	}
	return str;
}
