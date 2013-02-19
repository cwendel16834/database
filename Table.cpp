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

	int index = getAttributeIndex(oldName);
	if (index == -1) return 1;
	
	attributes[index].attributeName = newName;
	return 0;
}

Table& Table::join(Table& table) {
	Table joined = *(new Table());

	for (int i = 0; i < getAttributes().size(); i++) {
		joined.addAttribute(attributes[i]); // add attributes from this table
	}

	for (int i = 0; i < table.getAttributes().size(); i++) {
		joined.addAttribute(table.attributes[i]); // add attributes from given table
	}

	list<Record*>::iterator thisIterator = records.begin();
	while (thisIterator != records.end()) {
		Record thisRecord = **thisIterator;

		list<Record*>::iterator givenIterator = table.records.begin();
		while (givenIterator != table.records.end()) {
			Record givenRecord = **givenIterator;

			// join record from this table with a record from the given
			// table and insert this into the joined table
			joined.insertRecord(Record::joinRecords(thisRecord, givenRecord));
		}
	}

	return joined;
}

double Table::sum(string attrName) {
	double sum = 0;
	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1) 
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
	
	list<Record*>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (**it).getValue(attrIndex);
		if (value != "NULL") {
			double number = stod(value);
			sum += number;
		}
	}

	return sum;
}

int Table::count(string attrName) {
	double count = 0;
	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1) 
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
	
	list<Record*>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (**it).getValue(attrIndex);
		if (value != "NULL") {
			count++;
		}
	}

	return count;
}

string Table::min(string attrName) {
	string min;

	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1) 
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
	
	//start with min value = first Record's value
	min = records.front()->getValue(attrIndex);

	list<Record*>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (**it).getValue(attrIndex);
		if (value != "NULL" && value < min) {
			min = value;
		}
	}

	return min;
}

string Table::max(string attrName) {
	string max;

	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1) 
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
	
	//start with max value = first Record's value
	max = records.front()->getValue(attrIndex);

	list<Record*>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (**it).getValue(attrIndex);
		if (value != "NULL" && value > max) {
			max = value;
		}
	}

	return max;
}

int Table::getAttributeIndex(string attrName) {
	vector<Attribute>::iterator it = attributes.begin();
	int i = 0;
	while (it != attributes.end()) {
		if (it->attributeName == attrName) {			
			return i;
		}
		i++;
	}

	return -1;
}

Table::TableIterator Table::begin() {
	return records.begin();
}
Table::TableIterator Table::end() {
	return records.end();
}