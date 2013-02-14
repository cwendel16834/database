//#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "Table.h"

string vc50 = "varchar(50)";

bool vectorContainsAttr(vector<Attribute> vect, string elem) {
	//returns true if vect contains an attribute with name = elem

	vector<Attribute>::iterator it = vect.begin();

	while (it != vect.end()) {
		if ( it->name == elem) return true;
	}

	return false;
}

BOOST_AUTO_TEST_CASE(Test1)
{
	Table t1;
	BOOST_CHECK(t1.GetSize()==0);
}

BOOST_AUTO_TEST_CASE(Test2)
{
	Table t1;
	string type = "type";
	t1.Add(type, vc50);
	vector<Attribute> vect = t1.GetAttributes();
	BOOST_CHECK(vectorContainsAttr(vect, type)==true);
}

BOOST_AUTO_TEST_CASE(Test3)
{
	Table t1;
	string typeA = "typeA";
	string typeB = "typeB";
	string typeC = "typeC";
	t1.Add(typeA, vc50);
	t1.Add(typeB, vc50);
	t1.Add(typeC, vc50);
	t1.Delete("typeA");
	BOOST_CHECK(t1.GetSize()==0);
}

BOOST_AUTO_TEST_CASE(Test4)
{
	Table t1;
	t1.Add("typeA", vc50);
	t1.Add("typeB", vc50);
	BOOST_CHECK(t1.GetSize()==0);
}

BOOST_AUTO_TEST_CASE(Test5)
{
	Table t1;
	string type="a";
	t1.Add(type, vc50);
	t1.Delete("a");
	vector<Attribute> vect = t1.GetAttributes();
	BOOST_CHECK(vect.size()==0);
}

BOOST_AUTO_TEST_CASE(Test6)
{
	Table t1;
	Attribute a;
	string type="a";
	t1.Add(type, vc50);
	t1.Delete(type);
	BOOST_CHECK(t1.GetAttributes().size()==0);
}

BOOST_AUTO_TEST_CASE(Test7)
{
	Table t1;
	Attribute a;
	string type="a";
	t1.Add(type, vc50);
	t1.Delete("a");
	BOOST_CHECK(t1.GetAttributes().size()==0);
}

BOOST_AUTO_TEST_CASE(Test8)
{
	Table t1;
	Record r;
	t1.Insert(r);
	BOOST_CHECK(t1.GetSize()==1);
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
	string type="a";
	t1.Add(type, vc50);
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	t1.Insert(r4);
	t1.Insert(r5);
	t1.Insert(r6);
	BOOST_CHECK(t1.GetSize()==6);
}

BOOST_AUTO_TEST_CASE(Test10)
{
	Table t1;
	string type="a";
	t1.Add(type, vc50);
	Record r1;
	Record r2;
	Record r3;
	Record r4;
	Record r5;
	Record r6;
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	BOOST_CHECK(t1.GetSize()==3);
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
	t1.Add("NAME", vc50);
	t1.Add("ADDRESS", vc50);
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	BOOST_CHECK(t1.GetSize()==3);
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
	t1.Add("NAME",vc50);
	t1.Add("ADDRESS", vc50);
	t1.Add("PHONE", vc50);
	t1.Insert(r1);
	t1.Insert(r2);
	t1.Insert(r3);
	vector<Attribute> vect = t1.GetAttributes();
	BOOST_CHECK(vect.size()==3);
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
	t1.Add("NAME", vc50);
	t1.Add("ADDRESS", vc50);
	t1.Add("PHONE", vc50);
	t1.Rename("PHONE", "PHONE NUMBER");
	vector<Attribute> vect = t1.GetAttributes();
	BOOST_CHECK(vectorContainsAttr(vect, "PHONE")==false);
}

BOOST_AUTO_TEST_CASE(Test14)
{
   vector<string> atts;
   atts.push_back("a1");
   atts.push_back("a2");
   atts.push_back("a3");
   vector<string> type;
   type.push_back(vc50);
   type.push_back(vc50);
   type.push_back(vc50);
   Table t1(atts, type);
   BOOST_CHECK(t1.GetAttributes().size()==3);
}

BOOST_AUTO_TEST_CASE(Test15)
{
   vector<string> vect;
   vector<string> type;
   Table t1(vect, type);
   BOOST_CHECK(t1.GetAttributes().size()==0);
}

