#include "Record.h"

int Record::currentKey = 0;

//constructor, key is unique value for each record
Record::Record() {
	key = Record::currentKey++;
}

Record::Record(int numValues) {
	values = vector<string>(numValues, "");
	key = Record::currentKey++;
}

Record::Record(vector<string> values) {
	this->values = values;
}

Record::~Record() {

}

int Record::updateValue(int valueNum, string data) throw(invalid_argument) {
	if (valueNum >= values.size() || valueNum < 0) {
		throw invalid_argument("ERROR: Value index out of bounds!");
	}

	values[valueNum] = data;
	return 0;
}

string Record::getValue(int valueNum) throw(invalid_argument) {
	if (valueNum >= values.size() || valueNum < 0) {
		throw invalid_argument("ERROR: Value index out of bounds!");
	}

	return values[valueNum];
}

void Record::addValue(string value) {
	values.push_back(value);
}

int Record::getNumValues() {
	return values.size();
}

Record Record::joinRecords(Record& rec1, Record& rec2) {
	Record joinedRecord;

	for( int i = 0; i < rec1.getNumValues(); i++) {
		joinedRecord.addValue(rec1.getValue(i));
	}

	for( int i = 0; i < rec2.getNumValues(); i++) {
		joinedRecord.addValue(rec2.getValue(i));
	}

	return joinedRecord;
}

//overloads "==" operator, uses the keys of a record for comparison
bool Record::operator==(const Record& a)
{
	if(currentKey==a.currentKey)
		return true;
	else
		return false;
}