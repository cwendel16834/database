#include "Record.h"

int Record::currentKey = 0;
/*constructor for key with new current key and with a vector of values if 
desired*/
Record::Record() {
 key = Record::currentKey++;
}

Record::Record(int numValues) {
 values = vector<string>(numValues, "");
 key = Record::currentKey++;
}
/*destructor*/
Record::~Record() {
}
/*update a value for a record */
int Record::updateValue(int valueNum, string data) throw(invalid_argument) {
 if (valueNum >= values.size() || valueNum < 0) {
 throw invalid_argument("ERROR: Value index out of bounds!");
 }
 values[valueNum] = data;
 return 0;
}
/*get a value for a record at a specific index */
string Record::getValue(int valueNum) throw(invalid_argument) {
 if (valueNum >= values.size() || valueNum < 0) {
 throw invalid_argument("ERROR: Value index out of bounds!");
 }
 return values[valueNum];
}
/*add value to the record*/
void Record::addValue(string value) {
 values.push_back(value);
}
/*return the number of values for the record*/
int Record::getNumValues() {
 return values.size();
}
/*make a record with the combined data from two given records*/
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
