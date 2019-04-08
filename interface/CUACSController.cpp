#include "CUACSController.h"

const std::string DB_PATH = "../data/data.db";

CUACSController::CUACSController()
{
    dbController = new DatabaseController();
    isDBOpen = dbController->openDB("data/data.db");

    animalCollection = ArrayCollection<UAnimal*>();
    clientCollection = ArrayCollection<UClient*>();

    animalBuilder = new AnimalBuilder();
    clientBuilder = new ClientBuilder();

    acmController = new ACMController(30.0f);
}

CUACSController::~CUACSController()
{


}

CandidateSet *CUACSController::launchACM()
{
    acmController->setup(animalCollection.count(), animalCollection.createIterator(), clientCollection.count(), clientCollection.createIterator());
    return acmController->run();
}



Iterator<UAnimal*>* CUACSController::getAnimalIterator()
{
    if(isDBOpen)
    {
        int i = -1;
        dbController->setSQL("SELECT * FROM Animal");
        while(dbController->step())
        {
            animalBuilder->reset();
            while(dbController->stepCol() != -1)
            {
                int currCol = dbController->getCurrCol();
                std::string colName = dbController->getColName();
                switch(currCol)
                {
                    case 0:
                    {
                        animalBuilder->setID(dbController->getIntCol());
                        break;
                    }
                    case 1:
                    {
                        animalBuilder->setName(dbController->getStringCol());
                        break;
                    }
                    case 4:
                    {
                        animalBuilder->setAge(dbController->getIntCol());
                        break;
                    }
                    case 5:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                    {
                        int colValue = dbController->getIntCol();
                        Description<int> desc = Description<int>(colName, currCol, colValue);
                        animalBuilder->addIntDesc(desc);
                        break;
                    }
                    case 2:
                    case 3:
                    case 6:
                    case 17:
                    case 18:
                    case 19:
                    case 20:
                    case 21:
                    {
                        std::string colValue = dbController->getStringCol();
                        Description<std::string> desc = Description<std::string>(colName, currCol, colValue);
                        animalBuilder->addStringDesc(desc);
                        break;
                    }
                    case 7:
                    {
                        bool colValue = dbController->getIntCol();
                        Description<bool> desc = Description<bool>(colName, currCol, colValue);
                        animalBuilder->addBoolDesc(desc);
                        break;
                    }
                }
            }
            UAnimal* animal = (UAnimal*)animalBuilder->build();
            if(animal != NULL){
                animalCollection.append(animal);
            }
        }
        return animalCollection.createIterator();
    }
}

Iterator<UClient*>* CUACSController::getClientIterator()
{
    if(isDBOpen)
    {
        dbController->setSQL("SELECT id, fName, hasChildrenUnderTwelve, hasPets, age, lName, prefTitle, phoneNumber, streetLine1, streetLine2, city, subnationalDivision, country, postalCode, lengthOfOwnershipExpectation, monthlyBudgetForAnimal, availabilityPerDay, levelOfMobility, levelOfPatience, previousExperience, physicalAffection FROM Client JOIN Address WHERE Client.id = Address.clientID");
        while(dbController->step())
        {
            clientBuilder->reset();
            while(dbController->stepCol() != -1)
            {
                int currCol = dbController->getCurrCol();
                std::string colName = dbController->getColName();
                switch(currCol)
                {
                  case 0:
                  {
                      clientBuilder->setID(dbController->getIntCol());
                      break;
                  }
                  case 1:
                  {
                      clientBuilder->setName(dbController->getStringCol());
                      break;
                  }
                  case 4:
                  {
                      clientBuilder->setAge(dbController->getIntCol());
                      break;
                  }
                  case 2:
                  case 3:
                  {
                    bool colValue = dbController->getIntCol();
                    Description<bool> desc = Description<bool>(colName, currCol, colValue);
                    clientBuilder->addBoolDesc(desc);
                    break;
                  }
                  case 5:
                  case 6:
                  case 7:
                  case 8:
                  case 9:
                  case 10:
                  case 11:
                  case 12:
                  case 13:
                  {
                    std::string colValue = dbController->getStringCol();
                    Description<std::string> desc = Description<std::string>(colName, currCol, colValue);
                    clientBuilder->addStringDesc(desc);
                    break;
                  }
                  case 14:
                  case 15:
                  case 16:
                  case 17:
                  case 18:
                  case 19:
                  case 20:
                  {
                    int colValue = dbController->getIntCol();
                    Description<int> desc = Description<int>(colName, currCol, colValue);
                    clientBuilder->addIntDesc(desc);
                    break;
                  }

                }
            }
            UClient* client = (UClient*)clientBuilder->build();
            if(client != NULL)
            {
                clientCollection.append(client);
            }
        }
        return clientCollection.createIterator();
    }
}