BOOST_AUTO_TEST_CASE(Test16)
{

   Table t1;
   t1.Add("NAME", vc50);
   t1.Rename("NAME", "FULLNAME");
   vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vectorContainsAttr(vect, "FULLNAME")==true);
                            
}

BOOST_AUTO_TEST_CASE(Test17)
{
   vector<Attribute> atts;
   Record r1;
   Table t1;
   t1.Add("ADDRESS", vc50);
   vector<Attribute> vect = t1.GetAttributes();
   t1.Insert(r1);
   BOOST_CHECK(vectorContainsAttr(vect, "ADDRESS")==true);
}

BOOST_AUTO_TEST_CASE(Test18)
{
  
   Table t1;
   t1.Add("DOB", vc50);
   t1.Delete("NAME");
   vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vectorContainsAttr(vect, "DOB")==true);
}

BOOST_AUTO_TEST_CASE(Test19)
{
  Table t1;
  t1.Add("name", vc50);
  t1.Add("dob", vc50);
  t1.Add("ssn", vc50);
  Record r1;
  t1.Delete("name");
  t1.Delete("ssn");
  t1.Insert(r1);
  t1.Add("DOB", vc50);
  BOOST_CHECK(t1.GetSize()==1);
}

BOOST_AUTO_TEST_CASE(Test20)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";

  Record r1;
  t1.Add(name1, vc50);
  t1.Add(name2, vc50);
  t1.Add(name3, vc50);
  t1.Insert(r1);
  BOOST_CHECK(t1.GetSize()==1);
}

BOOST_AUTO_TEST_CASE(Test21)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ss";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";

  Record r1;
  t1.Add(name1 , vc50);
  t1.Add(name2, vc50);
  t1.Add(name5, vc50);
  t1.Insert(r1);
  t1.Rename("ss", "SSN");
  vector<Attribute> vect = t1.GetAttributes();
  BOOST_CHECK(vectorContainsAttr(vect, name2)==false);
  
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
  t1.Add(name1, vc50);
  t1.Add(name3, vc50);
  t1.Add(name5, vc50);
  t1.Insert(r1);
  t1.Rename("OCCUPATION", "JOB");
  t1.Rename("NAME", "MAIDEN  NAME");
  t1.Rename("DOB", "DATE OF BIRTH");
  BOOST_CHECK(t1.GetSize()==1);
}

BOOST_AUTO_TEST_CASE(Test23)
{
  Table t1;
  string name1 = "NAME";
  string name2 = "ssn";
  string name3 = "DOB";
  string name4 = "ADDRESS";
  string name5 = "OCCUPATION";
  Record r1;
  Record r2;
  Record r3;
  t1.Add(name1, vc50);
  t1.Add(name2, vc50);
  t1.Add(name3, vc50);
  t1.Add(name4, vc50);
  t1.Add("OCCUPATION", vc50);
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
  vector<Attribute> vect = t1.GetAttributes();
  BOOST_CHECK(vectorContainsAttr(vect, name2)==false); 
}

BOOST_AUTO_TEST_CASE(Test24)
{
  	Table t1;
	string type = "NAME";
	t1.Add(type, vc50);
	Record r1;
	t1.Insert(r1);
	t1.Delete("NAME");
	vector<Attribute> vect = t1.GetAttributes();
    BOOST_CHECK(vectorContainsAttr(vect, "NAME")==false);
}

BOOST_AUTO_TEST_CASE(Test25)
{
  	Table t1;
	Attribute a;
	string type = "nme";
	t1.Add(type, vc50);
	t1.Rename(type, "SURNAME");
    vector<Attribute> vect = t1.GetAttributes();
    BOOST_CHECK(vectorContainsAttr(vect, type)==false);
}

BOOST_AUTO_TEST_CASE(Test26)
{
    Table t1;
	string type = "NAME";
	t1.Add(type, vc50);
	t1.Add("DOB", vc50);
	
	Record r;
	t1.Insert(r);
	t1.Delete(type);
    vector<Attribute> vect = t1.GetAttributes();
    BOOST_CHECK(vectorContainsAttr(vect, type)==false);
}

