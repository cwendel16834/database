#ifndef RECORD_H
#define RECORD_H
#include <vector>

using namespace std;

class Record {

public:
	Record(); //Creates a Record object with 0 entries
	Record(int numEntries); //Creates a Record object with numEntries entries
	~Record(); 
	int updateEntry(int entryNum, string data); //Updates value at position entryNum to value given in data
	string getEntry(int entryNum); //Gets the entry data at position entryNum
	int getNumEntries(); //Gets the number of entries in this Record

private:
	vector<string> entries;

};

#endif