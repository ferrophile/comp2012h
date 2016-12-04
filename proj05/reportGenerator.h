#ifndef _REPORTGENERATOR_H
#define _REPORTGENERATOR_H

#include <string>
#include <fstream>
#include <vector>
#include "hashTable.h"

class ReportGenerator {
private:
	std::string title;
	std::string name;
	std::string key;
	std::ofstream file;
public:
	ReportGenerator();
	ReportGenerator(std::string, std::string);
	~ReportGenerator();

	bool isFileOpen();
	void writeHtmlHeader();
	void writeHtmlFooter();
	void writeTableRow(std::vector<std::string>, bool isHeader = false);
};

#endif
