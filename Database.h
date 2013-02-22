#ifdef DATABASE_EXPORTS
#define DATABASE_API __declspec(dllexport) 
#else
#define DATABASE_API __declspec(dllimport) 
#endif

#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>
#include "Table.h"

using namespace std;

class DATABASE_API Database
{
public:	
	Database(){}
	int addTable(string name, Table table);
	int dropTable(string name);
	vector<string>& listTable();
	map<string, Table>& getTables();
	//Table query(string select, string from, string whereName);
	Table query(string select, string from, string whereName);
	int deleteTuple(string from, string whereName);
	
	
private:
	map<string, Table> tableMap;
	
};

#endif


