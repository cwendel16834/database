#include "Database.h"
#include <string>
#include <map>

vector<string> fixLiterals(vector<string> input) {
	vector<string> result;
	string merge = "";
	bool merging = false;

	vector<string>::iterator it = input.begin();
	while (it != input.end()) {
		string item = *it;
		if (merging) {
			merge += " " + item;

			if (item[item.size()-1] == '\'') {
				merging = false;
				result.push_back(merge);
			}
		}
		else {

			if (item[0] == '\'') {
				merge = item;
				merging = true;
			}
			else {
				result.push_back(item);
			}
		}
		it++;
	}

	return result;
}

vector<string> removeCommas(vector<string> input) {
	vector<string>::iterator it = input.begin();
	while (it != input.end()) { 
		string item = *it;
		if (item[item.size()-1] == ',') {
			item = item.substr(0, item.size()-1);
		}
		it++;
	}
	return input;
}

string removeQuotes(string input) {
	if (input[0] == '\'') {
		input = input.substr(1, input.size()-1);
	}

	if (input[input.size()-1] == '\'') {
		input = input.substr(0, input.size()-1);
	}

	return input;
}

int Database::addTable(string name, Table table)
{
	if( !tableMap.insert(pair<string, Table>(name, table)).second)
		return 1;
	else
		return 0;
}

int Database::dropTable(string name)
{
	map<string, Table>::iterator it;
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
	map<string, Table>::iterator it;
	for(it = tableMap.begin(); it != tableMap.end(); ++it)
		tableNames.push_back(it->first);

	return tableNames;
}

map<string, Table>& Database::getTables()
{
	map<string, Table> result;
	result=tableMap;
	return result;
}

Table Database::query(string select, string from, string whereName)
{
	//from
	map<string, Table>::iterator fromIt = tableMap.find(from);
	if (fromIt == tableMap.end()) {
		throw invalid_argument("ERROR: Invalid table name in from statment!");
	}
	Table fromTable = fromIt->second;

	//where
	vector<string> pieces, redux;
	map<string, Table> tables;
	int count = 0;

	stringstream ss(whereName);
	string piece;
	while(getline(ss, piece, ' '))
			pieces.push_back(piece);

	pieces = fixLiterals(pieces);

	for (int i = 0; i < pieces.size(); i+=4) {
		string attr, op, lit;
		attr = pieces[i];
		op = pieces[i+1];
		lit = pieces[i+2];

		lit = removeQuotes(lit);

		fromTable.filter(attr, op, lit);
		string label = "EXP" + count++;
		tables.insert(pair<string, Table>(label, fromTable));
		redux.push_back(label);

		if( i+3 < pieces.size()) {
			string boolOp = pieces[i+3];
			redux.push_back(boolOp);
		}
	}

	//and loop
	for (int i = 1; i < redux.size(); ) {
		if (redux[i] == "and") {
			Table lhs, rhs, intersectedTable;
			lhs = tables[redux[i-1]];
			rhs = tables[redux[i+1]];

			intersectedTable = Table::tableIntersect(lhs, rhs);
			string label = "EXP" + count++;
			tables.insert(pair<string, Table>(label, intersectedTable));

			redux[i] = label;
			redux.erase(redux.begin());			

		}
		else {
			i += 2;
		}
	}

	//or loop
	for (int i = 1; i < redux.size(); ) {
		if (redux[i] == "or") {
			Table lhs, rhs, unionedTable;
			lhs = tables[redux[i-1]];
			rhs = tables[redux[i+1]];

			unionedTable = Table::tableUnion(lhs, rhs);
			string label = "EXP" + count++;
			tables.insert(pair<string, Table>(label, unionedTable));

			redux[i] = label;
			redux.erase(redux.begin());			

		}
		else {
			i += 2;
		}
	}

	Table filteredTable = tables["EXP" + count];

	
	Table result;
	//select
	vector<string> selectPieces;
	stringstream ss2(select);
	while(getline(ss2, piece, ' '))
			selectPieces.push_back(piece);
	selectPieces = removeCommas(selectPieces);

	vector<string>::iterator it = selectPieces.begin();

	//fill in attributes
	while(it != selectPieces.end()) {
		result.addAttribute(filteredTable.getAttribute(*it));
		it++;
	}

	//fill in Records with selected columns
	Table::TableIterator tableIt = filteredTable.begin();
	while(tableIt != filteredTable.end()) {
		Record rec = *tableIt;
		Record newRec;
		it = selectPieces.begin();
		while (it != selectPieces.end()) {
			int index = filteredTable.getAttributeIndex(*it);
			newRec.addValue(rec.getValue(index));
		}
		result.insertRecord(newRec);
		tableIt++;
	}

	return result;
}

int Database::deleteTuple(string select, string from, string whereName)
{
	return 0;
}

