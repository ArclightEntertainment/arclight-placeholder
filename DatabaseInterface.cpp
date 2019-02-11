#include <stdio.h>
#include <sqlite3.h>
#include "DatabaseInterface.h"

DatabaseInterface::DatabaseInterface()
{

}

DatabaseInterface::~DatabaseInterface()
{

}

int DatabaseInterface::getDB()
{
	sqlite3 *db;
	sqlite3_stmt *stmt = 0;
	char const *sql;
	int rc;

	// Open database
	rc = sqlite3_open("data/data.db", &db);

	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
	{
		fprintf(stderr, "Opened databse successfully\n");
	}

	sql = "SELECT * FROM animals;";
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		printf("shelterlID                : %d\n", sqlite3_column_int(stmt, 0));
		printf("animalName                : %s\n", sqlite3_column_text(stmt, 1));
		printf("animalSpecies             : %s\n", sqlite3_column_text(stmt, 2));
		printf("animalBreed               : %s\n", sqlite3_column_text(stmt, 3));
		printf("animalAge                 : %d\n", sqlite3_column_int(stmt, 4));
		printf("animalTrainingLevel       : %d\n", sqlite3_column_int(stmt, 5));
		printf("animalAffinityForPeople   : %d\n", sqlite3_column_int(stmt, 6));
		printf("animalAffinityForChildren : %d\n", sqlite3_column_int(stmt, 7));
		printf("animalAffinityForAnimals  : %d\n", sqlite3_column_int(stmt, 8));
		printf("animalApproachability     : %d\n", sqlite3_column_int(stmt, 9));
		printf("animalTimeCommitment      : %d\n", sqlite3_column_int(stmt, 10));
		printf("animalDietNeeds           : %s\n", sqlite3_column_text(stmt, 11));
		printf("animalMobilityNeeds       : %s\n", sqlite3_column_text(stmt, 12));
		printf("animalDisablityNeeds      : %s\n", sqlite3_column_text(stmt, 13));
		printf("animalAbuseHistory        : %s\n", sqlite3_column_text(stmt, 14));
		printf("animalBiography           : %s\n", sqlite3_column_text(stmt, 15));
		printf("\n");
	}
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;
}
