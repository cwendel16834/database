#include "Table.h"
#include <string>
/*constructors for empty table or table with specific attributes*/
Table::Table() {
}

Table::Table(vector<Attribute> attr) {
	attributes=attr;
}
/*add a new attribute to the table and give records NULL value for new 
attribute*/
int Table::addAttribute(Attribute newAttribute) {
 attributes.push_back(newAttribute);
 list<Record>::iterator recordIterator=records.begin();
 while(recordIterator != records.end()) {
 recordIterator->values.push_back("NULL");
 recordIterator++;
 }
 return 0;
}

/*delete an attribute and all record values associated with the attribute */
int Table::deleteAttribute(Attribute oldAttribute) {
 for(int i=0;i<attributes.size();i++){
 if(oldAttribute.attributeName==attributes[i].attributeName){
 
 if(oldAttribute.attributeType==attributes[i].attributeType){
 attributes.erase(attributes.begin()+i);
 
 list<Record>::iterator recordIterator=records.begin();
 while(recordIterator != records.end()) {
 recordIterator->values.erase(recordIterator->values.begin()+i);
 recordIterator++;
 }
 return 0;
 }
 }
 }
 return 1;
}
/*add a new record to the table*/
int Table::insertRecord(Record newRecord) {
 records.push_back(newRecord);
 return 0;
}
/*get the key for a record*/
int Table::getKey(Record rec){
 return rec.currentKey;
}
/*delete a record from the table*/
void Table::removeRecord(Record delRecord){
 list<Record>::iterator it = records.begin();
 while(it != records.end()) {
 if(delRecord.currentKey == getKey(*it)){
 records.erase(it);
 }
 it++;
 }
}
/*get a specific attribute from the table */
Attribute Table::getAttribute(string attrName) {
 int index = getAttributeIndex(attrName);
 return attributes[index];
}
/*return a vector of names for the attributes in the table */
vector<string> Table::getAttributes() {
 vector<string> att;
 for(int i=0; i<attributes.size(); i++){
 att.push_back(attributes[i].attributeName);
 }
 return att;
}
/*return the number of records in the table */
int Table::getSize() {
 return records.size();
}
/*change the name of an attribute in the table*/
int Table::renameAttribute(string oldName, string newName) {
 int index = getAttributeIndex(oldName);
 if (index == -1){
 return 1;
 }
 attributes[index].attributeName = newName;
 return 0;
}
/*join the records and attributes of this table and another specified table*/
Table Table::join(Table& table) {
 Table joined = *(new Table());
 /*add attributes from the current table*/
 for (int i = 0; i < getAttributes().size(); i++) {
 joined.addAttribute(attributes[i]); 
 }
 /*add attributes from the specified table */
 for (int i = 0; i < table.getAttributes().size(); i++) {
 joined.addAttribute(table.attributes[i]); 
 }
 /*join record from current table and record from given table
 add it into the joined table*/
 list<Record>::iterator thisIterator = records.begin();
 while (thisIterator != records.end()) {
 Record thisRecord = *thisIterator;
 list<Record>::iterator givenIterator = table.records.begin();
 while (givenIterator != table.records.end()) {
 Record givenRecord = *givenIterator;
 joined.insertRecord(Record::joinRecords(thisRecord, givenRecord));
 givenIterator++;
 }
 thisRecord++;
 }
 return joined;
}
/*return the sum of the values for a given attribute */
double Table::sum(string attrName) {
 double sum = 0;
 int attrIndex = getAttributeIndex(attrName);
 if (attrIndex == -1){
 throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
 }
 
 list<Record>::iterator it = records.begin();
 while (it != records.end()) {
 string value = (*it).getValue(attrIndex);
 if (value != "NULL") {
 double number = stod(value);
 sum += number;
 }
 it++;
 }
 return sum;
}
/*count the records that have a non null value for a given attribute*/
int Table::count(string attrName) {
 double count = 0;
 int attrIndex = getAttributeIndex(attrName);
 if (attrIndex == -1){
 throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
 }
 list<Record>::iterator it = records.begin();
 while (it != records.end()) {
 string value = (*it).getValue(attrIndex);
 if (value != "NULL") {
 count++;
 }
 it++;
 }
 return count;
}
/*find the name with the minimum value for a given record that isn't null*/
string Table::min(string attrName) {
 string min;
 int attrIndex = getAttributeIndex(attrName);
 if (attrIndex == -1){
 throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
 }
 
 min = records.front().getValue(attrIndex);
 list<Record>::iterator it = records.begin();
 while (it != records.end()) {
 string value = (*it).getValue(attrIndex);
 if (value != "NULL" && value < min) {
 min = value;
 }
 it++;
 }
 return min;
}
/*get name of the record with greatest value for a given attribute */
string Table::max(string attrName) {
 string max;
 int attrIndex = getAttributeIndex(attrName);
 if (attrIndex == -1){ 
 throw invalid_argument("ERROR: " + attrName + " is not a valid attribute name!");
 }
 max = records.front().getValue(attrIndex);
 list<Record>::iterator it = records.begin();
 while (it != records.end()) {
 string value = (*it).getValue(attrIndex);
 if (value != "NULL" && value > max) {
 max = value;
 }
 it++;
 }
 return max;
}
/*find the index for a given attribute */
int Table::getAttributeIndex(string attrName) {
 vector<Attribute>::iterator it = attributes.begin();
 int i = 0;
 while (it != attributes.end()) {
 if (it->attributeName == attrName) {
 return i;
 }
 i++;
 it++;
 }
 return -1;
}
/*iterators for Table*/
Table::TableIterator Table::begin() {
 return records.begin();
}