Entity * CUACSController::getAnimalWithId(int id)
{
    Iterator<UAnimal*> * iter = createAnimalIterator();

    while (!iter->isDone())
    {
        if (iter->currentItem()->getID() == id)
        {
            return iter->currentItem();
        }
        iter->next();
    }
    return NULL;
}

int CUACSController::getNextAnimalID()
{
    int highest = 0;
    Iterator<UAnimal*> * iter = createAnimalIterator();
    while (!iter->isDone())
    {
        if (iter->currentItem()->getID() > highest)
        {
            highest = iter->currentItem()->getID();
        }
        iter->next();
    }
    return highest+1;
}

Entity * CUACSController::getClientWithId(int id)
{
    Iterator<UClient*> * iter = createClientIterator();

    while (!iter->isDone())
    {
        if (iter->currentItem()->getID() == id)
        {
            return iter->currentItem();
        }
        iter->next();
    }
    return NULL;
}

int CUACSController::getNextClientID()
{
    int highest = 0;
    Iterator<UClient*> * iter = createClientIterator();
    while (!iter->isDone())
    {
        if (iter->currentItem()->getID() > highest)
        {
            highest = iter->currentItem()->getID();
        }
        iter->next();
    }
    return highest+1;
}

/*
**************************************************************************************************************
************************************CREATE ANIMALS************************************************************
**************************************************************************************************************
*/
void CUACSController::addAnimal (int id,int expenditure,std::string name,int age,int maxAge,std::string sex,std::string species,std::string breed,int care,int energy)
{
    animalBuilder->reset();
    animalBuilder->setID(id);
    animalBuilder->addIntDesc(Description<int>("id", static_cast<int>(AnimalAttribute::ID), id));
    animalBuilder->addIntDesc(Description<int>("expenditure", static_cast<int>(AnimalAttribute::MONTHLY_EXPENDITURE), expenditure));
    animalBuilder->setName(name);
    animalBuilder->addStringDesc(Description<std::string>("name", static_cast<int>(AnimalAttribute::NAME), name));
    animalBuilder->setAge(age);
    animalBuilder->addIntDesc(Description<int>("age", static_cast<int>(AnimalAttribute::AGE), age));
    animalBuilder->addIntDesc(Description<int>("lifeExpetancy", static_cast<int>(AnimalAttribute::LIFE_EXPECTANCY), maxAge));
    animalBuilder->addStringDesc(Description<std::string>("sex", static_cast<int>(AnimalAttribute::SEX), sex));
    animalBuilder->addStringDesc(Description<std::string>("species", static_cast<int>(AnimalAttribute::SPECIES), species));
    animalBuilder->addStringDesc(Description<std::string>("breed", static_cast<int>(AnimalAttribute::BREED), breed));
    animalBuilder->addIntDesc(Description<int>("levelOfCare", static_cast<int>(AnimalAttribute::LEVEL_OF_CARE), care));
    animalBuilder->addIntDesc(Description<int>("levelOfEnergy", static_cast<int>(AnimalAttribute::LEVEL_OF_ENERGY), energy));
}

