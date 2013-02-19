#ifndef RECORD_H
#define RECORD_H
#include <vector>

using namespace std;

class Record {

public:
	Record(); //Creates a Record object with no values
	Record(int numValues); //Creates a Record object with numValues values
	~Record(); 
	int updateValue(int valueNum, string value) throw(invalid_argument) ; //Updates value at position valueNum to value given in data
	string getValue(int valueNum) throw(invalid_argument); //Gets the value data at position valueNum
	void addValue(string value="NULL"); //Adds another space for a value value at the end of the Record
	int getNumValues(); //Gets the number of values in this Record

private:
	vector<string> values;
};

#endif