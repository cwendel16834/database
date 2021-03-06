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

struct Attribute{
 string attributeName;
 string attributeType;
 Attribute(string n="", string t=""): attributeName(n), attributeType(t) {};
 };

class DATABASE_API Table {
public:    
    Table(); 
    Table(vector<Attribute> attr);

    int addAttribute(Attribute newAttribute);
    int deleteAttribute(Attribute oldAttribute);
    vector<string> getAttributes();
	Attribute getAttribute(string attrName);
	int renameAttribute(string oldName, string newName);

    int insertRecord(Record newRecord);
	
	int getKey(Record rec);
    int getSize();
	Table join(Table& table);

	double sum(string attrName);
	int count(string attrName);
	string min(string attrName);
	string max(string attrName);

	typedef  list<Record>::iterator TableIterator;
	TableIterator begin();
	TableIterator end();

	
	bool containsRecord(Record record);
	void removeRecord(Record delRecord);	
	int getAttributeIndex(string attrName);	
	bool checkRow(Record rec, vector<string> cond);
	
private:
	list<Record> records; // List containing  all of the Records in the table
	vector<Attribute> attributes; // Vector of all attribute columns of this Table
};

#endif
