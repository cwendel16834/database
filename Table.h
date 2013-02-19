#ifdef DATABASE_EXPORTS
#define DATABASE_API __declspec(dllexport) 
#else
#define DATABASE_API __declspec(dllimport) 
#endif

#ifndef TABLE_H
#define TABLE_H
#include "Record.h"
#include <list>
#include <vector>
using namespace std;



class DATABASE_API Table {
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
	
	struct Attribute
	{
		string attributeName;
		string attributeType;
		Attribute(string n="", string t=""): attributeName(n), attributeType(t) {};
  
	};
    
    Table(); 
    Table(vector<Attribute> attributes);

    int addAttribute(Attribute newAttribute);
    int deleteAttribute(Attribute oldAttribute);
    vector<string> getAttributes();
	int renameAttribute(string oldName, string newName);

    int insertRecord(Record newRecord);
    int getSize();
	Table& join(Table& table);

	double sum(string attrName);
	int count(string attrName);
	string min(string attrName);
	string max(string attrName);

private:
	list<Record*> records; // List containing pointers to all of the Records in the table
	vector<Attribute> attributes; // Vector of all attribute columns of this Table

	int getAttributeIndex(string attrName);
};

#endif
