#include "Table.h"
#include <string>

Table::Table() {

}

Table::Table(vector<Attribute> attr) {
	attributes=attr;
}

int Table::addAttribute(Attribute newAttribute) {
    attributes.push_back(newAttribute);
   
    list<Record>::iterator recordIterator=records.begin();
    while(recordIterator != records.end()) {
          recordIterator->values.push_back("NULL");
          recordIterator++;
                         }
    return 0;

}

int Table::deleteAttribute(Attribute oldAttribute) {
    
    for(int i=0;i<attributes.size();i++){
      if(oldAttribute.attributeName==attributes[i].attributeName)
      {
      if(oldAttribute.attributeType==attributes[i].attributeType)
      {
        attributes.erase(attributes.begin()+i);
        list<Record>::iterator recordIterator=records.begin();
        while(recordIterator != records.end()) {
          recordIterator->values.erase(recordIterator->values.begin()+i);
          recordIterator++;
          }
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

Table::Attribute Table::getAttribute(string attrName) {
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
		}
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

Table Table::filter(string attr, string op, string lit) {

	TableIterator it = begin();
	while (true) {
		Record rec = *it;
		string value;
		//"100" < "96"
		// yyyy/mm/dd
		if (op == "=") {
			if (value != lit) {
				records.erase(it);
			}
			else it++;
		}
		else if (op == "!=") {
			if (value == lit) {
				records.erase(it);
			}
			else it++;
		}
		else if (op == "<") {
			if (value >= lit) {
				records.erase(it);
			}
			else it++;
		}
		else if (op == ">") {
			if (value <= lit) {
				records.erase(it);
			}
			else it++;
		}
		else if (op == "<=") {
			if (value > lit) {
				records.erase(it);
			}
			else it++;
		}
		else if (op == ">=") {
			if (value < lit) {
				records.erase(it);
			}
			else it++;
		}
		else {
			throw invalid_argument("ERROR: Invalid operation!");
		}
	}
}

bool attrEqual(vector<Table::Attribute> attr1, vector<Table::Attribute> attr2) {
	return true;
}

bool Table::containsRecord(Record record) {
	TableIterator it = begin();
	while (it != end()) {
		if (it->key == record.key) {
			return true;
		}
	}

	return false;
}

Table Table::tableUnion(Table& t1, Table& t2) {
	Table result(t1.attributes);
	if (!attrEqual(t1.attributes, t2.attributes)) {
		throw invalid_argument("ERROR! Attributes do not match!");
	}

	TableIterator it1 = t1.begin();
	while (it1 != t1.end()) {
		Record rec = *it1;
		result.insertRecord(rec);
	}

	TableIterator it2 = t2.begin();
	while (it2 != t2.end()) {
		Record rec = *it2;
		if(!t1.containsRecord(rec)){
			result.insertRecord(rec);
		}
	}

	return result;
}

Table Table::tableIntersect(Table& t1, Table& t2) {
	Table result(t1.attributes);
	if (!attrEqual(t1.attributes, t2.attributes)) {
		throw invalid_argument("ERROR! Attributes do not match!");
	}

	TableIterator it1 = t1.begin();
	while (it1 != t1.end()) {
		Record rec = *it1;
		result.insertRecord(rec);

		if(t2.containsRecord(rec)){
			result.insertRecord(rec);
		}
	}

	return result;
}
