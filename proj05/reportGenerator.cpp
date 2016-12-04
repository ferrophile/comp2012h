#include "reportGenerator.h"

ReportGenerator::ReportGenerator() {}

ReportGenerator::ReportGenerator(std::string fn, std::string t)
: title(t) {
	file.open(fn);
}

ReportGenerator::~ReportGenerator() {
	file.close();
}

bool ReportGenerator::isFileOpen() {
	return file.is_open();
}

void ReportGenerator::writeHtmlHeader() {
	if (!isFileOpen()) return;
	std::string header = "\
<html>\n\
<head>\n\
<title>" + title + "</title>\n\
</head>\n\
<body>\n\
<h1>HKUST Course Registration System</h1>\n\
<h2>" + title + "</h2>\n\
<p>\n\
<table cellSpacing=1 cellPadding=4 border=1>\n\
";
	file << header;
}

void ReportGenerator::writeHtmlFooter() {
	if (!isFileOpen()) return;
	std::string footer = "\
</table>\n\
</p>\n\
</body>\n\
</html>\n\
";
	file << footer;
}

void ReportGenerator::writeTableRow(std::vector<std::string> cells, bool isHeader) {
	std::vector<std::string>::iterator itr;

	std::string tag = isHeader ? "th" : "td";

	file << "<tr>\n";
	for (itr = cells.begin(); itr != cells.end(); itr++) {
		file << "<" << tag << ">" << *itr << "</" << tag << ">\n";
	}
	file << "</tr>\n";
}
