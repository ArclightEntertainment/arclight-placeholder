#include <stdio.h>
#include <sqlite3.h>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include "DatabaseInterface.h"

DatabaseInterface::DatabaseInterface()
{

}

DatabaseInterface::~DatabaseInterface()
{

}

int DatabaseInterface::getAnimalCount(){
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
        fprintf(stderr, "Opened databse successfully, rc: %d\n", rc);
    }

    // Get the total amount of Animals
    sql = "SELECT count(*) FROM Animals";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    rc = sqlite3_step(stmt);
    int animalCount = sqlite3_column_int(stmt, 0);

    // Finalize the stamtement, then close the database
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);

    return animalCount;
}

Animal** DatabaseInterface::getDB()
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
        fprintf(stderr, "Opened databse successfully, rc: %d\n", rc);
    }

    // Get the total amount of Animals
    sql = "SELECT count(*) FROM Animals";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    rc = sqlite3_step(stmt);
    int animalCount = sqlite3_column_int(stmt, 0);

    // Initialize the Animal array
    static Animal *animalArray = new Animal[animalCount];

    // Finalize the statement
    rc = sqlite3_finalize(stmt);

    // Get the Animals table
    sql = "SELECT * FROM Animals;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    // Go through each row, create an Animal with the column data, and add them into the array
    int i = 0;
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int shelterID = sqlite3_column_int(stmt, 0);
        std::string animalName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string animalSpecies = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        std::string animalBreed = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        int animalAge = sqlite3_column_int(stmt, 4);
        char animalSex = sqlite3_column_text(stmt, 5)[0];
        int animalTrainingLevel = sqlite3_column_int(stmt, 6);
        int animalAffinityForPeople = sqlite3_column_int(stmt, 7);
        int animalAffinityForChildren = sqlite3_column_int(stmt, 8);
        int animalAffinityForAnimals = sqlite3_column_int(stmt, 9);
        int animalApproacability = sqlite3_column_int(stmt, 10);
        int animalTimeCommitment = sqlite3_column_int(stmt, 11);
        std::string animalDietNeeds = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 12)));
        std::string animalMobilityNeeds = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 13)));
        std::string animalDisabilityNeeds = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 14)));
        std::string animalAbuseHistory = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 15)));
        std::string animalBiography = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 16)));
        animalArray[i] = Animal(shelterID, animalName, animalAge, animalSex, animalSpecies, animalBreed, 1);
        animalArray[i].populateHistory(true, animalDietNeeds, animalMobilityNeeds, animalDisabilityNeeds, animalBiography, animalAbuseHistory);
        animalArray[i].populateSocial(animalTrainingLevel, 1, animalAffinityForPeople, animalAffinityForChildren, animalAffinityForAnimals, animalApproacability, animalTimeCommitment);
        i++;
    }

    // Finalize the stamtement, then close the database
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);
    Animal animal = *&animalArray[0];

    // Return a pointer to the first element in the array
    return &animalArray;
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

    if (sqlite3_open("data/data.db", &db) == SQLITE_OK)
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
