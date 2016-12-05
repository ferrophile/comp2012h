#include "reportGenerator.h"

ReportGenerator::ReportGenerator() {}

ReportGenerator::ReportGenerator(std::string fn, std::string t)
: title(t), name(""), key("") {
	file.open(fn);
}

ReportGenerator::ReportGenerator(std::string fn, std::string t, std::string n, std::string k)
: title(t), name(n), key(k) {
	file.open(fn);
}

ReportGenerator::~ReportGenerator() {
	file.close();
}

bool ReportGenerator::isFileOpen() {
	return file.is_open();
}

void ReportGenerator::writeString(std::string str) {
	if (!isFileOpen()) return;
	file << str;
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
";
	if (name != "" && key != "") {
		header += ("<h2>" + title + ": " + name + " (" + key + ")</h2>\n");
	} else {
		header += ("<h2>" + title + "</h2>\n");
	}
	header += "\
<p>\n\
";
	file << header;
}

void ReportGenerator::writeHtmlFooter() {
	if (!isFileOpen()) return;
	std::string footer = "\
</p>\n\
</body>\n\
</html>\n\
";
	file << footer;
}

void ReportGenerator::writeTableHeader() {
	if (!isFileOpen()) return;
	std::string header = "<table cellSpacing=1 cellPadding=4 border=1>\n";
	file << header;
}

void ReportGenerator::writeTableFooter() {
	if (!isFileOpen()) return;
	std::string footer = "</table>\n";
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
