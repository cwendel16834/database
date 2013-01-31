#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <map>
#include <vector>
#include "Table.h"

using namespace std;

class Database
{
public:	
	Database(){}
	void addTable(string name, Table* table);
	void dropTable(string name);
	vector <string> listTable();
	map<string, Table*> getTables();
	Table* query(string select, Table* from, string where);
	void deleteTuple(string select, Table* from, string where);
	
	
private:
	map<string, Table*> tableMap;
	
};

#endif


