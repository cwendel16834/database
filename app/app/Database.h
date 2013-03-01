
#ifndef DATABASE_H
#define DATABASE_H

#ifdef DBDLL_EXPORTS
#define DBDLL_API __declspec(dllexport) 
#else
#define DBDLL_API __declspec(dllimport) 
#endif

#include<vector>
#include<string>
#include<iostream>

#include "Table.h"
#include "Record.h"
#include "Attribute.h"

using namespace std;

class DBDLL_API Database {
public:
	vector<Table> allTables;

	Database();		//Constructor function to create empty database
	~Database();	//Destructor
	int AddTable(Table _table, string _name); //Returns 0 if correct -1 if not
	int DropTable(string _name);	//Returns 0 if correct -1 if not
	vector<string> ListTables();	//prints a list of all table names in the database
	vector<Table> GetTables();	//returns all of the tables in the database
	Table Query(string _select, string _from, string _where);
	int Delete(string _select, string _from, string _where);	//Returns 0 if correct -1 if not
};

#endif