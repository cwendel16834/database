#include "Database.h"

int main()
{
	Database d1;
	Table t1;
	Record r1;
	r1.addValue("ryan");
	r1.addValue("pesek");

	Record r2;
	r2.addValue("kori");
	r2.addValue("michalec");
	
		
	Attribute a1;
	a1.attributeName="first";
	a1.attributeType="string";
	Attribute a2;
	a2.attributeName="second";
	a2.attributeType="string";

	t1.addAttribute(a1);
	t1.addAttribute(a2);
	t1.insertRecord(r1);
	t1.insertRecord(r2);
	
	d1.addTable("test",t1);

	Table t2=d1.query("first", "test", "first = 'pesek'");
	cout << t2.getSize();
	cout << "hi";
	char ch;
	cin>>ch;

}