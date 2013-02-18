========================================================================================
Database
========================================================================================
Database::constructor 
Description: Creates an empty database object. 

Parameters: none

Return Value: Database object
_______________________________________________________________________________________

int Database::addTable(string name, Table* table)
Description: Takes a specified table and a name and adds that table to the database.

Parameters: 
name: name of table to add
table: pointer to a table that is being added to database

Return value: returns 1 if successful and 0 if unsuccessful
_______________________________________________________________________________________

int Database::dropTable(string name)
Description: Removes a specified table from the database.

Parameters:
name: name of table to remove

Return value: returns 1 if successful and 0 if unsuccessful
_______________________________________________________________________________________

vector<string>& Database::listTable()
Description: Returns a list of all the table names in the database.

Parameters: none

Return value: A vector of type string is returned with the names of all the tables in the database.
_______________________________________________________________________________________

map<string, Table*>& Database::getTables()
Description: Returns all the tables in the database.

Parameters: none

Return value: A map<string, Table*>& is returned with all the tables that are in the database.
_______________________________________________________________________________________

Table* Database::query(string select, Table* from, string where)
Description: This is the query funtion for the database.

Parameters:
select: a string list of which attribute names to keep, a null list means keep all
from: the name of the table to query
where: string to parse through that references the attributes

Return value: Returns a Table* that is the result of the query function.
_______________________________________________________________________________________

int deleteTuple(string select, Table* from, string where)
Description: Deletes the specified tuples from the table.

Parameters:
select: a string list of which attribute names to keep, a null list means keep all
from: the name of the table to delete the tuples from
where: string to parse through that references the attributes

Return value: returns 1 if successful and 0 if unsuccessful

========================================================================================
Table
========================================================================================

Table::TableIterator
Description: An iterator type for traversing the records in a Table
_______________________________________________________________________________________

Attribute{}
Description: This is a structure to contain the name and type of an attribute

Parameters:
attributeName: name of the attribute
attributeType: a string name of the type of the attribute 

Return Value: a new Attribute structure
_______________________________________________________________________________________

Table::Table()
Description: empty constructor for a new Table

Parameters: none 

Return Value: Table Object
_______________________________________________________________________________________

Table::Table(Attribute attributes[])
Description: This is a constructor that initializes a Table object populated with 
attributes designated by the user.

Parameters:
attributes: an array of Attribute structures that are the attributes the Table is to be initialized with

Return Value: a new Table object
_______________________________________________________________________________________

int Table::addAttribute(Attribute newAttribute)
Description
This function adds a new attribute to the table

Parameters:
newAttribute: an Attribute structure containing the name and type of the attribute to be added

Return Value: returns 0 if successful and 1 if unsuccessful
_______________________________________________________________________________________

int Table::deleteAttribute(Attribute oldAttribute)
Description: deletes an attribute from the Table 

Parameters: 
oldAttribute: an Attribute object that has the name and type of the attribute that is to be deleted

Return Value: returns 0 if successful and 1 if unsuccessful
_______________________________________________________________________________________

int Table::insertRecord(Record newRecord)
Description: inserts a new record into the table

Parameters:
newRecord: a record object that is to be inserted into the table

Return Value: returns 0 if successful, 1 if unsuccessful
_______________________________________________________________________________________

vector<string> Table::getAttributes()
Description: A function that returns a list of the attributes in the table

Parameters: none

Return Value: a string that lists the types of attributes in the table
_______________________________________________________________________________________

int Table::getSize()
Description: A function that returns the size of the table

Parameters: none 

Return Value: an int value that is the total number of records in the table
_______________________________________________________________________________________

int Table::renameAttribute(string oldName, string newName);
Description: Renames the specified attribute. Returns 0 if successful or 1 if there is an error.

Parameters:
oldName: The name of the existing attribute to be renamed
newName: The new name for the attribute

Return value: 0 if successful, 1 if there is an error
_______________________________________________________________________________________

Table& Table::join(Table& table);
Description: Returns this a table containing this Table's records joined with the specified Table's records.

Parameters:
table: Table to be joined with this Table

Return value: The joined Table
_______________________________________________________________________________________

double Table::sum(string attrName);
Description: Computes the sum of all the attributes in the specified attribute column.

Parameters: 
attrName: Name of the attribute to sum

Return value: Returns the sum of the specified attribute column.
_______________________________________________________________________________________

int Table::count(string attrName);
Description: Computes the total number of non-NULL attributes in the specified attribute column.

Parameters: 
attrName: Name of the attribute to sum

Return value: Returns the number of non-NULL attributes in the specified attribute column.
_______________________________________________________________________________________

Record& Table::min(string attrName);
Description: Computes the minimum element in the specified attribute column.

Parameters: 
attrName: Name of the attribute to find the minimum

Return value: The record containing the minimum value for the specified attribute
_______________________________________________________________________________________

Record& Table::max(string attrName);
Description: Computes the maximum element in the specified attribute column.

Parameters: 
attrName: Name of the attribute to find the maximum

Return value: The record containing the maximum value for the specified attribute

========================================================================================
Record
========================================================================================

Record::Record();
Description: Creates a new record with no attributes

Parameters: none
_______________________________________________________________________________________
Record::Record(int numAttributes);
Description: Creates a new record with space allocated for the number of attributes specified in numAttributes

Parameters: 
numAttributes: The number of attributes in this record
_______________________________________________________________________________________

Record::~Record();
Description: Destroys the Record and returns all assets

Parameters: none
_______________________________________________________________________________________

int Record::updateAttribute(int attributeNum, string data);
Description: Updates the specified attribute to the given data string. Returns 0 if successful or 1 if there is an error.

Parameters: 
attributeNum: The index of the attribute to update
data: String containing the new value for the attribute

Return value: Returns 0 if successful, 1 if there is an error
_______________________________________________________________________________________

string Record::getAttribute(int attributeNum);
Description: Returns the value stored in the specified attribute.

Parameters: 
attributeNum: The index of the attribute to retrieve data from

Return value: The value stored in the specified attribute
_______________________________________________________________________________________

int Record::getNumAttributes();
Description: Returns the number of attributes in the Record

Parameters: none

Return value: The number of attributes in the Record


