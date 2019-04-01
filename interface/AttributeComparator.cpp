#include <cstdlib>
#include <ctime>
#include "AttributeComparator.h"


float AttributeComparator::calculateCompatibility(UAnimal *animal, UClient *client)
{
    //Temporary
    float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX)); //1.0;
    return random;
}