Table::TableIterator Table::end() {
 return records.end();
}
/*filter table attributes based on given operation */
Table Table::filter(string attr, string op, string lit) {
 TableIterator it = begin();
 while (it != end()) {
 Record rec = *it;
 string value = rec.getValue(getAttributeIndex(attr));
 //"100" < "96"
 // yyyy/mm/dd
 if (op == "=") {
 if (value != lit) {
 records.erase(it);
 }
 else it++;
 }else if (op == "!=") {
 if (value == lit) {
 records.erase(it);
 }
 else it++;
 }else if (op == "<") {
 if (value >= lit) {
 records.erase(it);
 }
 else it++;
 }else if (op == ">") {
 if (value <= lit) {
 records.erase(it);
 }
 else it++;
 }else if (op == "<=") {
 if (value > lit) {
 records.erase(it);
 }
 else it++;
 }else if (op == ">=") {
 if (value < lit) {
 records.erase(it);
 }
 else it++;
 }
 else {
 throw invalid_argument("ERROR: Invalid operation!");
 }
 }
}
/*check lists of attributes for equality in size, order and attributes*/
bool attrEqual(vector<Attribute> attr1, vector<Attribute> attr2) {
 if(attr1.size() != attr2.size()) return false;
 for(int i=0; i<attr1.size(); i++){
 if(attr1[i].attributeName != attr2[i].attributeName){
 return false;
 }
 if(attr1[i].attributeType != attr2[i].attributeType){
 return false;
 }
 }
 return true;
}
/*check to see if a specified record is in the table*/
bool Table::containsRecord(Record record) {
 TableIterator it = begin();
 while (it != end()) {
 if (it->key == record.key) {
 return true;
 }
 it++;
 }
 return false;
}
/*return union of two tables*/
Table Table::tableUnion(Table& t1, Table& t2) {
 Table result(t1.attributes);
 if (!attrEqual(t1.attributes, t2.attributes)) {
 throw invalid_argument("ERROR! Attributes do not match!");
 }
 TableIterator it1 = t1.begin();
 while (it1 != t1.end()) {
 Record rec = *it1;
 result.insertRecord(rec);
 it1++;
 }

 TableIterator it2 = t2.begin();
 while (it2 != t2.end()) {
 Record rec = *it2;
 if(!t1.containsRecord(rec)){
 result.insertRecord(rec);
 }
 it2++;
 }
 return result;
}
/*return intersect of two tables */
Table Table::tableIntersect(Table& t1, Table& t2) {
 Table result(t1.attributes);
 if (!attrEqual(t1.attributes, t2.attributes)) {
 throw invalid_argument("ERROR! Attributes do not match!");
 }

 TableIterator it1 = t1.begin();
 while (it1 != t1.end()) {
 Record rec = *it1;
 result.insertRecord(rec);
 if(t2.containsRecord(rec)){
 result.insertRecord(rec);
 }
 it1++;
 }
 return result;
}
