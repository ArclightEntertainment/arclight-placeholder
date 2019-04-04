#include "CUACSController.h"

const std::string DB_PATH = "../data/data.db";

CUACSController::CUACSController()
{
    dbController = new DatabaseController();
    isDBOpen = dbController->openDB("data/data.db");

    animalCollection = ArrayCollection<UAnimal*>();
    clientCollection = ArrayCollection<UClient*>();
}

CUACSController::~CUACSController()
{


}

Iterator<UClient*>* CUACSController::getClientIterator()
{
    if(isDBOpen)
    {
        dbController->setSQL("SELECT id, fName, hasChildrenUnderTwelve, hasPets, age, lName, prefTitle, phoneNumber, streetLine1, streetLine2, city, subnationalDivision, country, postalCode, lengthOfOwnershipExpectation, monthlyBudgetForAnimal, availabilityPerDay, levelOfMobility, levelOfPatience, previousExperience, physicalAffection FROM Client JOIN Address WHERE Client.id = Address.clientID");
        while(dbController->step())
        {
            entity = new ClientBuilder();
            while(dbController->stepCol() != -1)
            {
                int currCol = dbController->getCurrCol();
                std::string colName = dbController->getColName();
                switch(currCol)
                {
                  case 0:
                  {
                      entity->setID(dbController->getIntCol());
                      break;
                  }
                  case 1:
                  {
                      entity->setName(dbController->getStringCol());
                      break;
                  }
                  case 4:
                  {
                      entity->setAge(dbController->getIntCol());
                      break;
                  }
                  case 2:
                  case 3:
                  {
                    bool colValue = dbController->getIntCol();
                    Description<bool> desc = Description<bool>(colName, currCol, colValue);
                    entity->addBoolDesc(desc);
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
                    entity->addStringDesc(desc);
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
                    entity->addIntDesc(desc);
                    break;
                  }

                }
            }
            UClient* client = (UClient*)entity->build();
            std::cout << "Test:" << client->getName()<< std::endl;
            if(client != NULL)
            {
                clientCollection.append(client);
            }
        }
        return clientCollection.createIterator();
    }
}

