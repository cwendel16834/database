#include "Database.h"

int Database::addTable(string name, Table* table)
{
	return 0;
}

int Database::dropTable(string name)
{
	return 0;
}

vector<string>& Database::listTable()
{
	vector<string> tables;
	return tables;
}

map<string, Table*>& Database::getTables()
{
	map<string, Table*> tables;
	return tables;
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

