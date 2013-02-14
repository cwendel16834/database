#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Table.h"

BOOST_AUTO_TEST_CASE(Test1)
{
	Table t1;
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test2)
{
	Table t1;
	Attribute a;
	string type = "type";
	t1.Add(a,type);
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test3)
{
	Table t1;
	Attribute a;
	Attribute b;
	Attribute c;
	string typeA = "typeA";
	string typeB = "typeB";
	string typeC = "typeC";
	t1.Add(a,typeA);
	t1.Add(b,typeB);
	t1.Add(c,typeC);
	t1.Delete("a");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test4)
{
	Table t1;
	Attribute a;
	Attribute b;
	t1.Add(a,"typeA");
	t1.Add(b,"typeB");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test5)
{
	Table t1;
	Attribute a;
	string type;
	t1.Add(a,type);
	t1.Delete("a");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test6)
{
	Table t1;
	Attribute a;
	string type;
	t1.Add(a,type);
	t1.Delete("a");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test7)
{
	Table t1;
	Attribute a;
	string type;
	t1.Add(a,type);
	t1.Delete("a");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test8)
{
	Table t1;
	Record r;
	t1.Insert(r);
	BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test9)
{
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);
	BOOST_CHECK(t1.GetSize(t1)==6);
}

BOOST_AUTO_TEST_CASE(Test10)
{
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	BOOST_CHECK(t1.GetSize(t1)==3);
}

BOOST_AUTO_TEST_CASE(Test11)
{
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	Attribute a1;
	Attribute a2;
	t1.Add(a1, "NAME");
	t1.Add(a1, "ADDRESS");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	BOOST_CHECK(t1.GetSize(t1)==3);
}


BOOST_AUTO_TEST_CASE(Test12)
{
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	Attribute a1;
	Attribute a2;
    Attribute a3;	
	t1.Add(a1, "NAME");
	t1.Add(a1, "ADDRESS");
	t1.Add(a1, "PHONE");
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	BOOST_CHECK(t1.GetSize(t1)==3);
}

BOOST_AUTO_TEST_CASE(Test13)
{
	Table t1;
	Record r1;
	Record r2;
	Record r3;
	Attribute a1;
	Attribute a2;
    Attribute a3;	
	t1.Add(a1, "NAME");
	t1.Add(a1, "ADDRESS");
	t1.Add(a1, "PHONE");
	t1.Rename("PHONE", "PHONE NUMBER");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test14)
{
   vector<Attribute> atts;
   Attribute a1;
	Attribute a2;
    Attribute a3;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   Table t1(atts, "NAME,DOB,PHONE");
   BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test15)
{
   vector<Attribute> atts;
   Attribute a1;
	Attribute a2;
    Attribute a3;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   Table t1(atts, "NAME,DOB,PHONE");
   t1.GetAttributes(t1);
   BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test16)
{
    vector<Attribute> atts;
   Attribute a1;
	Attribute a2;
    Attribute a3;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   Table t1(atts, "NAME,DOB,PHONE");
   t1.Rename("NAME", "FULLNAME");
   t1.GetAttributes(t1);
   BOOST_CHECK(t1.GetSize(t1)==0);
                            
}

BOOST_AUTO_TEST_CASE(Test17)
{
   vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   Table t1(atts, "NAME,DOB,PHONE");
   t1.Add(a4, "ADDRESS");
   t1.GetAttributes(t1);
   t1.Insert(r1);
   BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test18)
{
   vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   Table t1(atts, "NAME,DOB,PHONE");
   t1.Delete("NAME");
   t1.GetAttributes(t1);
   BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test19)
{
  Table t1;
  Attribute a1;
  Attribute a2;
  Attribute a3;
  t1.Add(a1, "NAME");
  t1.Add(a2, "SSN");
  t1.Add(a3, "DOB");
  Record r1;
  t1.Delete("DOB");
  t1.Delete("SSN");
  t1.Insert(r1);
  t1.Add(a3, "DOB");
  t1.GetAttributes(t1);
  BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test20)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";
  Attribute a1;
  Attribute a2;
  Attribute a3;
  Record r1;
  t1.Add(a1, name1);
  t1.Add(a2, name2);
  t1.Add(a3, name5);
  t1.Insert(r1);
  t1.GetAttributes(t1);
  BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test21)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";
  Attribute a1;
  Attribute a2;
  Attribute a3;
  Record r1;
  t1.Add(a1, name1);
  t1.Add(a2, name2);
  t1.Add(a3, name5);
  t1.Insert(r1);
  t1.Rename("ssn", "SSN");
  t1.GetAttributes(t1);
  BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test22)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";
  Attribute a1;
  Attribute a2;
  Attribute a3;
  Record r1;
  t1.Add(a1, name1);
  t1.Add(a2, name3);
  t1.Add(a3, name5);
  t1.Insert(r1);
  t1.Rename("OCCUPATION", "JOB");
  t1.Rename("NAME", "MAIDEN  NAME");
  t1.Rename("DOB", "DATE OF BIRTH");
  t1.GetAttributes(t1);
  BOOST_CHECK(t1.GetSize(t1)==1);
}

