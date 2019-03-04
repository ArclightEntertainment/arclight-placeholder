#include <stdio.h>
#include <sqlite3.h>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include "DatabaseInterface.h"
#include "./interface/Levels.h"

DatabaseInterface::DatabaseInterface()
{

}

DatabaseInterface::~DatabaseInterface()
{

}

int DatabaseInterface::getAnimalCount()
{
    sqlite3 *db;
    sqlite3_stmt *stmt = 0;
    char const *sql;
    int rc;

    // Open database
    rc = sqlite3_open("data/data.db", &db);

    if (rc)
    {
        fprintf(stderr, "getAnimalCount(): Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    else
    {
        fprintf(stderr, "getAnimalCount(): Opened databse successfully, rc: %d\n", rc);
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

int DatabaseInterface::getClientCount()
{
    sqlite3 *db;
    sqlite3_stmt *stmt = 0;
    char const *sql;
    int rc;

    // Open database
    rc = sqlite3_open("data/data.db", &db);

    if (rc)
    {
        fprintf(stderr, "getClientCount(): Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    else
    {
        fprintf(stderr, "getClientCount(): Opened databse successfully, rc: %d\n", rc);
    }

    // Get the total amount of Clients
    sql = "SELECT count(*) FROM Clients";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    rc = sqlite3_step(stmt);
    int clientCount = sqlite3_column_int(stmt, 0);

    // Finalize the stamtement, then close the database
    rc = sqlite3_finalize(stmt);
    sqlite3_close(db);

    return clientCount;
}

Animal** DatabaseInterface::getAnimalArray()
{
    sqlite3 *db;
    sqlite3_stmt *stmt = 0;
    char const *sql;
    int rc;

    // Open database
    rc = sqlite3_open("data/data.db", &db);

    if (rc)
    {
        fprintf(stderr, "getAnimalArray(): Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr, "getAnimalArray(): Opened databse successfully, rc: %d\n", rc);
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
        ThreeScale animalTrainingLevel = toThreeScale(sqlite3_column_int(stmt, 6));
        ThreeScale animalAffinityForPeople = toThreeScale(sqlite3_column_int(stmt, 7));
        ThreeScale animalAffinityForChildren = toThreeScale(sqlite3_column_int(stmt, 8));
        ThreeScale animalAffinityForAnimals = toThreeScale(sqlite3_column_int(stmt, 9));
        ThreeScale animalApproacability = toThreeScale(sqlite3_column_int(stmt, 10));
        ThreeScale animalTimeCommitment = toThreeScale(sqlite3_column_int(stmt, 11));
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

Client** DatabaseInterface::getClientArray()
{
    sqlite3 *db;
    sqlite3_stmt *stmt = 0;
    char const *sql;
    int rc;

    // Open database
    rc = sqlite3_open("data/data.db", &db);

    if (rc)
    {
        fprintf(stderr, "getClientArray(): Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr, "getClientArray(): Opened databse successfully, rc: %d\n", rc);
    }

    // Get the total amount of Clients
    sql = "SELECT count(*) FROM Clients";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    rc = sqlite3_step(stmt);
    int clientCount = sqlite3_column_int(stmt, 0);

    // Initialize the Client array
    static Client *clientArray = new Client[clientCount];

    // Finalize the statement
    rc = sqlite3_finalize(stmt);

    // Get the Clients table
    sql = "SELECT * FROM Clients JOIN Address WHERE clientID = addressClientID;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    // Go through each row, create an Client with the column data, and add them into the array
    int i = 0;
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int clientID = sqlite3_column_int(stmt, 0);
        std::string clientFName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string clientLName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        std::string clientPrefTitle = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        std::string clientPhoneNumber = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        int clientAge = sqlite3_column_int(stmt, 5);
        int clientHasChildrenUnderTwelve = sqlite3_column_int(stmt, 6); // 0 is false, 1 is true
        int clientLengthOfOwnershipExpectation = sqlite3_column_int(stmt, 7);
        int clientMonthlyBudgetForAnimal = sqlite3_column_int(stmt, 8);
        int clientLivingSpaceSquareFeet = sqlite3_column_int(stmt, 9);
        int clientAvailabilityPerDay = sqlite3_column_int(stmt, 10);
        FiveScale clientLevelOfMobility = toFiveScale(sqlite3_column_int(stmt, 11));
        FiveScale clientLevelOfEnergy = toFiveScale(sqlite3_column_int(stmt, 12));
        FiveScale clientLevelOfPatience = toFiveScale(sqlite3_column_int(stmt, 13));
        FiveScale clientPreviousExperience = toFiveScale(sqlite3_column_int(stmt, 14));
        FiveScale clientPhysicalAffection = toFiveScale(sqlite3_column_int(stmt, 15));
        std::string addressStreetLine1 = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 17)));
        std::string addressStreetLine2 = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 18)));
        std::string addressCity = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 19)));
        std::string addressSubnationalDivision = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 20)));
        std::string addressCountry = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 21)));
        std::string addressPostalCode = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 22)));
        clientArray[i] = Client(clientID, clientPrefTitle, clientFName, clientLName, clientPhoneNumber);
        clientArray[i].populateAddress(addressStreetLine1, addressStreetLine2, addressCity, addressSubnationalDivision, addressCountry, addressPostalCode);
        clientArray[i].populateProfile(clientAge, clientHasChildrenUnderTwelve, clientLengthOfOwnershipExpectation, clientMonthlyBudgetForAnimal,
                                       clientAvailabilityPerDay, clientLevelOfMobility, clientLevelOfEnergy,
                                       clientLevelOfPatience, clientPreviousExperience, clientPhysicalAffection);
        i++;

        //std::cout << clientFName << " " << clientLName << " " << clientID;
    }
    sqlite3_close_v2(db);
    return &clientArray;
}