void CUACSController::updateAnimalSocial (int training,int trainability,int people,int child,int animal,int approach,int time)
{
    //int training,int trainability,int people,int child,int animal,int approach,int time
    animalBuilder->addIntDesc(Description<int>("trainingLevel", static_cast<int>(AnimalAttribute::TRAINING_LEVEL), training));
    animalBuilder->addIntDesc(Description<int>("trainabilityLevel", static_cast<int>(AnimalAttribute::TRAINABILITY_LEVEL), trainability));
    animalBuilder->addIntDesc(Description<int>("affinityForPeople", static_cast<int>(AnimalAttribute::AFFINITY_FOR_PEOPLE), people));
    animalBuilder->addIntDesc(Description<int>("affinityForChildren", static_cast<int>(AnimalAttribute::AFFINITY_FOR_CHILDREN), child));
    animalBuilder->addIntDesc(Description<int>("affinityForAnimals", static_cast<int>(AnimalAttribute::AFFINITY_FOR_ANIMALS), animal));
    animalBuilder->addIntDesc(Description<int>("approachability", static_cast<int>(AnimalAttribute::APPROACHABILITY), approach));
    animalBuilder->addIntDesc(Description<int>("timeCommitment", static_cast<int>(AnimalAttribute::TIME_COMMITMENT), time));

}
void CUACSController::updateAnimalHistory (bool imm,std::string diet,std::string mob,std::string disab,std::string bio,std::string aHist)
{
    animalBuilder->addBoolDesc(Description<bool>("immunized", static_cast<int>(AnimalAttribute::IMMUNIZED), imm));
    animalBuilder->addStringDesc(Description<std::string>("dietNeeds", static_cast<int>(AnimalAttribute::DIET_NEEDS), diet));
    animalBuilder->addStringDesc(Description<std::string>("mobilityNeeds", static_cast<int>(AnimalAttribute::MOBILITY_NEEDS), mob));
    animalBuilder->addStringDesc(Description<std::string>("disabilityNeeds", static_cast<int>(AnimalAttribute::DISABILITY_NEEDS), disab));
    animalBuilder->addStringDesc(Description<std::string>("abuseHistory", static_cast<int>(AnimalAttribute::ABUSE_HISTORY), aHist));
    animalBuilder->addStringDesc(Description<std::string>("biography", static_cast<int>(AnimalAttribute::BIOGRAPHY), bio));
}
void CUACSController::finalizeAnimal()
{
    UAnimal * newAnimal = (UAnimal*)animalBuilder->build();
    if (newAnimal != NULL)
    {
        animalCollection.append(newAnimal);

        std::string attributes[22];
        attributes[0] = std::to_string(newAnimal->getID());
        attributes[1] = newAnimal->getName();
        attributes[2] = newAnimal->getString(static_cast<int>(AnimalAttribute::SPECIES));
        attributes[3] = newAnimal->getString(static_cast<int>(AnimalAttribute::BREED));
        attributes[4] = std::to_string(newAnimal->getAge());
        attributes[5] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::LIFE_EXPECTANCY)));
        attributes[6] = newAnimal->getString(static_cast<int>(AnimalAttribute::SEX));
        attributes[7] = std::to_string(newAnimal->getBool(static_cast<int>(AnimalAttribute::IMMUNIZED)));
        attributes[8] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::LEVEL_OF_CARE)));
        attributes[9] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::LEVEL_OF_ENERGY)));
        attributes[10] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::TRAINING_LEVEL)));
        attributes[11] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::TRAINABILITY_LEVEL)));
        attributes[12] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::AFFINITY_FOR_PEOPLE)));
        attributes[13] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::AFFINITY_FOR_CHILDREN)));
        attributes[14] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::AFFINITY_FOR_ANIMALS)));
        attributes[15] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::APPROACHABILITY)));
        attributes[16] = std::to_string(newAnimal->getInt(static_cast<int>(AnimalAttribute::TIME_COMMITMENT)));
        attributes[17] = newAnimal->getString(static_cast<int>(AnimalAttribute::DIET_NEEDS));
        attributes[18] = newAnimal->getString(static_cast<int>(AnimalAttribute::MOBILITY_NEEDS));
        attributes[19] = newAnimal->getString(static_cast<int>(AnimalAttribute::DISABILITY_NEEDS));
        attributes[20] = newAnimal->getString(static_cast<int>(AnimalAttribute::ABUSE_HISTORY));
        attributes[21] = newAnimal->getString(static_cast<int>(AnimalAttribute::BIOGRAPHY));

        std::string sql = "INSERT OR REPLACE INTO Animal(id,name,species,breed,age,lifeExpectancy,sex,immunized,levelOfCare,levelOfEnergy,trainingLevel,trainabilityLevel,affinityForPeople,affinityForChildren,affinityForAnimals,approachability,timeCommitment,dietNeeds,mobilityNeeds,disablityNeeds,abuseHistory,biography)VALUES(";
        for(int i=0; i<22; i++)
        {
            switch(i)
            {
                case 0:
                case 4:
                case 5:
                case 7:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                {
                    sql += attributes[i];
                    break;
                }
                case 6:
                {
                    sql += "\'" + attributes[i] + "\'";
                    break;
                }
                default:
                {
                    sql += "\"" + attributes[i] + "\"";
                    break;
                }
            }
            if(i != 21)
            {
                sql += ",";
            }
        }
        sql += ")";
        dbController->setSQL(sql);
        dbController->step();
    }
}

