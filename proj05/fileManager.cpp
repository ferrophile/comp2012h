#include "fileManager.h"

FileManager::FileManager() {}

FileManager::FileManager(std::string fn) : name(fn) {}

FileManager::~FileManager() {
	if(this->isFileOpen())
		file.close();
}

void FileManager::openOutFile() {
	file.open(name, std::fstream::out);
}

void FileManager::openInFile() {
	file.open(name, std::fstream::in);
}

bool FileManager::isFileOpen() {
	return file.is_open();
}

//Output functions

void FileManager::writeInt(int i) {
	i = (i > 255) ? 255 : i;
	file << std::hex << std::setw(2) << std::setfill('0') << i;
}

void FileManager::writeString(std::string str) {
	int len = str.length();
	for (int i=0; i < len; i++) {
		writeInt(int(str[i]));
	}
}

//Input functions

int FileManager::charToHex(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	else
		throw READ_ERROR;
}

int FileManager::readNum(int maxVal) {
	char c;
	int num = 0;

	if (file.eof()) throw READ_ERROR;
	file.get(c);
	num += charToHex(c)*16;

	if (file.eof()) throw READ_ERROR;
	file.get(c);
	num += charToHex(c);

	if (num > maxVal) throw READ_ERROR;
	return num;
}

void FileManager::checkValue(int val) {
	int num = readNum();
	if (num != val) throw READ_ERROR;
}

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
