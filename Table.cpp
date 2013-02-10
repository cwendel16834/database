#include "Table.h"

Table::Table() {

}
Table::Table(Entry entries[]) {

}
int Table::addEntry(Entry newEntry) {
	return 0;
}
int Table::deleteEntry(Entry oldEntry) {
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
	return 0;
}
int Table::renameAttribute(string oldName, string newName) {
	return 0;
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
Record& Table::min(string attrName) {
	Record record(0);
	return record;
}
Record& Table::max(string attrName) {
	Record record(0);
	return record;
}