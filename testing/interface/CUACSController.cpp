#include "CUACSController.h"

const std::string DB_PATH = "../data/data.db";

CUACSController::CUACSController()
{
    dbController = new DatabaseController();
    isDBOpen = dbController->openDB("data/data.db");

    animalBuilder = new AnimalBuilder();
}

CUACSController::~CUACSController()
{

}

Iterator<UAnimal*>* CUACSController::getAnimalIterator()
{
    //std::cout << "getAnimalIterator()" << std::endl;
    if(isDBOpen)
    {
        ArrayCollection<UAnimal*> animalCollection;
        dbController->setSQL("SELECT * FROM Animal");
        dbController->step();
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
