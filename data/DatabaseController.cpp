#include "DatabaseController.h"

const int DatabaseController::DB_INTEGER = 1; // Same value as SQLITE_INTEGER
const int DatabaseController::DB_STRING  = 3; // Same value as SQLITE_TEXT/SQLITE3_TEXT
DatabaseController::DatabaseController()
{
	isDBOpen = false;
	hasSQL = false;
	colCount = -1;
	currCol = -1;
}

DatabaseController::~DatabaseController()
{
	if(isDBOpen)
	{
		if(hasSQL){
			sqlite3_finalize(stmt);
		}
		sqlite3_close_v2(db);
	}
}

bool DatabaseController::openDB(std::string path)
{
	if(sqlite3_open_v2(path.c_str(), &db, SQLITE_OPEN_READWRITE, NULL) == SQLITE_OK)
	{
		isDBOpen = true;
		return true;
	}
	else { return false; }
}

bool DatabaseController::setSQL(std::string s)
{
	if(isDBOpen)
    {
		if(hasSQL)
		{
			sqlite3_finalize(stmt);
        }
		sql = s;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
		if(rc == SQLITE_OK)
        {
			hasSQL = true;
			colCount = sqlite3_column_count(stmt);
			return true;
		}
		else
        {
			hasSQL = false;
			sqlite3_finalize(stmt);
			return false;
		}
	}
	else { return false; }
}

int DatabaseController::getColCount() { return colCount; }

int DatabaseController::getCurrCol() { return currCol; }

bool DatabaseController::step()
{
	if(hasSQL)
    {
        rc = sqlite3_step(stmt);
        if(rc != SQLITE_ROW)
        {
            sqlite3_finalize(stmt);
            hasSQL = false;
			return false;
		}
		else { return true; }
	} else { return false; }
}

int DatabaseController::stepCol()
{
	if(currCol < colCount-1)
	{
		currCol++;
		return sqlite3_column_type(stmt, currCol);
	}
	else
	{
		currCol = -1;
		return -1;
	}
}

std::string DatabaseController::getColName()
{
	return std::string(reinterpret_cast<const char*>(sqlite3_column_name(stmt, currCol)));
}

int DatabaseController::getIntCol()
{
	if(sqlite3_column_type(stmt, currCol) == SQLITE_INTEGER)
	{
		return sqlite3_column_int(stmt, currCol);
	}
	else { return -1; }
}

std::string DatabaseController::getStringCol()
{
	if(sqlite3_column_type(stmt, currCol) == SQLITE3_TEXT)
	{
		return std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, currCol)));
	}
	else { return NULL; }
}
