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

void CUACSController::printAnimalList()
{
    if(isDBOpen)
    {
        std::cout << dbController->setSQL("SELECT * FROM Animal;") << std::endl;
        while(dbController->step())
        {
            int colType;
            while((colType = dbController->stepCol()) != -1)
            {
                std::cout << dbController->getColName() << ": ";
                if(colType == DatabaseController::DB_STRING)
                {
                    std::cout << dbController->getStringCol();
                }
                else if(colType == DatabaseController::DB_INTEGER)
                {
                    std::cout << dbController->getIntCol();
                }
                std::cout << std::endl;
            }
            std::cout << "---------------------------------------"<< std::endl;
        }
    }
}
