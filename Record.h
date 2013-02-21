//   devs:   this depends on project name: YOURPROJECTNAME_EXPORTS, or just add to your project's preprocessor definitions
//clients:   ignore ^^
#ifdef DATABASE_EXPORTS 
#define DATABASE_API __declspec(dllexport) 
#else
#define DATABASE_API __declspec(dllimport) 
#endif

#ifndef RECORD_H
#define RECORD_H
#include <vector>

using namespace std;

class Table;

class DATABASE_API Record {

public:
	Record(); //Creates a Record object with no values
	Record(int numValues); //Creates a Record object with numValues values
	~Record(); 
	int updateValue(int valueNum, string value) throw(invalid_argument) ; //Updates value at position valueNum to value given in data
	string getValue(int valueNum) throw(invalid_argument); //Gets the value data at position valueNum
	void addValue(string value); //Adds another space for a value value at the end of the Record
	int getNumValues(); //Gets the number of values in this Record

	static Record joinRecords(Record& rec1, Record& rec2);

	friend class Table;

private:
	vector<string> values;
	int key;

	static int currentKey;
};

#endif