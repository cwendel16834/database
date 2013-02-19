#include "Table.h"
#include <string>

Table::Table() {

}
Table::Table(vector<Attribute> attributes) {

}
int Table::addAttribute(Attribute newAttribute) {
	return 0;
}
int Table::deleteAttribute(Attribute oldAttribute) {
	return 0;
}
int Table::insertRecord(Record newRecord) {
	return 0;
}
vector<string> Table::getAttributes() {
	vector<string> att;
	return att;
}
int Table::getSize() {
	return records.size();
}
int Table::renameAttribute(string oldName, string newName) {

	vector<Attribute>::iterator it = attributes.begin();

	while (it != attributes.end()) {
		if (it->attributeName == oldName) {
			it->attributeName = newName;
			return 0;
		}
	}

	return 1;
}
Table& Table::join(Table& table) {
	return *this;
}
double Table::sum(string attrName) {
	return 0;
}
int Table::count(string attrName) {
	return 0;
}
string Table::min(string attrName) {
	return "";
}
string Table::max(string attrName) {
	return "";
}