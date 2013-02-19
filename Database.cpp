#include "Database.h"
#include <string>

int Database::addTable(string name, Table* table)
{
	if( !tableMap.insert(pair<string, Table*>(name, table)).second)
		return 1;
	else
		return 0;
}

int Database::dropTable(string name)
{
	map<string, Table*>::iterator it;
	it=tableMap.find(name);
	tableMap.erase(it);
	if(it==tableMap.end())
		return 1;
	else
		return 0;
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
	vector<string> pieces;	

	stringstream ss(whereName);
	string piece;
	while(getline(ss, piece, ' '))
			pieces.push_back(piece);

	for(int i=0; i<pieces.size(); i++)
		cout << pieces[i] << endl;
	


	Table* table = new Table();
	return table;
}

int Database::deleteTuple(string select, Table* from, string whereName)
{
	return 0;
}

