#ifndef RECORD_H
#define RECORD_H
#include <string>

using namespace std;

class Record {

public:
	Record(int numEntries);

	int updateEntry(int entryNum, std::string data);
	string getEntry(int entryNum);

private:
	int numEntries;
	string entries[];

};

#endif