//need accessor function in Record class
//where are the attribute values stored? in record or table?
//the Min and Max functions should return values not records. If they are returned as record, we need to have the index of the elements. Instead, they can just return min and max values.
//need print_attributes function


// main.cpp - BOOST TEST

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "Database.h"
#include "Record.h"
#include "Table.h"

// Database.h test cases

Database databaseTest;
Table* tableTest;
vector<string> listTables;
map<string, Table*> mapTables;

BOOST_AUTO_TEST_CASE(AddTableTest1)
{
	BOOST_CHECK(databaseTest.addTable("test1",NULL)==0);
}

BOOST_AUTO_TEST_CASE(AddTableTest2)
{
	BOOST_CHECK(databaseTest.addTable("test2",NULL)==1);
}

BOOST_AUTO_TEST_CASE(AddTableTest3)
{
	BOOST_CHECK(databaseTest.addTable("test3",NULL)==2);
}

BOOST_AUTO_TEST_CASE(AddTableTest4)
{
	BOOST_CHECK(databaseTest.addTable("test4",NULL)==0);
}

BOOST_AUTO_TEST_CASE(AddTableTest5)
{
	BOOST_CHECK(databaseTest.addTable("test5",NULL)==0);
}

BOOST_AUTO_TEST_CASE(DropTableTest1)
{
	BOOST_CHECK(databaseTest.dropTable("test1")==0);
}

BOOST_AUTO_TEST_CASE(DropTableTest2)
{
	BOOST_CHECK(databaseTest.dropTable("test2")==0);
}

BOOST_AUTO_TEST_CASE(DropTableTest3)
{
	BOOST_CHECK(databaseTest.dropTable("test3")==0);
}

BOOST_AUTO_TEST_CASE(DropTableTest4)
{
	BOOST_CHECK(databaseTest.dropTable("test4")==0);
}

BOOST_AUTO_TEST_CASE(DropTableTest5)
{
	BOOST_CHECK(databaseTest.dropTable("test5")==0);
}

BOOST_AUTO_TEST_CASE(ListTableTest1)
{
	BOOST_CHECK(databaseTest.listTable()==listTables);
}

BOOST_AUTO_TEST_CASE(GetTablesTest1)
{
	BOOST_CHECK(databaseTest.getTables()==mapTables);
}

BOOST_AUTO_TEST_CASE(QueryTest1)
{
	BOOST_CHECK(databaseTest.query("select_test1",tableTest,"where_test1")==tableTest);
}

BOOST_AUTO_TEST_CASE(QueryTest2)
{
	BOOST_CHECK(databaseTest.query("select_test2",tableTest,"where_test2")==tableTest);
}

BOOST_AUTO_TEST_CASE(QueryTest3)
{
	BOOST_CHECK(databaseTest.query("select_test3",tableTest,"where_test3")==tableTest);
}

BOOST_AUTO_TEST_CASE(QueryTest4)
{
	BOOST_CHECK(databaseTest.query("select_test4",tableTest,"where_test4")==tableTest);
}

BOOST_AUTO_TEST_CASE(QueryTest5)
{
	BOOST_CHECK(databaseTest.query("select_test5",tableTest,"where_test5")==tableTest);
}

BOOST_AUTO_TEST_CASE(DeleteTupleTest1)
{
	BOOST_CHECK(databaseTest.deleteTuple("select_test1",tableTest,"where_test1")==0);
}

BOOST_AUTO_TEST_CASE(DeleteTupleTest2)
{
	BOOST_CHECK(databaseTest.deleteTuple("select_test2",tableTest,"where_test2")==0);
}

BOOST_AUTO_TEST_CASE(DeleteTupleTest3)
{
	BOOST_CHECK(databaseTest.deleteTuple("select_test3",tableTest,"where_test3")==0);
}

BOOST_AUTO_TEST_CASE(DeleteTupleTest4)
{
	BOOST_CHECK(databaseTest.deleteTuple("select_test4",tableTest,"where_test4")==0);
}

BOOST_AUTO_TEST_CASE(DeleteTupleTest5)
{
	BOOST_CHECK(databaseTest.deleteTuple("select_test5",tableTest,"where_test5")==0);
}

// Table.h test cases

Attribute attributes[1];
Attribute name_attribute("Name", "string");
attributes[0]=name_attribute;

Table Table_test1(attributes);

