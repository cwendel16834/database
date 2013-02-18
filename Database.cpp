#include "Database.h"

int Database::addTable(string name, Table* table)
{
	if( !tableMap.insert(pair<string, Table*>(name, table)).second)
		return 0;
	else
		return 1;
}

int Database::dropTable(string name)
{
	map<string, Table*>::iterator it;
	it=tableMap.find(name);
	tableMap.erase(it);
	if(it==tableMap.end())
		return 0;
	else
		return 1;
}

vector<string>& Database::listTable()
{
	vector<string> tableNames;
	map<string, Table*>::iterator it;
	for(it = tableMap.begin(); it != tableMap.end(); ++it)
		tableNames.push_back(it->first);

	return tableNames;
}

map<string, Table*>& Database::getTables()
{
	map<string, Table*> result;
	result=tableMap;
	return result;
}

Table* Database::query(string select, Table* from, string whereName)
{
	Table* table;
	return table;
}

int Database::deleteTuple(string select, Table* from, string whereName)
{
	return 0;
}

