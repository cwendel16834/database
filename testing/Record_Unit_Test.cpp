//uncomment if running only this test
//#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Record.h"

bool recordContainsEntry(Record& rec, string val) {
	//returns true if rec contains an entry with value val

	for (int i = 0; i < rec.GetNumEntries(); i++) {
		if (rec.GetEntry(i) == val) return true;
	}

	return false;
}

bool recordContainsEntries(Record& rec, vector<string> vals) {
	//returns true if rec contains an entry that matches every value in vals

	for (int i = 0; i < vals.size(); i++) {
		if ( !recordContainsEntry(rec, vals[i]) ) 
			return false;
	}

	return true;
}

//testing Record()

BOOST_AUTO_TEST_CASE(Constructor1)
{
	Record r1;

	BOOST_CHECK(r1.GetNumEntries() == 0);
}

//testing Record(vector<string>)

BOOST_AUTO_TEST_CASE(Constructor2)
{
	vector<string> values;
	values.push_back("john");

	Record r1(values);

	BOOST_CHECK(r1.GetNumEntries() == 1);
}

BOOST_AUTO_TEST_CASE(Constructor3)
{
	vector<string> values;
	values.push_back("john");

	Record r1(values);

	BOOST_CHECK(recordContainsEntry(r1, "john"));
}

BOOST_AUTO_TEST_CASE(Constructor4)
{
	vector<string> values;
	values.push_back("john");	
	values.push_back("smith");

	Record r1(values);

	BOOST_CHECK(recordContainsEntries(r1, values));
}

BOOST_AUTO_TEST_CASE(Constructor5)
{
	vector<string> values;
	values.push_back("john");	
	values.push_back("smith");

	Record r1(values);

	BOOST_CHECK(r1.GetNumEntries() == 2);
}

//testing InsertEntry(vector<string>)

BOOST_AUTO_TEST_CASE(InsertEntry1)
{
	vector<string> values;
	values.push_back("john");

	Record r1;
	r1.InsertEntry(values);

	BOOST_CHECK(r1.GetNumEntries() == 1);
}

BOOST_AUTO_TEST_CASE(InsertEntry2)
{
	vector<string> values;
	values.push_back("john");

	Record r1;
	r1.InsertEntry(values);

	BOOST_CHECK(recordContainsEntry(r1, "john"));
}

BOOST_AUTO_TEST_CASE(InsertEntry3)
{
	vector<string> values;
	values.push_back("john");	
	values.push_back("smith");

	Record r1;	
	r1.InsertEntry(values);

	BOOST_CHECK(r1.GetNumEntries() == 2);
}

BOOST_AUTO_TEST_CASE(InsertEntry4)
{
	vector<string> values;
	values.push_back("john");	
	values.push_back("smith");

	Record r1;	
	r1.InsertEntry(values);

	BOOST_CHECK(recordContainsEntries(r1, values));
}

//GetEntry(int) tested by previous tests

//testing ChangeEntry(int, string)

BOOST_AUTO_TEST_CASE(ChangeEntry1)
{
	vector<string> values;
	values.push_back("john");

	Record r1;	
	r1.InsertEntry(values);

	r1.ChangeEntry(0, "james");

	BOOST_CHECK(recordContainsEntry(r1, "james") && !recordContainsEntry(r1, "john"));
}

BOOST_AUTO_TEST_CASE(ChangeEntry2)
{
	vector<string> values;
	values.push_back("john");

	Record r1;	
	r1.InsertEntry(values);

	r1.ChangeEntry(0, "james");

	BOOST_CHECK(r1.GetNumEntries() == 1);
}

BOOST_AUTO_TEST_CASE(ChangeEntry3)
{
	vector<string> values;
	values.push_back("john");
	values.push_back("doe");

	Record r1;	
	r1.InsertEntry(values);

	r1.ChangeEntry(0, "james");

	BOOST_CHECK(recordContainsEntry(r1, "james") && !recordContainsEntry(r1, "john") && recordContainsEntry(r1, "doe"));
}

BOOST_AUTO_TEST_CASE(ChangeEntry4)
{
	vector<string> values;
	values.push_back("john");
	values.push_back("doe");

	Record r1;	
	r1.InsertEntry(values);

	r1.ChangeEntry(0, "james");

	BOOST_CHECK(r1.GetNumEntries() == 2);
}