BOOST_AUTO_TEST_CASE(Test27)
{
    Table t1;

	string type = "NAME";
	t1.Add(type, vc50);
	Record r;
	t1.Insert(r);
	t1.Add("DOB", vc50);
	t1.Delete("DOB");
    vector<Attribute> vect = t1.GetAttributes();
    BOOST_CHECK(vectorContainsAttr(vect, type)==true);                  
}

BOOST_AUTO_TEST_CASE(Test28)
{
   vector<string> attname;
   vector<string> atttype;
   attname.push_back("SSN");
   atttype.push_back(vc50);
   Table t1(attname,atttype);
   vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vectorContainsAttr(vect, "SSN")==false);        
}

BOOST_AUTO_TEST_CASE(Test29)
{
 vector<string> atts;
 vector<string> type;
 type.push_back(vc50);
 atts.push_back("NME");
   Record r1;
   Table t1(atts, type);
   t1.Delete("dob");   
   t1.Delete("name");
   t1.Delete("ssn");
   vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vect.size() == 1);                      
}

BOOST_AUTO_TEST_CASE(Test30)
{
   
   Table t1;
   t1.Add("dob", vc50);   
   t1.Delete("name");
   t1.Delete("ssn");
   BOOST_CHECK(t1.GetAttributes().size() == 1);                          
}

BOOST_AUTO_TEST_CASE(Test31)
{
   
   Table t1;
   t1.Add("record", vc50);
   vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vectorContainsAttr(vect, "record")==true);

}

BOOST_AUTO_TEST_CASE(Test32)
{
  
   Table t1;
   t1.Add("NME", vc50);
   Record r1;
   t1.Insert(r1);
   BOOST_CHECK(t1.GetSize()==1);                           
}

BOOST_AUTO_TEST_CASE(Test33)
{

   Record r1;
   Record r2;
   Record r3;
   Record r4;
   Record r5;
   Table t1;
   t1.Add("name", vc50);
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
  
   BOOST_CHECK(t1.GetSize()==3);                    
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
   t1.Add("NAME", vc50);
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
   
   BOOST_CHECK(t1.GetSize()==3);                       
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
   t1.Add("NAME", vc50);
   t1.Insert(r1);
   t1.Insert(r2);
   t1.Insert(r3);
   
   t1.Rename("NAME", "maiden name");
  vector<Attribute> vect = t1.GetAttributes();
   BOOST_CHECK(vectorContainsAttr(vect, "maiden name")==true);
                 
}

//testing rename(string, string)

BOOST_AUTO_TEST_CASE(Test36) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	t1.Rename("name", "fullname");
	vector<Attribute> attributes = t1.GetAttributes();
	string attrName = "fullname";
	BOOST_CHECK(vectorContainsAttr(attributes, attrName));
}

BOOST_AUTO_TEST_CASE(Test37) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	t1.Rename("name", "name");
	//should either rename to same or ignore
	vector<Attribute> attributes = t1.GetAttributes();
	string attrName = "name";
	BOOST_CHECK(vectorContainsAttr(attributes, attrName));
}

BOOST_AUTO_TEST_CASE(Test38) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	int error = t1.Rename("name", "");
	//should not allow rename to empty string
	BOOST_CHECK(error == -1);
}

BOOST_AUTO_TEST_CASE(Test39) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	int error = t1.Rename("name", "");
	//should not allow rename to empty string
	//should still have old attribute
	vector<Attribute> attributes = t1.GetAttributes();
	string attrName = "name";
	BOOST_CHECK(vectorContainsAttr(attributes, attrName));
}

BOOST_AUTO_TEST_CASE(Test40) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	int error = t1.Rename("date", "birthday");
	//should not allow rename to nonexistent attribute

	BOOST_CHECK(error == -1);
}

BOOST_AUTO_TEST_CASE(Test41) 
{
	Table t1;
	t1.Add("name", "varchar(50)");
	int error = t1.Rename("date", "birthday");
	//should not allow rename to to nonexistent attribute
	//should still have old attribute
	vector<Attribute> attributes = t1.GetAttributes();
	string attrName = "name";
	BOOST_CHECK(vectorContainsAttr(attributes, attrName));
}

BOOST_AUTO_TEST_CASE(Test42) 
{
	Table t1, t2;
	t1.Add("name", "varchar(50)");


	BOOST_CHECK(false);

}
