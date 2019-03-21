#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <sqlite3.h>
#include <string>
#include <iostream>

class DatabaseController
{
public:
	DatabaseController();
	~DatabaseController();
	static const int DB_INTEGER; // Same value as SQLITE_INTEGER
	static const int DB_STRING; // Same value as SQLITE_TEXT/SQLITE3_TEXT

	bool openDB(std::string path); // Returns if the db was opened
	bool setSQL(std::string s); // Returns if the SQL has rows
	int getColCount(); // Returns the amount of cols in the rows
	int getCurrCol(); // Returns the currCol index
	bool step(); // Advances to the next row or pushs an insert/update, returns false when it advances past the last row
	int stepCol(); // Advances to the next col, returns the type of that col
	std::string getColName(); // Get the name of the current column
	int getIntCol(); // Gets an int out of the current column
	std::string getStringCol(); // Gets a string out of the current column
private:
	sqlite3 *db;
	sqlite3_stmt *stmt;
	std::string sql;
	int rc;
	int currCol;
	int colCount;
	bool isDBOpen;
	bool hasSQL;
};
#endif
