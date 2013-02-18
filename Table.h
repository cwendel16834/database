#ifndef TABLE_H
#define TABLE_H
#include "Record.h"
#include <list>
#include <vector>
using namespace std;

struct Attribute
{
  string attributeName;
  string attributeType;
  Attribute(string n="", string t=""): attributeName(n), attributeType(t) {};
  
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
    Table(Attribute attributes[]);
    int addAttribute(Attribute newAttribute);
    int deleteAttribute(Attribute oldAttribute);
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
	list<Record*> records; // List containing pointers to all of the Records in the table
	vector<Attribute> attributes; // Vector of all attribute columns of this Table
};

#endif
