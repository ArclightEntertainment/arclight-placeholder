#include <stdio.h>
#include <sqlite3.h>
#include <string>

int main(int argc, char* argv[]){
	sqlite3 *db;
	sqlite3_stmt *stmt = 0;
	char *sql;
	int rc;

	// Open database
	rc = sqlite3_open("data.db", &db);

	if(rc){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}else{
		fprintf(stderr, "Opened databse successfully\n");
	}

	sql = "SELECT * FROM animals;";
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	while( (rc = sqlite3_step(stmt)) == SQLITE_ROW){
		printf("animalID                  : %d\n", sqlite3_column_int(stmt, 0));
		printf("animalName                : %s\n", sqlite3_column_text(stmt, 1));
		printf("animalAge                 : %d\n", sqlite3_column_int(stmt, 2));
		printf("animalTrainingLevel       : %d\n", sqlite3_column_int(stmt, 3));
		printf("animalAffinityForPeople   : %d\n", sqlite3_column_int(stmt, 4));
		printf("animalAffinityForChildren : %d\n", sqlite3_column_int(stmt, 5));
		printf("animalAffinityForAnimals  : %d\n", sqlite3_column_int(stmt, 6));
		printf("animalApproachability     : %d\n", sqlite3_column_int(stmt, 7));
		printf("animalTimeCommitment      : %d\n", sqlite3_column_int(stmt, 8));
		printf("animalDietNeeds           : %s\n", sqlite3_column_text(stmt, 9));
		printf("animalMobilityNeeds       : %s\n", sqlite3_column_text(stmt, 10));
		printf("animalDisablityNeeds      : %s\n", sqlite3_column_text(stmt, 11));
		printf("animalAbuseHistory        : %s\n", sqlite3_column_text(stmt, 12));
		printf("animalBiography           : %s\n", sqlite3_column_text(stmt, 13));
		printf("\n");
	}
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;
}
