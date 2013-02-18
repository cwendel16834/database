#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>
#include "Table.h"

using namespace std;

class Database
{
public:	
	Database(){}
	int addTable(string name, Table* table);
	int dropTable(string name);
	vector<string>& listTable();
	map<string, Table*>& getTables();
	Table* query(string select, Table* from, string whereName);
	int deleteTuple(string select, Table* from, string whereName);
	
	
private:
	map<string, Table*> tableMap;
	
};

#endif


