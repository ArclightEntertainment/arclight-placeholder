#include "../data/DatabaseController.h"
#include "./CUACSController.h"
#include <iostream>

int main(int argc, char *argv[])
{
	CUACSController mediator = CUACSController();
	mediator.printAnimalList();
	return 0;
}
