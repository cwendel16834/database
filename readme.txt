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
Description: Computes the sum of all the entries in the specified attribute column.

Parameters: 
attrName: Name of the attribute to sum

Return value: Returns the sum of the specified attribute column.
_______________________________________________________________________________________

int Table::count(string attrName);
Description: Computes the total number of non-NULL entries in the specified attribute column.

Parameters: 
attrName: Name of the attribute to sum

Return value: Returns the number of non-NULL entries in the specified attribute column.
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

Record::Record(int numEntries);
Description: Creates a new record with space allocated for the number of entries specified in numEntries

Parameters: 
numEntries: The number of entries in this record
_______________________________________________________________________________________

int Record::updateEntry(int entryNum, string data);
Description: Updates the specified entry to the given data string. Returns 0 if successful or 1 if there is an error.

Parameters: 
entryNum: The index of the entry to update
data: String containing the new value for the entry

Return value: Returns 0 if successful, 1 if there is an error
_______________________________________________________________________________________

string Record::getEntry(int entryNum);
Description: Returns the value stored in the specified entry.

Parameters: 
entryNum: The index of the entry to retrieve data from

Return value: The value stored in the specified entry


