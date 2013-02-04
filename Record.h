#ifndef RECORD_H
#define RECORD_H

class Record {

public:
	Record(int numEntries);

	int updateEntry(int entryNum, string data);
	string getEntry(int entryNum);

private:
	int numEntries;
	string entries[];

};

#endif