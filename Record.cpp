#include "Record.h"

Record::Record() {

}

Record::Record(int numEntries) {
	entries = vector<string>(numEntries, "");
}

Record::~Record() {

}

int Record::updateEntry(int entryNum, string data) {
	if (entryNum >= entries.size() || entryNum < 0) {
		return 1;
	}

	entries[entryNum] = data;
	return 0;
}

string Record::getEntry(int entryNum) {
	if (entryNum >= entries.size() || entryNum < 0) {
		return "";
	}

	return entries[entryNum];
}