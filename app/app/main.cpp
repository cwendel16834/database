#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include "Database.h"
#include "Table.h"
#include "Record.h"
#include "Attribute.h"
using namespace std;

/*using database from team 23*/

int addTableToDatabase(Database& d, string filename)
{
	/*get appropriate name for table */
	string name=filename;
	for(int i=0;i<4;i++)
	{
		name.pop_back();
	}
	/*first line of every file is a list of table attributes, 
	read in the first line, parse it and add individual attributes to the table*/
	ifstream readFile(filename);
	string attributeLine;
    getline(readFile, attributeLine);

	/*make a stream that is used to get individual attribute names from the list of attributes and add them to the table*/
	stringstream attributeStream (stringstream::in | stringstream::out);
	attributeStream<<attributeLine;

	/*populate a vector of attributes and a vector of attribute types
	to be passed to the table*/
	vector<string> tableAttNames;
	vector<string> tableAttTypes;
	string newAttribute;
	string newType;
	while(attributeStream.good()) 
	{
		attributeStream>>newAttribute;
		tableAttNames.push_back(newAttribute);
		
	}
	stringstream typeStream;
	getline(readFile,attributeLine);
	typeStream<<attributeLine;
	while(typeStream.good())
	{
		typeStream>>newType;
		tableAttTypes.push_back(newType);
	}

	Table newTable(tableAttNames, tableAttTypes);
	
	/*populate table with records before adding to the database */
	while(readFile.good())
	{
	  string record;
	  vector<string>recordTuples;
      getline(readFile,record);
	  string individualTuple;
	  stringstream recordStream;
	  recordStream<<record;
	  while(recordStream.good())
	  {
		  recordStream>>individualTuple;
		  recordTuples.push_back(individualTuple);
	  }
	  Record newRecord(recordTuples);
	  newTable.Insert(newRecord);
	 
	}
	readFile.close();
	d.AddTable( newTable,name);
	return 0;
}

/*get information about a customer*/
void customerProfile(Table& t, string customerID, string info)
{
	int position=0;
	cout<<endl<<customerID<<"\n"<<info<<":";

	/*for each table, iterate through records and print record that has customer information*/
	vector<Attribute>tableAttributes = t.GetAttributes();
	for(int i=0; i<tableAttributes.size(); i++)
	{
	 if(tableAttributes[i].name == info)
	 {
	  position=i;
	 }
	}
	
	/*get the customer's entry for the specific attribute*/
	for(int j=0;j<t.set.size()-1;j++)
	{
	 if(position>tableAttributes.size())
	 {
	  break;
	 }
     string s=t.set[j].tuple[0];
	 if(s.compare(customerID)==0)
	 {
	 cout<<t.set[j].tuple[position]<<endl;
	 }
	}
}
/*get information about a restaurants hours,payment,parking,or cuisine*/
void restaurantProfile(Database& d, string restaurant, string info)
{
	/*find table with the requested data,iterate through records and print
	data result for given restaurant
	*/
	cout<<"restaurant ID: "<<restaurant<<endl<<info<<": \n";
	vector<Table>dataTables=d.GetTables();
	if(info.compare("hours")==0)
	{
	 for(int i=0;i<dataTables.size();i++)
	 {
	  if(dataTables[i].name.compare("chefmozhours")==0)
	  {
	   for(int j=0;j<dataTables[i].set.size();j++)
	   {
	    if(dataTables[i].set[j].tuple[0].compare(restaurant)==0)
		{
		 for(int k=1;k<dataTables[i].set[j].tuple.size();k++)
		 {
		  cout<<dataTables[i].set[j].tuple[k];
		 }
		 cout<<endl;
		}
	   }
	  }
	 }
	} else if(info.compare("cuisine")==0){
	for(int i=0;i<dataTables.size();i++)
	{
	 if(dataTables[i].name.compare("chefmozcuisine")==0)
	 {
	  for(int j=0;j<dataTables[i].set.size();j++)
	  {
	   if(dataTables[i].set[j].tuple[0].compare(restaurant)==0)
	   {
	    for(int k=1;k<dataTables[i].set[j].tuple.size();k++)
		{
		 cout<<dataTables[i].set[j].tuple[k];
		}
		cout<<endl;
	   }
	  }
	 }
	}
	}else if(info.compare("parking")==0){
	for(int i=0;i<dataTables.size();i++)
	{
	 if(dataTables[i].name.compare("chefmozparking")==0)
	 {
	  for(int j=0;j<dataTables[i].set.size();j++)
	  {
	   if(dataTables[i].set[j].tuple[0].compare(restaurant)==0)
	   {
		for(int k=1;k<dataTables[i].set[j].tuple.size();k++)
		{
		 cout<<dataTables[i].set[j].tuple[k];
		}
		cout<<endl;
	   }
	  }
 	 }	
	}
	}else if(info.compare("payment")==0){
	for(int i=0;i<dataTables.size();i++)
	{
	 if(dataTables[i].name.compare("chefmozaccepts")==0)
	 {
	  for(int j=0;j<dataTables[i].set.size();j++)
	  {
	   if(dataTables[i].set[j].tuple[0].compare(restaurant)==0)
	   {
		for(int k=1;k<dataTables[i].set[j].tuple.size();k++)
		{
		 cout<<dataTables[i].set[j].tuple[k];
		}
		cout<<endl;
	   }
	  }
	 }	
	}
	} else if(info.compare("ratings")==0) {
	for(int i=0;i<dataTables.size();i++)
	{
	 if(dataTables[i].name.compare("rating_final")==0)
	 {
	  for(int j=0;j<dataTables[i].set.size()-1;j++)
	  {
	   if(dataTables[i].set[j].tuple[1].compare(restaurant)==0)
	   {
		cout<<dataTables[i].set[j].tuple[2]<<" ";	
		cout<<endl;
	   }
	  }
	 }	
	}

	} else{
		cout<<"invalid request"<<endl;
	}
	
}