Table Table_test2(attributes);
Attribute Table3_attributes[2];
Attribute date_attribute("Date", "Date");
Table3_attributes[1]=date_attribute;
Attribute age_attribute("Age", "int");
Table3_attributes[1]=age_attribute;
Table Table_test3(Table3_attributes);

Attribute Joined_table_attributes[3];
Joined_table_attributes[0]=name_attribute;
Joined_table_attributes[1]=date_attribute;
Joined_table_attributes[2]=age_attribute;
Table Table_test_joined(Joined_table_attributes);

BOOST_AUTO_TEST_CASE(AddAttributeTest1)
{
	Attribute Attribute_test("Age", "int");
	BOOST_CHECK(Table_test1.addAttribute(Attribute_test)==0);
}

BOOST_AUTO_TEST_CASE(AddAttributeTest2)
{
	Attribute Attribute_test("Date", "Date");
	BOOST_CHECK(Table_test1.addAttribute(Attribute_test)==0);
}

BOOST_AUTO_TEST_CASE(AddAttributeTest3)
{
	Attribute Attribute_test("Balance", "float");
	BOOST_CHECK(Table_test1.addAttribute(Attribute_test)==0);
}

BOOST_AUTO_TEST_CASE(DeleteAttributeTest1)
{
	Attribute Attribute_test("Name", "int");
	BOOST_CHECK(Table_test1.deleteAttribute(Attribute_test)==1);
}

BOOST_AUTO_TEST_CASE(DeleteAttributeTest2)
{
	Attribute Attribute_test("Date", "Date");
	BOOST_CHECK(Table_test1.deleteAttribute(Attribute_test)==0);
}


BOOST_AUTO_TEST_CASE(DeleteAttributeTest3)
{
	Attribute Attribute_test("Balance", "float");
	BOOST_CHECK(Table_test1.deleteAttribute(Attribute_test)==0);
}

BOOST_AUTO_TEST_CASE(DeleteAttributeTest4)
{
	Attribute Attribute_test("Age", "int");
	BOOST_CHECK(Table_test1.deleteAttribute(Attribute_test)==0);
}

BOOST_AUTO_TEST_CASE(InsertRecordTest1)
{
	Record Record_test(1);
	BOOST_CHECK(Table_test1.insertRecord(Record_test)==0);
}

BOOST_AUTO_TEST_CASE(InsertRecordTest2)
{
	Record Record_test(5);
	BOOST_CHECK(Table_test1.insertRecord(Record_test)==1);
}

BOOST_AUTO_TEST_CASE(InsertRecordTest3)
{
	Record Record_test(100);
	BOOST_CHECK(Table_test1.insertRecord(Record_test)==1);
}

BOOST_AUTO_TEST_CASE(GetAttributesTest1)
{
	vector<string> vector_test;
	vector_test.push_back("Name");
	BOOST_CHECK(Table_test1.getAttributes()==vector_test);
}

BOOST_AUTO_TEST_CASE(GetAttributesTest2)
{
	vector<string> vector_test;
	vector_test.push_back("Date");
	BOOST_CHECK(Table_test1.getAttributes()!=vector_test);
}

BOOST_AUTO_TEST_CASE(GetAttributesTest3)
{
	vector<string> vector_test;
	vector_test.push_back("Name");
	vector_test.push_back("Age");
	BOOST_CHECK(Table_test1.getAttributes()!=vector_test);
}

BOOST_AUTO_TEST_CASE(GetSizeTest1)
{
	BOOST_CHECK(Table_test1.getSize()!=100);
}

BOOST_AUTO_TEST_CASE(GetSizeTest2)
{
	BOOST_CHECK(Table_test1.getSize()==1);
}

BOOST_AUTO_TEST_CASE(RenameAttributeTest1)
{
	BOOST_CHECK(Table_test1.renameAttribute("Name", "new_Name")==0);
}

BOOST_AUTO_TEST_CASE(RenameAttributeTest2)
{
	BOOST_CHECK(Table_test1.renameAttribute("old", "new")==1);
}

BOOST_AUTO_TEST_CASE(RenameAttributeTest3)
{
	vector<int> test_vector;
	BOOST_CHECK(Table_test1.renameAttribute("old", test_vector)==1);
}

BOOST_AUTO_TEST_CASE(JoinTest1)
{
	BOOST_CHECK(Table_test2.join(Table_test3)==Table_test_joined);
}

