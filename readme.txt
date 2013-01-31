Database::constructor 
Description: Creates an empty database object. 

Parameters: none

Return Value: Database object



void Database::addTable(string name, Table* table)
Description: Takes a specified table and a name and adds that table to the database.

Parameters: 
name: name of table to add
table: pointer to a table that is being added to database

Return value: none



void Database::dropTable(string name)
Description: Removes a specified table from the database.

Parameters:
name: name of table to remove

Return value: none



vector<string> Database::listTable()
Description: Returns a list of all the table names in the database.

Parameters: none

Return value: A vector of type string is returned with the names of all the tables in the database.



map<string, Table*> Database::getTables()
Description: Returns all the tables in the database.

Parameters: none

Return value: A map<string, Table*> is returned with all the tables that are in the database.



Table* Database::query(string select, Table* from, string where)
Description: This is the query funtion for the database.

Parameters:
select: a string list of which attribute names to keep, a null list means keep all
from: the name of the table to query
where: string to parse through that references the attributes

Return value: Returns a Table* that is the result of the query function.



void deleteTuple(string select, Table* from, string where)
Description: Deletes the specified tuples from the table.

Parameters:
select: a string list of which attribute names to keep, a null list means keep all
from: the name of the table to delete the tuples from
where: string to parse through that references the attributes

Return value: none





