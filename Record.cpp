#include "Record.h"

Record::Record() {

}

Record::Record(int numAttributes) {
	attributes = vector<string>(numAttributes, "");
}

Record::~Record() {

}

int Record::updateAttribute(int attributeNum, string data) throw(invalid_argument) {
	if (attributeNum >= attributes.size() || attributeNum < 0) {
		throw invalid_argument("ERROR: Attribute index out of bounds!");
	}

	attributes[attributeNum] = data;
	return 0;
}

string Record::getAttribute(int attributeNum) throw(invalid_argument) {
	if (attributeNum >= attributes.size() || attributeNum < 0) {
		throw invalid_argument("ERROR: Attribute index out of bounds!");
	}

	return attributes[attributeNum];
}