/*
**************************************************************************************************************
************************************CREATE CLIENTS************************************************************
**************************************************************************************************************
*/
//entity->addIntDesc(Description<int>("timeCommitment", 16, time));
//entity->addIntDesc(Description<bool>("immunized", 7, imm));
//entity->addIntDesc(Description<std::string>("dietNeeds", 17, diet));
void CUACSController::addClient(std::string t, int iD, std::string fn, std::string ln, std::string pn)
{
    /*
    entity->reset();
    entity->addStringDesc(Description<std::string>("prefTitle", static_cast<int>(ClientAttribute::PREF_TITLE), t));
    entity->addIntDesc(Description<int>("id", static_cast<int>(ClientAttribute::ID), iD));
    entity->addStringDesc(Description<std::string>("fName", static_cast<int>(ClientAttribute::FIRST_NAME), fn));
    entity->addStringDesc(Description<std::string>("lName", static_cast<int>(ClientAttribute::LAST_NAME), ln));
    entity->addStringDesc(Description<std::string>("phoneNumber", static_cast<int>(ClientAttribute::PHONE_NUMBER), pn));
    */
}
void CUACSController::populateClientAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc)
{
    /*
    entity->addStringDesc(Description<std::string>("streetLine1",static_cast<int>(ClientAttribute::STREET_LINE_1),sl1));
    entity->addStringDesc(Description<std::string>("streetLine1",static_cast<int>(ClientAttribute::STREET_LINE_2),sl2));
    entity->addStringDesc(Description<std::string>("city",static_cast<int>(ClientAttribute::CITY),ct));
    entity->addStringDesc(Description<std::string>("subnationalDivision",static_cast<int>(ClientAttribute::SUBNATIONAL_DIVISION),sub));
    entity->addStringDesc(Description<std::string>("country",static_cast<int>(ClientAttribute::COUNTRY),c));
    entity->addStringDesc(Description<std::string>("postalCode",static_cast<int>(ClientAttribute::POSTAL_CODE),pc));
    */
}
void CUACSController::populateClientProfile(Entity * en, int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, int lOfMobility, int lOfPatience, int prevExp, int physAffect)
{
//int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget,
//int timeAvail, int lOfMobility, int lOfPatience, int prevExp, int physAffect)
    /*
    std::cout<< a << " " << hasUnderTwelve << " " << hasPet << " " << ownExp << " " << budget << " " << timeAvail << " " << lOfMobility << " " << lOfPatience << " " << prevExp << " " << physAffect <<std::endl;
    en->addIntDesc(Description<int>("age", static_cast<int>(ClientAttribute::AGE), a));
    en->setAge(a);
    en->addBoolDesc(Description<bool>("hasChildrenUnderTwelve", static_cast<int>(ClientAttribute::HAS_CHILDREN_UNDER_TWELVE), hasUnderTwelve));
    en->addBoolDesc(Description<bool>("hasPets", static_cast<int>(ClientAttribute::HAS_PETS), hasPet));
    en->addIntDesc(Description<int>("lengthOfOwnershipExpectation", static_cast<int>(ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION), ownExp));
    en->addIntDesc(Description<int>("monthlyBudgetForAnimal", static_cast<int>(ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL), budget));
    en->addIntDesc(Description<int>("availabilityPerDay", static_cast<int>(ClientAttribute::AVAILABILITY_PER_DAY), timeAvail));
    en->addIntDesc(Description<int>("levelOfMobility", static_cast<int>(ClientAttribute::LEVEL_OF_MOBILITY), lOfMobility));
    en->addIntDesc(Description<int>("levelOfPatience", static_cast<int>(ClientAttribute::LEVEL_OF_PATIENCE), lOfPatience));
    en->addIntDesc(Description<int>("previousExperience", static_cast<int>(ClientAttribute::PREVIOUS_EXPERIENCE), prevExp));
    en->addIntDesc(Description<int>("physicalAffection", static_cast<int>(ClientAttribute::PHYSICAL_AFFECTION), physAffect));
    en->addBoolDesc(Description<bool>("profilePopulated", static_cast<int>(ClientAttribute::POPULATED), true));
    */
}
void CUACSController::finalizeClient()
{
    /*
    UClient * newClient = (UClient*)entity->build();
    if (newClient != NULL)
    {
	clientCollection.append(newClient);
    }
    */
}
