#ifndef TABLE_H
#define TABLE_H


#include<vector>
#include<string>
#include<iostream>
#include "Attribute.h"
#include "Record.h"

using namespace std;

class Table {
public:
	string name;
	vector<Attribute> attributeList;
	vector<Record> set;

	Table(); //Constructor function to create empty table
	~Table();	//Destructor
	Table(vector<string> _attributeName, vector<string> _attributeType);	//Other constructor that takes a list of attribute names and types
	void Add(string _name, string _type);	//takes a single attribute name and type and adds a new *column* to the end of the table the other rows should get NULL for this column
	int Delete(string _name);	//takes and attribute name and deletes it from the table
	int Insert(Record _record);	//takes a record and adds it to the table
	vector<Attribute> GetAttributes();	//returns a list of the attributes and types for that table
	//cw changed Attributes to Attribute
	int GetSize();	//returns the number of records in the table
	int Rename(string _oldName, string _newName);	//takes two names, replaces the name for the attribute given by the first name with the second one
	Table CrossJoin(Table _table1, Table _table2);	//Cross join command that takes two tables as input and produces one table as output

	int Sum(string _attribute);	//Routines that calculate the: sum, count(only non-NULL entries), min and max
	int Count(string _attribute);
	int Min(string _attribute);
	int Max(string _attribute);
	typedef Record * iterator; 

	
};

#endif