BOOST_AUTO_TEST_CASE(JoinTest2)
{
	BOOST_CHECK(Table_test1.join(Table_test2)!=Table_test3);
}

BOOST_AUTO_TEST_CASE(JoinTest3)
{
	Table Table_join();
	BOOST_CHECK(Table_test1.join(Table_join)==Table_test1);
}

BOOST_AUTO_TEST_CASE(SumTest1)
{
	BOOST_CHECK(Table_test2.sum("Age")==20); //assuming the age is 20 for the only record in the table
}

BOOST_AUTO_TEST_CASE(SumTest2)
{
	BOOST_CHECK(Table_test2.sum("Name")!=100);
}

BOOST_AUTO_TEST_CASE(SumTest3)
{
	BOOST_CHECK(Table_test2.sum("Name")=="Bob"); //assuming the name is bob.
}

BOOST_AUTO_TEST_CASE(CountTest1)
{
	BOOST_CHECK(Table_test_joined.count("Name")==1);
}

BOOST_AUTO_TEST_CASE(CountTest2)
{
	BOOST_CHECK(Table_test_joined.count("Age")==1);
}

BOOST_AUTO_TEST_CASE(CountTest3)
{
	BOOST_CHECK(Table_test_joined.count("UIN")==0);
}

BOOST_AUTO_TEST_CASE(CountTest4)
{
	BOOST_CHECK(Table_test_joined.count("SSN")==0);
}


BOOST_AUTO_TEST_CASE(MinTest1)
{
	Record Record_test(3);
	BOOST_CHECK(Table_test1.min("Name")==Record_test);
}

BOOST_AUTO_TEST_CASE(MinTest2)
{
	Record Record_test(5);
	BOOST_CHECK(Table_test1.min("Name")!=Record_test);
}

BOOST_AUTO_TEST_CASE(MinTest3)
{
	Record Record_test(5);
	BOOST_CHECK(Table_test1.min("Date")!=Record_test);
}

BOOST_AUTO_TEST_CASE(MaxTest1)
{
	Record Record_test(3);
	BOOST_CHECK(Table_test1.max("Name")==Record_test);
}

BOOST_AUTO_TEST_CASE(MaxTest2)
{
	Record Record_test(5);
	BOOST_CHECK(Table_test1.max("Name")!=Record_test);
}

BOOST_AUTO_TEST_CASE(MaxTest3)
{
	Record Record_test(5);
	BOOST_CHECK(Table_test1.max("Date")!=Record_test);
}


// Record.h test cases
Record Record_test(1);
int numAttributes = 1;

BOOST_AUTO_TEST_CASE(UpdateAttributeTest1)
{
	//Attributes are based on a 0 index, so a Record with a single attribute can be
	//updated with Record_test.update(0, "name of attribute")
	BOOST_CHECK(Record_test.updateAttribute(numAttributes, "data_type1")==0); //numAttributes of the Record class
}

BOOST_AUTO_TEST_CASE(UpdateAttributeTest2)
{
	//See above comment ^^
	BOOST_CHECK(Record_test.updateAttribute(numAttributes, "data_type2")==0);
}

BOOST_AUTO_TEST_CASE(UpdateAttributeTest3)
{
	//Why should this return 1? 
	BOOST_CHECK(Record_test.updateAttribute(numAttributes, "123")==1);
}

BOOST_AUTO_TEST_CASE(GetAttributeTest1)
{
	//I don't understand where the literal "column[0]" came from
	BOOST_CHECK(Record_test.getAttribute(0)=="column[0]");
}

BOOST_AUTO_TEST_CASE(GetAttributeTest2)
{
	//this expected data value does not make sense
	BOOST_CHECK(Record_test.getAttribute(numAttributes-1)=="column[numAttributes-1]");
}

BOOST_AUTO_TEST_CASE(GetAttributeTest3)
{
	//this will now throw an invalid_argument exception. Try catching that
	BOOST_CHECK(Record_test.getAttribute(numAttributes)=="The column doesn't exist");
}

BOOST_AUTO_TEST_CASE(GetAttributeTest4)
{
	//this will now throw an invalid_argument exception. Try catching that
	BOOST_CHECK(Record_test.getAttribute(numAttributes+100)=="The column doesn't exist");
}

