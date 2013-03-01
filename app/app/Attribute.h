#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H


#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Attribute {
public:
	string name;
	string type;

	Attribute();
	~Attribute();
	
	Attribute(string _name, string _type);  //cw changed _type from int to string for consistency
	void setName(string _name);
};

#endif