int DatabaseInterface::pushDBAnimal(Animal &animal)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open("data/data.db", &db) == SQLITE_OK)
    {
        std::string sql = "INSERT OR REPLACE INTO Animals (shelterID, animalName, animalSpecies, animalBreed, animalAge, animalSex, animalTrainingLevel, animalTrainabilityLevel, animalAffinityForPeople, animalAffinityForChildren, animalAffinityForAnimals, animalApproachability, animalTimeCommitment, animalDietNeeds, animalMobilityNeeds, animalDisablityNeeds, animalAbuseHistory, animalBiography) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if (rc == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, animal.getShelterID());
            sqlite3_bind_text(stmt, 2, animal.getName().c_str(),  animal.getName().length(),  SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, animal.getSpecies().c_str(), animal.getSpecies().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, animal.getBreed().c_str(), animal.getBreed().length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 5, animal.getAge());
            char sex = animal.getSex();
            char *psex = &sex;
            sqlite3_bind_text(stmt, 6, psex, 1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 7, animal.getTrainingLevel());
            sqlite3_bind_int(stmt, 8, animal.getTrainabilityLevel());
            sqlite3_bind_int(stmt, 9, animal.getAffForPeople());
            sqlite3_bind_int(stmt, 10, animal.getAffForChildren());
            sqlite3_bind_int(stmt, 11, animal.getAffForAnimals());
            sqlite3_bind_int(stmt, 12, animal.getApproachability());
            sqlite3_bind_int(stmt, 13, animal.getTimeCommitment());
            sqlite3_bind_text(stmt, 14, animal.getDietNeeds().c_str(), animal.getDietNeeds().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 15, animal.getMobilityNeeds().c_str(), animal.getMobilityNeeds().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 16, animal.getDisabilityNeeds().c_str(), animal.getSpecies().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 17, animal.getAbuseHistory().c_str(), animal.getAbuseHistory().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 18, animal.getBiography().c_str(), animal.getBiography().length(), SQLITE_TRANSIENT);

            std::cout << sql << std::endl;

            if (sqlite3_step(stmt) != SQLITE_DONE){std::cout << "Didn't Insert Item!" << std::endl;}
            sqlite3_finalize(stmt);

        }
        else
        {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            return -1;
        }
        sqlite3_close_v2(db);
    }
    return 0;
}

int DatabaseInterface::pushDBClient(Client &client)
{
    sqlite3 *db;
    sqlite3_stmt *stmt = 0;
    if (sqlite3_open("data/data.db", &db) == SQLITE_OK)
    {
        std::string sql = "INSERT OR REPLACE INTO Clients(clientID, clientFName, clientLName, clientPrefTitle, clientPhoneNumber, clientAge, clientHasChildrenUnderTwelve, clientLengthOfOwnershipExpectation, clientMonthlyBudgetForAnimal, clientLivingSpaceSquareFeet, clientAvailabilityPerDay, clientLevelOfMobility, clientLevelOfEnergy, clientLevelOfPatience, clientPreviousExperience, clientPhysicalAffection)VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if(rc == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, client.getClientID());
            sqlite3_bind_text(stmt, 2, client.getFirstName().c_str(), client.getFirstName().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, client.getLastName().c_str(), client.getLastName().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, client.getTitle().c_str(), client.getTitle().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 5, client.getPhoneNumber().c_str(), client.getPhoneNumber().length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 6, client.getClientProfile().getAge());
            sqlite3_bind_int(stmt, 7, client.getClientProfile().getHasChildrenUnderTwelve());
            sqlite3_bind_int(stmt, 8, client.getClientProfile().getLengthOfOwnershipExpectation());
            sqlite3_bind_int(stmt, 9, client.getClientProfile().getBudgetPerMonth());
            sqlite3_bind_int(stmt, 10, 0);
            sqlite3_bind_int(stmt, 11, client.getClientProfile().getTimeAvailabilityPerDay());
            sqlite3_bind_int(stmt, 12, client.getClientProfile().getLevelOfMobility());
            sqlite3_bind_int(stmt, 13, client.getClientProfile().getLevelOfEnergy());
            sqlite3_bind_int(stmt, 14, client.getClientProfile().getLevelOfPatience());
            sqlite3_bind_int(stmt, 15, client.getClientProfile().getPreviousExperience());
            sqlite3_bind_int(stmt, 16, client.getClientProfile().getPhysicalAffection());
        }
        rc = sqlite3_finalize(stmt);

        sql = "INSERT OR REPLACE INTO Address(addressClientID, addressStreetLine1, addressStreetLine2, addressCity, addressSubnationalDivision, addressCountry, addressPostalCode)VALUES(?, ?, ?, ?, ?, ?, ?)";
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if(rc == SQLITE_OK)
        {
            Address adr = client.getAddress();
            sqlite3_bind_int(stmt, 1, client.getClientID());
            sqlite3_bind_text(stmt, 2, adr.getStreetLine1().c_str(), adr.getStreetLine1().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, adr.getStreetLine2().c_str(), adr.getStreetLine2().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, adr.getCity().c_str(), adr.getCity().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 5, adr.getSubnationalDivision().c_str(), adr.getSubnationalDivision().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 6, adr.getCountry().c_str(), adr.getCountry().length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 7, adr.getPostalCode().c_str(), adr.getPostalCode().length(), SQLITE_TRANSIENT);
        }
        rc = sqlite3_finalize(stmt);
        sqlite3_close_v2(db);
    }
}
