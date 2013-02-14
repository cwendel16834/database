#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Record.h"

BOOST_AUTO_TEST_CASE(Test1)
{
	Table t1;
	BOOST_CHECK(t1.GetSize(t1)==0);
}

