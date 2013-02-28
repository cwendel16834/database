========================================================================================
Database
========================================================================================
Database::constructor 
Description: Creates an empty database object. 

Parameters: none

Return Value: Database object
_______________________________________________________________________________________

int Database::addTable(string name, Table table)
Description: Takes a specified table and a name and adds that table to the database.

Parameters: 
name: name of table to add
table: pointer to a table that is being added to database

Return value: returns 0 if successful and 1 if unsuccessful
_______________________________________________________________________________________

int Database::dropTable(string name)
Description: Removes a specified table from the database.

Parameters:
name: name of table to remove

Return value: returns 0 if successful and 1 if unsuccessful
_______________________________________________________________________________________

vector<string> Database::listTable()
Description: Returns a list of all the table names in the database.

Parameters: none

Return value: A vector of type string is returned with the names of all the tables in the database.
_______________________________________________________________________________________

map<string, Table> Database::getTables()
Description: Returns all the tables in the database.

Parameters: none

Return value: A map<string, Table> is returned with all the tables that are in the database.
_______________________________________________________________________________________

Table Database::query(string select, string from, string where)
Description: This is the query funtion for the database.

Parameters:
select: a string list of which attribute names to keep
from: the name of the table to query
where: string to parse through that references the attributes

Return value: Returns a Table that is the result of the query function.
_______________________________________________________________________________________

int deleteTuple(string from, string where)
Description: Deletes the specified tuples from the table.

Parameters:
from: the name of the table to delete the tuples from
where: string to parse through that references the attributes

Return value: returns 0 if successful and 1 if unsuccessful

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

Table::Table(vector<Attribute> attr)
Description: This is a constructor that initializes a Table object populated with 
attributes designated by the user.

Parameters:
attributes: a vector of Attribute structures that are the attributes the Table is to be initialized with

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

Return Value: returns 0 if successful and 1 if unsuccessful
_______________________________________________________________________________________

vector<string> Table::getAttributes()
Description: A function that returns a list of the attributes in the table

Parameters: none

Return Value: a string that lists the types of attributes in the table
_______________________________________________________________________________________

int Table::getKey(Record Rec)
Description: A function that returns the key of a specified record

Parameters: rec: a record

Return Value: an int that contains the key of a given record
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

string Table::min(string attrName);
Description: Computes the minimum element in the specified attribute column.

Parameters: 
attrName: Name of the attribute to find the minimum

Return value: A string containing the minimum value for the specified attribute, can then be parsed to the desired type
_______________________________________________________________________________________

string Table::max(string attrName);
Description: Computes the maximum element in the specified attribute column.

Parameters: 
attrName: Name of the attribute to find the maximum

Return value: A string containing the maximum value for the specified attribute, can then be parsed to the desired type
_______________________________________________________________________________________

TableIterator Table::begin();
Description: Gives an iterator pointing to the first Record* in the Table

Parameters: none

Return value: An iterator pointing to the first Record* in the Table
_______________________________________________________________________________________

TableIterator Table::end();
Description: Gives an iterator pointing to the postiion after the last Record* in the Table

Parameters: none

Return value: An iterator pointing to the postiion after the last Record* in the Table

_______________________________________________________________________________________

void removeRecord(Record delRecord);
Description: Removes a specified record from the list

Parameters: a record

Return value: none

_______________________________________________________________________________________

bool checkRow(Record rec, vector<string> cond);
Description: Returns true if the specified record meets the conditions, returns false otherwise.

Parameters: 
rec: input record
cond: vector of string conditions

Return value: returns true if the specified record meets the conditions, returns false otherwise.
========================================================================================
Record
========================================================================================

Record::Record();
Description: Creates a new record with no values

Parameters: none
_______________________________________________________________________________________

Record::Record(int numValues);
Description: Creates a new record with space allocated for the number of values specified in numValues

Parameters: 
numValues: The number of values in this record
_______________________________________________________________________________________

Record::Record(vector<string> values);
Description: Creates a Record containing the values in values

Parameters: 
numValues: The values to be stored in this Record
_______________________________________________________________________________________

Record::~Record();
Description: Destroys the Record and returns all assets

Parameters: none
_______________________________________________________________________________________

int Record::updateValue(int valueNum, string value);
Description: Updates the specified value to the given value string. Returns 0 if successful or 1 if there is an error.

Parameters: 
valueNum: The index of the value to update
value: String containing the new value for the value

Exceptions: Throws an invalid_argument exception if the valueNum is < 0 or > the number of values

Return value: Returns 0 if successful, 1 if there is an error
_______________________________________________________________________________________

string Record::getValue(int valueNum);
Description: Returns the value stored in the specified value.

Parameters: 
valueNum: The index of the value to retrieve value from

Return value: The value stored in the specified value
_______________________________________________________________________________________

int Record::addValue(string value = "NULL");
Description: Adds another space for an value value at the end of the Record, value defaults to "NULL" if not given

Parameters: 
value: The value to be stored in the new column, default is "NULL"

Return value: 0 if successful, otherwise 1
_______________________________________________________________________________________

int Record::getNumValues();
Description: Returns the number of values in the Record

Parameters: none

Return value: The number of values in the Record
_______________________________________________________________________________________

static Record Record::joinRecords(Record& rec1, Record& rec2);
Description: Creates a new Record with the values from rec1 followed by the values from rec2

Parameters: 
rec1: First Record to join
rec2: Second Record to join

Return value: A Record containing the values from the two given Records

_______________________________________________________________________________________

bool Record::operator==(const Record& a);
Description: overloads the operator==

Parameters: 
a: a record for comparison


Return value: Returns true if a and the current record are equal, and returns false otherwise.
