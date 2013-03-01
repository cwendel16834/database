#ifndef RECORD_H
#define RECORD_H



#include<vector>
#include<string>
#include<iostream>
#include<iterator>
#include "Attribute.h"

using namespace std;

class Record {
public:
	vector<string> tuple;

	//Ordered set of strings (must all be strings regardless of item) can be done as char arrays
	Record();	//Constructor to create an arbitrary number of entries
	~Record();	//Destructor

	Record(vector<string> _newTuple);	

	string GetEntry(int _entryNumber);	//Accessor that allows access to individual entry in record
	int ChangeEntry(int _entryNumber, string _newString);		//Returns 0 if correct -1 if not
	int InsertEntry(vector<string> NewEntry);
	int GetNumEntries(); // Gets the number of entries in this Record
};

#endif