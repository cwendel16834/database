#include "Table.h"
#include <string>
#include <iostream>

Table::Table() {

}

Table::Table(vector<Attribute> attr) {
	attributes=attr;
}

int Table::addAttribute(Attribute newAttribute) {
    attributes.push_back(newAttribute);
    return 0;

}

int Table::deleteAttribute(Attribute oldAttribute) {
    for(int i=0;i<attributes.size();i++){
      if(oldAttribute.attributeName==attributes[i].attributeName)
      {
      if(oldAttribute.attributeType==attributes[i].attributeType)
      {
        attributes.erase(attributes.begin()+i);
        return 0;
      }
      }
    }
	return 1;
}

int Table::insertRecord(Record newRecord) {
    records.push_back(newRecord);
	return 0;
}
int Table::getKey(Record rec)
{
	return rec.currentKey;
}


void Table::removeRecord(Record delRecord)
{
	list<Record>::iterator tempIt;
	for( list<Record>::iterator it = records.begin(); it != records.end(); /*  */ ) {
		tempIt=it;
		if(delRecord == *it) {			
			records.erase(tempIt);	
			break;
		}
		else {
			++it;
		}
	}
	
}

Attribute Table::getAttribute(string attrName) {	
	int index = getAttributeIndex(attrName);	
	return attributes[index];
}

vector<string> Table::getAttributes() {
	vector<string> att;
	for(int i=0; i<attributes.size(); i++){
        att.push_back(attributes[i].attributeName);
	}
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

Table Table::join(Table& table) {
	Table joined = *(new Table());

	for (int i = 0; i < getAttributes().size(); i++) {
		joined.addAttribute(attributes[i]); // add attributes from this table
	}

	for (int i = 0; i < table.getAttributes().size(); i++) {
		joined.addAttribute(table.attributes[i]); // add attributes from given table
	}

	list<Record>::iterator thisIterator = records.begin();
	while (thisIterator != records.end()) {
		Record thisRecord = *thisIterator;

		list<Record>::iterator givenIterator = table.records.begin();
		while (givenIterator != table.records.end()) {
			Record givenRecord = *givenIterator;

			// join record from this table with a record from the given
			// table and insert this into the joined table
			joined.insertRecord(Record::joinRecords(thisRecord, givenRecord));
			givenIterator++;
		}
		thisIterator++;
	}

	return joined;
}

double Table::sum(string attrName) {
	double sum = 0;
	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1)
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");

	list<Record>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (*it).getValue(attrIndex);
		if (value != "NULL") {
			double number = stod(value);
			sum += number;
		}
	it++;
	}

	return sum;
}

int Table::count(string attrName) {
	double count = 0;
	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1)
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");

	list<Record>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (*it).getValue(attrIndex);
		if (value != "NULL") {
			count++;
		}
	it++;
	}

	return count;
}

string Table::min(string attrName) {
	string min;

	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1)
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");

	//start with min value = first Record's value
	min = records.front().getValue(attrIndex);

	list<Record>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (*it).getValue(attrIndex);
		if (value != "NULL" && value < min) {
			min = value;
		}
	it++;
	}

	return min;
}

string Table::max(string attrName) {
	string max;

	int attrIndex = getAttributeIndex(attrName);
	if (attrIndex == -1)
		throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");

	//start with max value = first Record's value
	max = records.front().getValue(attrIndex);

	list<Record>::iterator it = records.begin();
	while (it != records.end()) {
		string value = (*it).getValue(attrIndex);
		if (value != "NULL" && value > max) {
			max = value;
		}
	it++;
	}

	return max;
}

int Table::getAttributeIndex(string attrName) {
	for(int i = 0; i < attributes.size(); i++)
	{
		if(attributes[i].attributeName == attrName)
			return i;
	}

	return -1;
}

Table::TableIterator Table::begin() {
	return records.begin();
}

Table::TableIterator Table::end() {
	return records.end();
}

bool Table::containsRecord(Record record) {
	TableIterator it = begin();
	while (it != end()) {
		if (it->key == record.key) {
			return true;
		}
	it++;
	}

	return false;
}