Iterator<UAnimal*>* CUACSController::getAnimalIterator()
{
    //std::cout << "getAnimalIterator()" << std::endl;
    if(isDBOpen)
    {
        dbController->setSQL("SELECT * FROM Animal");
        dbController->step();
        while(dbController->step())
        {
            entity = new AnimalBuilder();
            while(dbController->stepCol() != -1)
            {
                int currCol = dbController->getCurrCol();
                std::string colName = dbController->getColName();
                switch(currCol)
                {
                    case 0:
                    {
                        entity->setID(dbController->getIntCol());
                        break;
                    }
                    case 1:
                    {
                        entity->setName(dbController->getStringCol());
                        break;
                    }
                    case 4:
                    {
                        entity->setAge(dbController->getIntCol());
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
                        entity->addIntDesc(desc);
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
                        entity->addStringDesc(desc);
                        break;
                    }
                    case 7:
                    {
                        bool colValue = dbController->getIntCol();
                        Description<bool> desc = Description<bool>(colName, currCol, colValue);
                        entity->addBoolDesc(desc);
                        break;
                    }
                }
            }
            UAnimal* animal = (UAnimal*)entity->build();
            //std::cout << animal->getName() << std::endl;
            if(animal != NULL){
                animalCollection.append(animal);
            }
        }
        return animalCollection.createIterator();
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
    entity->reset();
    entity->setID(id);
    entity->addIntDesc(Description<int>("id", 0, id));
    entity->addIntDesc(Description<int>("expenditure", 22, expenditure));
    entity->setName(name);
    entity->addStringDesc(Description<std::string>("name", 1, name));
    entity->setAge(age);
    entity->addIntDesc(Description<int>("age", 4, age));
    entity->addIntDesc(Description<int>("lifeExpetancy", 5, maxAge));
    entity->addStringDesc(Description<std::string>("sex", 6, sex));
    entity->addStringDesc(Description<std::string>("species", 2, species));
    entity->addStringDesc(Description<std::string>("breed", 3, breed));
    entity->addIntDesc(Description<int>("levelOfCare", 8, care));
    entity->addIntDesc(Description<int>("levelOfEnergy", 9, energy));

    std::cout<<entity->getEntity()->getName()<<std::endl;
}
void CUACSController::updateAnimalSocial (int training,int trainability,int people,int child,int animal,int approach,int time)
{
    //int training,int trainability,int people,int child,int animal,int approach,int time
    entity->addIntDesc(Description<int>("trainingLevel", 10, training));
    entity->addIntDesc(Description<int>("trainabilityLevel", 11, trainability));
    entity->addIntDesc(Description<int>("affinityForPeople", 12, people));
    entity->addIntDesc(Description<int>("affinityForChildren", 13, child));
    entity->addIntDesc(Description<int>("affinityForAnimals", 14, animal));
    entity->addIntDesc(Description<int>("approachability", 15, approach));
    entity->addIntDesc(Description<int>("timeCommitment", 16, time));

}
void CUACSController::updateAnimalHistory (bool imm,std::string diet,std::string mob,std::string disab,std::string bio,std::string aHist)
{
    //bool imm,std::string diet,std::string mob,std::string disab,std::string bio,std::string aHist

    entity->addBoolDesc(Description<bool>("immunized", 7, imm));
    entity->addStringDesc(Description<std::string>("dietNeeds", 17, diet));
    entity->addStringDesc(Description<std::string>("mobilityNeeds", 18, mob));
    entity->addStringDesc(Description<std::string>("disabilityNeeds", 19, disab));
    entity->addStringDesc(Description<std::string>("abuseHistory", 20, aHist));
    entity->addStringDesc(Description<std::string>("biography", 21, bio));
}

void CUACSController::finalizeAnimal()
{
    UAnimal * newAnimal = (UAnimal*)entity->build();
    if (newAnimal != NULL)
    {
        animalCollection.append(newAnimal);
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
    entity->reset();
    entity->addStringDesc(Description<std::string>("prefTitle", 3, t));
    entity->addIntDesc(Description<int>("id", 0, iD));
    entity->addStringDesc(Description<std::string>("fName", 1, fn));
    entity->addStringDesc(Description<std::string>("lName", 2, ln));
    entity->addStringDesc(Description<std::string>("phoneNumber", 4, pn));
}
void CUACSController::populateClientAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc)
{
    entity->addStringDesc(Description<std::string>("streetLine1",15,sl1));
    entity->addStringDesc(Description<std::string>("streetLine1",16,sl2));
    entity->addStringDesc(Description<std::string>("city",17,ct));
    entity->addStringDesc(Description<std::string>("subnationalDivision",18,sub));
    entity->addStringDesc(Description<std::string>("country",19,c));
    entity->addStringDesc(Description<std::string>("postalCode",20,pc));
}
void CUACSController::populateClientProfile(Entity * en, int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, int lOfMobility, int lOfPatience, int prevExp, int physAffect)
{
//int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget,
//int timeAvail, int lOfMobility, int lOfPatience, int prevExp, int physAffect)
    en->addIntDesc(Description<int>("age", 5, a));
    en->addBoolDesc(Description<bool>("hasChildrenUnderTwelve", 6, hasUnderTwelve));
    en->addBoolDesc(Description<bool>("hasPets", 7, hasPet));
    en->addIntDesc(Description<int>("lengthOfOwnershipExpectation", 8, ownExp));
    en->addIntDesc(Description<int>("monthlyBudgetForAnimal", 9, budget));
    en->addIntDesc(Description<int>("availabilityPerDay", 10, timeAvail));
    en->addIntDesc(Description<int>("levelOfMobility", 11, lOfMobility));
    en->addIntDesc(Description<int>("levelOfPatience", 12, lOfPatience));
    en->addIntDesc(Description<int>("previousExperience", 13, prevExp));
    en->addIntDesc(Description<int>("physicalAffection", 14, physAffect));
    en->addBoolDesc(Description<bool>("profilePopulated", 99, true));
}
void CUACSController::finalizeClient()
{

}
