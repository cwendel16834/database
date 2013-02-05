#ifndef TABLE_H
#define TABLE_H
#include "Record.h"

using namespace std;

class Table {
public:
	class TableIterator {
	public:
		TableIterator();
		TableIterator(const TableIterator& it);
		TableIterator& operator++();
		TableIterator& operator++(int);
		bool operator==(const TableIterator& rhs);
		bool operator!=(const TableIterator& rhs);
		Record& operator*();
	};

	int renameAttribute(string oldName, string newName);
	Table& join(Table& table);
	double sum(string attrName);
	int count(string attrName);
	Record& min(string attrName);
	Record& max(string attrName);

private:

};

#endif