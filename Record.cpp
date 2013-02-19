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