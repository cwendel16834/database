#ifndef TABLE_H
#define TABLE_H
#include "Record.h"
#include <vector>
using namespace std;

struct Entry
{
  string entryName;
  string entryType;
  Entry(string n, string t): entryName(n), entryType(t) {};
  
};

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
    
    Table(); 
    Table(Entry entries[]);
    int addEntry(Entry newEntry);
    int deleteEntry(Entry oldEntry);
    int insertRecord(Record newRecord);
    vector<string> getAttributes();
    int getSize();
	int renameAttribute(string oldName, string newName);
	Table& join(Table& table);
	double sum(string attrName);
	int count(string attrName);
	Record& min(string attrName);
	Record& max(string attrName);

private:

};

#endif
