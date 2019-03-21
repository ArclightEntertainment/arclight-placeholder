#include "../data/DatabaseController.h"
#include "./CUACSController.h"
#include <iostream>

int main(int argc, char *argv[])
{
	CUACSController mediator = CUACSController();
	Iterator<UAnimal*>* animalIterator = mediator.getAnimalIterator();
	int i =0;
	while(!animalIterator->isDone())
	{
		std::string name = animalIterator->currentItem()->getName();
		std::cout << name << std::endl;

		animalIterator->next();
	}
	return 0;
}
