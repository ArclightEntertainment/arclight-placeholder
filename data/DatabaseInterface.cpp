#include <stdio.h>
#include <sqlite3.h>
#include <sstream>
#include <iostream>
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
    rc = sqlite3_open("./data.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr, "Opened databse successfully\n");
    }

    sql = "SELECT * FROM Animals;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    printf("test print");
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
    sqlite3_close_v2(db);
    return 0;
}

int DatabaseInterface::pushDBAnimal(Animal &animal)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    //int rc;

    /*// Open database
    rc = sqlite3_open("data.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr, "Opened databse successfully\n");
    }

    std::string sep = ", ";
    std::string strsep = "'";
    /*std::string sql =
            std::string("INSERT OR REPLACE INTO Animals(shelterID, animalName, animalSpecies, animalBreed, animalAge, animalSex, animalTrainingLevel, animalAffinityForPeople, animalAffinityForChildren, animalAffinityForAnimals, animalApproachability, animalTimeCommitment, animalDietNeeds, animalMobilityNeeds, animalDisablityNeeds, animalAbuseHistory, animalBiography) VALUES(")
            + animal.getShelterID() + sep
            + animal.getName() + sep
            + animal.getSpecies() + sep
            + animal.getBreed() + sep
            + animal.getAge() + sep
            + animal.getSex() + sep
            + animal.getTrainingLevel() + sep
            + animal.getAffForPeople() + sep
            + animal.getAffForChildren() + sep
            + animal.getAffForAnimals() + sep
            + animal.getApproachability() + sep
            + animal.getTimeCommitment() + sep
            + animal.getDietNeeds() + sep
            + animal.getMobilityNeeds() + sep
            + animal.getDisabilityNeeds() + sep
            + animal.getAbuseHistory() + sep
            + animal.getBiography() + std::string(");");*/

    /*std::ostringstream sql;
    sql << "INSERT OR REPLACE INTO Animals(shelterID, animalName, animalSpecies, animalBreed, animalAge, animalSex, animalTrainingLevel, animalAffinityForPeople, animalAffinityForChildren, animalAffinityForAnimals, animalApproachability, animalTimeCommitment, animalDietNeeds, animalMobilityNeeds, animalDisablityNeeds, animalAbuseHistory, animalBiography) VALUES( "
        << animal.getShelterID() << sep
        << strsep << animal.getName() << strsep << sep
        << strsep << animal.getSpecies() << strsep << sep
        << strsep << animal.getBreed() << strsep << sep
        << animal.getAge() << sep
        << strsep << animal.getSex() << strsep << sep
        << animal.getTrainingLevel() << sep
        << animal.getAffForPeople() << sep
        << animal.getAffForChildren() << sep
        << animal.getAffForAnimals() << sep
        << animal.getApproachability() << sep
        << animal.getTimeCommitment() << sep
        << strsep << animal.getDietNeeds() << strsep << sep
        << strsep << animal.getMobilityNeeds() << strsep << sep
        << strsep << animal.getDisabilityNeeds() << strsep << sep
        << strsep << animal.getAbuseHistory() << strsep << sep
        << strsep << animal.getBiography() <<  strsep << ");";

    std::cout << sql.str() << std::endl;*/

    if (sqlite3_open("./data.db", &db) == SQLITE_OK)
    {

        std::string sql = "INSERT OR REPLACE INTO Animals (shelterID, animalName, animalSpecies, animalBreed, animalAge, animalSex, animalTrainingLevel, animalAffinityForPeople, animalAffinityForChildren, animalAffinityForAnimals, animalApproachability, animalTimeCommitment, animalDietNeeds, animalMobilityNeeds, animalDisablityNeeds, animalAbuseHistory, animalBiography) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if (rc == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, animal.getShelterID());
            std::cout << sql << std::endl;
            sqlite3_bind_text(stmt, 2, animal.getName().c_str(),  animal.getName().length(),  SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, animal.getSpecies().c_str(), animal.getSpecies().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, animal.getBreed().c_str(), animal.getBreed().length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 5, animal.getAge());
            char sex = animal.getSex();
            char *psex = &sex;
            sqlite3_bind_text(stmt, 6, psex, 1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 7, animal.getTrainingLevel());
            sqlite3_bind_int(stmt, 8, animal.getAffForPeople());
            sqlite3_bind_int(stmt, 9, animal.getAffForChildren());
            sqlite3_bind_int(stmt, 10, animal.getAffForAnimals());
            sqlite3_bind_int(stmt, 11, animal.getApproachability());
            sqlite3_bind_int(stmt, 12, animal.getTimeCommitment());
            sqlite3_bind_text(stmt, 13, animal.getDietNeeds().c_str(), animal.getDietNeeds().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 14, animal.getMobilityNeeds().c_str(), animal.getMobilityNeeds().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 15, animal.getDisabilityNeeds().c_str(), animal.getSpecies().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 16, animal.getAbuseHistory().c_str(), animal.getAbuseHistory().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 17, animal.getBiography().c_str(), animal.getBiography().length(), SQLITE_TRANSIENT);
            /*
            << animal.getAge() << sep
            << strsep << animal.getSex() << strsep << sep
            << animal.getTrainingLevel() << sep
            << animal.getAffForPeople() << sep
            << animal.getAffForChildren() << sep
            << animal.getAffForAnimals() << sep
            << animal.getApproachability() << sep
            << animal.getTimeCommitment() << sep
            << strsep << animal.getDietNeeds() << strsep << sep
            << strsep << animal.getMobilityNeeds() << strsep << sep
            << strsep << animal.getDisabilityNeeds() << strsep << sep
            << strsep << animal.getAbuseHistory() << strsep << sep
            << strsep << animal.getBiography() <<  strsep << ");";*/

            std::cout << sql << std::endl;

            //sqlite3_step(stmt);
            if (sqlite3_step(stmt) != SQLITE_DONE) std::cout << "Didn't Insert Item!" << std::endl;;
            sqlite3_finalize(stmt);

        }
        else
        {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        }
        sqlite3_close_v2(db);
    }

    /*sqlite3_prepare(db, sql.str().c_str(), -1, &stmt, NULL);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    std::cout << rc << std::endl;*/
    return 0;
}