/*combine the data from multiple tables using the Table class CrossJoin function*/
void joinTables(Database& d, string table1, string table2)
{
	/*allow user to specify the name of new table*/
	table1=table1.substr(1);
	string newTableName;
	cout<<"Enter the name for the new table: ";
	cin>>newTableName;
	Table oldTable1;
	vector<Table>dataTables=d.GetTables();
	/*find and join the two tables and add them to the database. */
	for(int i=0; i<dataTables.size(); i++)
	{
	  if(dataTables[i].name.compare(table1)==0)
	  { 
	   cout<<"found first table\n";
	   for(int k=0;k<dataTables.size();k++)
	   {
        if(dataTables[k].name.compare(table2)==0)
        {
		 cout<<"found second table\n";
		 //oldTable1.CrossJoin(dataTables[i],dataTables[k]);
		 cout<<"successfully joined the tables\n";
		}
	   }
	  }
	}
}
/*helper function to find the ID of a restaurant based on it's name*/
string findID(Database&d, string name)
{
	vector<Table>dataTables=d.GetTables();
	for(int i=0;i<dataTables.size(); i++)
	{
	 if(dataTables[i].name.compare("geoplaces2")==0)
	 {
	  for(int k=0;k<dataTables[i].set.size()-1; k++)
	  {
	   if(dataTables[i].set[k].tuple[4].compare(name)==0)
	   {
		return dataTables[i].set[k].tuple[0];
	   }
	  }
	 }
	}
	return "could not find an ID for that restaurant";
}
int main()
{
	/*populate the database*/
	Database database;
	addTableToDatabase(database, "chefmozaccepts.txt");
	addTableToDatabase(database, "chefmozcuisine.txt");
	addTableToDatabase(database, "chefmozhours.txt");
	addTableToDatabase(database, "chefmozparking.txt");
	addTableToDatabase(database, "usercuisine.txt");
	addTableToDatabase(database, "userpayment.txt");
	addTableToDatabase(database, "userprofile.txt");
	addTableToDatabase(database, "rating_final.txt");
	addTableToDatabase(database, "geoplaces2.txt");
	vector<Table>tables=database.GetTables();

	/*user requests information from the console window. 
	'quit' ends the program. Commands are listed in the API*/
	
	while(true)
	{
	  cout<<"*************\ninput command\n*************\n";
	  string input;
	  getline(cin, input);
	  /*parse string command and determine which operation is to be performed */
	  if(input == "QUIT" || input =="quit")
	  {
	   break;
	  }
	  /*separate command from parameters*/
	  int commandSubstr = input.find(':');
	  string command=input.substr(0,commandSubstr);
	  string params=input.substr(commandSubstr+1);
	  string parameter1;
	  string parameter2;
	  if(input.find('-')>0)
	  {
	  parameter1 = params.substr(0,params.find('-'));
	  parameter2 = params.substr(params.find('-')+1);
	  }else{
	   parameter1 = params;
	   parameter2 = "";
	  }

	  /*carry out the appropriate operation specified by the command */

	  /*will print out a specific attribute for a customer from their profile
		 if a specific attribute isn't specified, then the function will print out 
		 all attributes about the user from the profile*/
	  if(command=="customer information" || command=="CUSTOMER INFORMATION")
	  {
	   for(int i=0;i<tables.size();i++)
		{
		 if(tables[i].name=="userprofile")
		 {
		  customerProfile(tables[i], parameter1, parameter2);
		 }
		}
	  }else if(command=="restaurant information" || command=="RESTAURANT INFORMATION"){
		  /*retrieves a specific attribute for a specified restaurant. if no attribute 
		  is specified, all attributes for the restaurant are printed*/
	   restaurantProfile(database, findID(database, parameter1), parameter2);
	  } else if(command=="combine tables" || command=="COMBINE TABLES"){
	       /*combine multiple tables from the database*/
	    joinTables(database, parameter1, parameter2);
	  } else{
		cout<<"invalid command"<<endl;
	  }

	}

	return 0;
}