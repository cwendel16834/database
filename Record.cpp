#include "Record.h"

Record::Record() {

}

Record::Record(int numEntries) {
	entries = vector<string>(numEntries, "");
}

Record::~Record() {

}

int Record::updateEntry(int entryNum, string data) throw(invalid_argument) {
	if (entryNum >= entries.size() || entryNum < 0) {
		throw invalid_argument("ERROR: Entry index out of bounds!");
	}

	entries[entryNum] = data;
	return 0;
}

string Record::getEntry(int entryNum) throw(invalid_argument) {
	if (entryNum >= entries.size() || entryNum < 0) {
		throw invalid_argument("ERROR: Entry index out of bounds!");
	}

	return entries[entryNum];
}