BOOST_AUTO_TEST_CASE(Test23)
{
   Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";
  Attribute a1;
  Attribute a2;
  Attribute a3;
  Attribute a4;
  Attribute a5;
  Record r1;
  Record r2;
  Record r3;
  t1.Add(a1, name1);
  t1.Add(a2, name2);
  t1.Add(a3, name3);
  t1.Add(a4, name4);
  t1.Add(a5, "OCCUPATION");
  t1.Insert(r1);
  t1.Insert(r2);
  t1.Insert(r3);
  t1.Rename("OCCUPATION", "JOB");
  t1.Rename("NAME", "MAIDEN  NAME");
  t1.Rename("DOB", "DATE OF BIRTH");
  t1.Delete("MAIDEN NAME");
  t1.Delete("JOB");
  t1.Delete("DATE OF BIRTH");
  t1.Delete("ssn");
  t1.Delete("ADDRESS");
  t1.GetAttributes(t1);
  BOOST_CHECK(t1.GetSize(t1)==0); 
}

BOOST_AUTO_TEST_CASE(Test24)
{
  	Table t1;
	Attribute Name;
	string type = "NAME";
	t1.Add(Name,type);
	Record r1;
	t1.Insert(r1);
	t1.Delete("NAME");
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test25)
{
  	Table t1;
	Attribute a;
	string type = "surNAMe";
	t1.Add(a,type);
	t1.Rename(type, "SURNAME");
	t1.GetAttributes(t1);
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test26)
{
    Table t1;
	Attribute a1;
	Attribute a2;
	Attribute a3;
	string type = "NAME";
	t1.Add(a1,type);
	t1.Add(a2, type);
	t1.Add(a3, type);
	Record r;
	t1.Insert(r);
	t1.Delete(type);
	t1.GetAttributes(t1);
	BOOST_CHECK(t1.GetSize(t1)==0);
}

BOOST_AUTO_TEST_CASE(Test27)
{
   Table t1;
	Attribute a1;
	Attribute a2;
	Attribute a3;
	string type = "NAME";
	t1.Add(a1,type);
	t1.Add(a2, type);
	Record r;
	t1.Insert(r);
	t1.Add(a3, "DOB");
	t1.Delete("DOB");
	t1.GetAttributes(t1);
	BOOST_CHECK(t1.GetSize(t1)==1);                   
}

BOOST_AUTO_TEST_CASE(Test28)
{
   vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   atts.push_back(a4);
   Table t1(atts, "name dob ssn occ");
   t1.Delete("dob");   
   BOOST_CHECK(t1.GetAttributes(t1) != "name dob ssn occ");         
}

BOOST_AUTO_TEST_CASE(Test29)
{
 vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   atts.push_back(a4);
   Table t1(atts, "name dob ssn occ");
   t1.Delete("dob");   
   t1.Delete("name");
   t1.Delete("ssn");
   BOOST_CHECK(t1.GetAttributes(t1) == "occ");                      
}

BOOST_AUTO_TEST_CASE(Test30)
{
   vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   atts.push_back(a4);
   Table t1(atts, "name dob ssn occ");
   t1.Delete("dob");   
   t1.Delete("name");
   t1.Delete("ssn");
   BOOST_CHECK(t1.GetAttributes(t1) == "occ");                          
}

BOOST_AUTO_TEST_CASE(Test31)
{
   vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   atts.push_back(a4);
   Table t1(atts, "name dob ssn occ");
   t1.Delete("dob");   
   t1.Delete("name");
   t1.Delete("ssn");
   t1.Delete("occ");
   BOOST_CHECK(t1.GetAttributes(t1) == "");    
}

BOOST_AUTO_TEST_CASE(Test32)
{
  vector<Attribute> atts;
   Attribute a1;
   Attribute a2;
   Attribute a3;
   Attribute a4;
   Record r1;
   atts.push_back(a1);
   atts.push_back(a2);
   atts.push_back(a3);
   atts.push_back(a4);
   Table t1(atts, "name dob ssn occ");
   t1.Insert(r1);
   t1.Delete("dob");   
   t1.Delete("name");
   t1.Delete("ssn");
   t1.Delete("occ");
   BOOST_CHECK(t1.GetSize(t1)==0);                           
}

BOOST_AUTO_TEST_CASE(Test33)
{
  vector<Attribute> atts;
   Attribute a1;
   Record r1;
   Record r2;
   Record r3;
   Record r4;
   Record r5;
   Table t1(atts, "name dob ssn occ");
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
  
   BOOST_CHECK(t1.GetSize(t1)==3);                    
}

BOOST_AUTO_TEST_CASE(Test34)
{
   Attribute a1;
   Record r1;
   Record r2;
   Record r3;
   Record r4;
   Record r5;
   Table t1;
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
   t1.Add(a1, "NAME");
   BOOST_CHECK(t1.GetSize(t1)==3);                       
}

BOOST_AUTO_TEST_CASE(Test35)
{
                             Attribute a1;
   Record r1;
   Record r2;
   Record r3;
   Record r4;
   Record r5;
   Table t1;
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
   t1.Add(a1, "NAME");
   t1.Rename("NAME", "maiden name");
   BOOST_CHECK(t1.GetAttributes(t1)=="maiden name"); 
                 
}


