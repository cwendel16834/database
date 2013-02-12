#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Database.h"

BOOST_AUTO_TEST_CASE(Test1)
{
	Database d1;
	Table t1 = d1.GetTables();
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test2)
{
	Database d1;
	Table t1;
	d1.AddTable(t1,"test");
	BOOST_CHECK(t1.GetSize(t1) == d1.GetTables().GetSize(t1));
}

BOOST_AUTO_TEST_CASE(Test3)
{
	Database d1;
	Table t1;
	d1.AddTable(t1,"test");
	d1.DropTable("test");
	BOOST_CHECK(d1.GetTables().GetSize(t1) == 0);
}

BOOST_AUTO_TEST_CASE(Test4)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	Attribute name;
	Attribute email;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);

	Table output = d1.Query("*",t1,"Name=Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));

}

BOOST_AUTO_TEST_CASE(Test5)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	Attribute name;
	Attribute email;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);

	Table answer;
	answer.Insert(r2);
	answer.Insert(r4);

	Table output = d1.Query("*",t1,"Email=test@test.com");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));

}

BOOST_AUTO_TEST_CASE(Test6)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);

	Table output = d1.Query("*",t1,"Name=Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));

}

BOOST_AUTO_TEST_CASE(Test7)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r2);
	answer.Insert(r4);

	Table output = d1.Query("*",t1,"Email=test@test.com");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));

}

BOOST_AUTO_TEST_CASE(Test8)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r5);
	answer.Insert(r6);

	Table output = d1.Query("SSN",t1,"SSN > 100");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));

}

BOOST_AUTO_TEST_CASE(Test9)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r6);

	Table output = d1.Query("SSN",t1,"SSN > 103");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test10)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r5);

	Table output = d1.Query("SSN",t1,"SSN != 106");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test11)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r2);

	Table output = d1.Query("Name",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test12)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r2);
	answer.Insert(r4);
	answer.Insert(r6);

	Table output = d1.Query("*",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test13)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r2);
	answer.Insert(r4);	

	Table output = d1.Query("Name SSN",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test14)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r5);
	answer.Insert(r6);

	Table output = d1.Query("SSN",t1,"SSN >= 101");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test15)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r6);	

	Table output = d1.Query("SSN",t1,"SSN >= 102");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test16)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r2);
	answer.Insert(r4);
	answer.Insert(r6);

	Table output = d1.Query("*",t1,"SSN >= 102");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test17)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;	
	answer.Insert(r2);	
	answer.Insert(r6);

	Table output = d1.Query("Name SSN",t1,"SSN >= 102");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test18)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r2);
	answer.Insert(r5);		
	answer.Insert(r6);

	Table output = d1.Query("Name SSN",t1,"SSN <= 106");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test19)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r2);	

	Table output = d1.Query("Name SSN",t1,"SSN < 106");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test20)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
		

	Table output = d1.Query("Name SSN",t1,"SSN < 100");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test21)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
		

	Table output = d1.Query("*",t1,"SSN < 100");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test22)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r2);	
	answer.Insert(r3);	
	answer.Insert(r4);	
	answer.Insert(r5);	
	answer.Insert(r6);	

	Table output = d1.Delete("*",t1,"SSN < 100");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test23)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;		

	Table output = d1.Delete("*",t1,"SSN < 107");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test24)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);
	answer.Insert(r6);

	Table output = d1.Delete("*",t1,"SSN = 106");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test25)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);
	answer.Insert(r6);

	Table output = d1.Delete("*",t1,"Name = Jane Smith");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test26)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);
	answer.Insert(r6);

	Table output = d1.Delete("*",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test27)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);
	answer.Insert(r4);
	answer.Insert(r5);
	answer.Insert(r6);

	Table output = d1.Delete("Name",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test28)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);
	answer.Insert(r4);
	answer.Insert(r5);	

	Table output = d1.Delete("Name SSN",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test29)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);	
	answer.Insert(r5);	

	Table output = d1.Delete("Name Email SSN",t1,"Name != Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test30)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r3);	
	answer.Insert(r5);	

	Table output = d1.Delete("*",t1,"Name > Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test31)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	

	Table output = d1.Delete("*",t1,"Name >= Bob Dole");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test32)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r2);
	answer.Insert(r4);
	answer.Insert(r6);	

	Table output = d1.Delete("*",t1,"Name < Jane Smith");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test33)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	

	Table output = d1.Delete("*",t1,"Name <= Jane Smith");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test34)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r2);
	answer.Insert(r5);
	answer.Insert(r6);	

	Table output = d1.Delete("Email",t1,"Name <= Jane Smith");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}

BOOST_AUTO_TEST_CASE(Test35)
{
	Database d1;
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	r1.ChangeEntry(1,"Bob Dole");
	r2.ChangeEntry(2,"Jane Smith");
	r3.ChangeEntry(3,"test@test.com");
	r4.ChangeEntry(4,"another@test.com");
	r5.ChangeEntry(5,"101");
	r6.ChangeEntry(6,"106");
	Attribute name;
	Attribute email;
	Attribute social;
	t1.Add(name, "Name");
	t1.Add(email, "Email");
	t1.Add(social, "SSN");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);

	Table answer;
	answer.Insert(r1);
	answer.Insert(r2);
	answer.Insert(r3);
	answer.Insert(r4);	

	Table output = d1.Delete("SSN",t1,"Name <= Jane Smith");

	BOOST_CHECK(output.GetSize(output)==answer.GetSize(answer));
}