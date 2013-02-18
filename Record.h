#ifndef RECORD_H
#define RECORD_H
#include <vector>

using namespace std;

class Record {

public:
	Record(); //Creates a Record object with 0 attributes
	Record(int numAttributes); //Creates a Record object with numAttributes attributes
	~Record(); 
	int updateAttribute(int attributeNum, string data) throw(invalid_argument) ; //Updates value at position attributeNum to value given in data
	string getAttribute(int attributeNum) throw(invalid_argument); //Gets the attribute data at position attributeNum
	int getNumAttributes(); //Gets the number of attributes in this Record

private:
	vector<string> attributes;
};

#endif