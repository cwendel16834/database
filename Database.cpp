#include "Database.h"
#include <string>
#include <map>

//helpers

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

//queryII helpers

bool evalComparison(string value, string type, string op, string lit) {

	if (type == "int" || type == "double") {
		double valueNum = stod(value);
		double litNum = stod(lit);

		if (op == "=") return valueNum == litNum;
		else if (op == "!=") return valueNum != litNum;
		else if (op == "<") return valueNum < litNum;
		else if (op == ">") return valueNum > litNum;
		else if (op == "<=") return valueNum <= litNum;
		else if (op == ">=") return valueNum >= litNum;
	}
	else { //handle varchars and dates as strings

		if (op == "=") return value == lit;
		else if (op == "!=") return value != lit;
		else if (op == "<") return value < lit;
		else if (op == ">") return value > lit;
		else if (op == "<=") return value <= lit;
		else if (op == ">=") return value >= lit;
	}
}

bool evalBool(bool lhs, string op, bool rhs) {
	if (op == "and") return lhs && rhs;
	else if (op == "or") return lhs || rhs;
}

bool Table::checkRow(Record rec, vector<string> cond) { //checks if the Record meets requirements listed in cond
	map<string, bool> bools; // used to hold labeled bool values representing evaluated parts of the expression
	vector<string> redux; // used to reduce expression by swapping parts of the expression for their evaluated values
	int count = 0;
	
	// find and evaluate comparisons (= != < > <= >=)
	for (int i = 0; i < cond.size(); i+=4) {
		string attr, op, lit;
		attr = cond[i];
		op = cond[i+1];
		lit = cond[i+2];
		
		string value = rec.getValue(getAttributeIndex(attr));
		Attribute attribute = getAttribute(attr);
		lit = removeQuotes(lit);

		//evaluate current expression
		bool evaluated = evalComparison(value, attribute.attributeType, op, lit);

		string label = "EXP" + count++;

		//insert labeled bool into map for later retrieval 
		bools.insert(pair<string, bool>(label, evaluated));

		//put label into reduced expression to locate bool value later
		redux.push_back(label);

		if( i+3 < cond.size()) {
			string boolOp = cond[i+3];
			redux.push_back(boolOp);
		}
	}

	//expression reduced to EXP#'s and boolean logic

	//loop to find and evaluate all 'and' operations
	for (int i = 1; i < redux.size(); ) {
		if (redux[i] == "and") {
			bool lhs, rhs, evaluated;
			string l, r, op;

			//load left and right labels and operation
			l = redux[i-1];
			op = redux[i];
			r = redux[i+1];

			//load evaluated bool values from map
			lhs = bools[l];
			rhs = bools[r];

			evaluated = evalBool(lhs, op, rhs);

			string label = "EXP" + count++;
			//store new evaluated value for later use
			bools.insert(pair<string, bool>(label, evaluated));

			//replace evaluated expression with label for result
			redux[i] = label;
			redux.erase(redux.begin()+i+1);	
			redux.erase(redux.begin()+i-1);			

		}
		else {
			//skip expression label and look at next operator
			i += 2;
		}
	}

	//loop to find and evaluate all 'or' operations
	for (int i = 1; i < redux.size(); ) {
		if (redux[i] == "or") {
			bool lhs, rhs, evaluated;
			string l, r, op;

			//load left and right labels and operation
			l = redux[i-1];
			op = redux[i];
			r = redux[i+1];

			//load evaluated bool values from map
			lhs = bools[l];
			rhs = bools[r];

			evaluated = evalBool(lhs, op, rhs);

			string label = "EXP" + count++;
			//store new evaluated value for later use
			bools.insert(pair<string, bool>(label, evaluated));

			//replace evaluated expression with label for result
			redux[i] = label;
			redux.erase(redux.begin()+i+1);	
			redux.erase(redux.begin()+i-1);			

		}
		else {
			//skip expression label and look at next operator
			i += 2;
		}
	}

	//last expression evaluated is the overall result
	bool result = bools["EXP" + count];
	
	return result;
}

Record selectValues(Record rec, vector<int> attrsIndex) { //returns a Record containing values for the attributes in attrs
	Record result;
	
	for(int i =0; i< attrsIndex.size(); i++)
	{
		result.addValue(rec.getValue(attrsIndex[i]));
	}
	
	return result;
}

vector<string> splitString(string str, char delim = ' ') { //splits str on each delim
	vector<string> result;
	stringstream ss(str);
	string piece;
	while(getline(ss, piece, ' '))
			result.push_back(piece);

	return result;
}

//Database Definitions

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

/*Table Database::query(string select, string from, string whereName)
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
	}

	return result;
}
*/
Table Database::query(string select, string from, string whereName) {
	Table fromTable, result;
	vector<int> attrSelIndex;

	//from
	map<string, Table>::iterator fromIt = tableMap.find(from);
	if (fromIt == tableMap.end()) {
		throw invalid_argument("ERROR: Invalid table name in from statment!");
	}
	fromTable = fromIt->second;

	//split select and where strings into components
	vector<string> attrSelected, whereCond;

	whereCond = splitString(whereName);
	whereCond = fixLiterals(whereCond);

	attrSelected = splitString(select);
	attrSelected = removeCommas(attrSelected);

	//fill in attributes in result table
	vector<string>::iterator vectIt = attrSelected.begin();
	while(vectIt != attrSelected.end()) {
		result.addAttribute(fromTable.getAttribute(*vectIt));
		vectIt++;
	}

	//iterate through table and select specified values for qualified rows
	Table::TableIterator it = fromTable.begin();
	while(it != fromTable.end()) {
		
		bool meetsReq = fromTable.checkRow(*it, whereCond);
		
		//if this Record meets the requirements in the where clause, 
		//select the requested values
		for(int i=0; i<attrSelected.size();i++)
		{
			attrSelIndex.push_back(fromTable.getAttributeIndex(attrSelected[i]));
		}

		if (meetsReq) {
			Record selected = selectValues(*it, attrSelIndex);
			result.insertRecord(selected);
		}
		it++;
	}
	return result;
}

int Database::deleteTuple(string from, string whereName)
{
	Table fromTable;	

	//from
	map<string, Table>::iterator fromIt = tableMap.find(from);
	if (fromIt == tableMap.end()) {
		throw invalid_argument("ERROR: Invalid table name in from statment!");
	}
	fromTable = fromIt->second;

	//split select and where strings into components
	vector<string> whereCond;

	whereCond = splitString(whereName);
	whereCond = fixLiterals(whereCond);	
	
	//iterate through table and select specified values for qualified rows
	Table::TableIterator it = fromTable.begin();
	while(it != fromTable.end()) {
		
		bool meetsReq = fromTable.checkRow(*it, whereCond);
		
		//if this Record meets the requirements in the where clause, 
		//select the requested values		

		if (meetsReq) {
			fromTable.removeRecord(*it);			
		}
		it++;
	}
	tableMap.at(from)=fromTable;
	return 0;
}

