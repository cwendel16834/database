#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Database.h"

BOOST_AUTO_TEST_CASE(Test1)
{
	Database d1;
	BOOST_CHECK(d1.GetTables()==NULL);
}

BOOST_AUTO_TEST_CASE(Test2)
{
	Database d1;
	Table t1;
	d1.AddTable(t1,"test");
	BOOST_CHECK(t1==d1.GetTables());
}

BOOST_AUTO_TEST_CASE(Test3)
{
	Database d1;
	Table t1;
	d1.AddTable(t1,"test");
	d1.DropTable("test");
	BOOST_CHECK(d1.GetTables()==NULL);
}