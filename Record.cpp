#include "Record.h"

Record::Record() {

}

Record::Record(int numValues) {
	values = vector<string>(numValues, "");
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

void Record::addValue(string value="NULL") {
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