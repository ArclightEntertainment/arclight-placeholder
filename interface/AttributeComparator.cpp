#include <cstdlib>
#include <ctime>
#include "AttributeComparator.h"


float AttributeComparator::calculateCompatibility(UAnimal *animal, UClient *client)
{
    //float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX));
    //return random;

    //Temporary
    float totalRating = 0.0f;
    float overCost = (animal->getInt(22) - client->getInt(15))/client->getInt(15);

    if(overCost < 0){
        overCost = 0.0f;
    }
    if(overCost > 0.25)
    {
        return -1;
    }

    if(animal->getInt(14) == 0 && client->getBool(2))
    {
        return -1;
    }

    if(client->getInt(14) - (animal->getInt(5) - animal->getInt(3)) > 4 || client->getInt(14) - (animal->getInt(5) - animal->getInt(3)) < -4.0f)
        return -1;

    if(client->getInt(18) - (4 - animal->getInt(12)*2) < 0)
    {
        totalRating += (4 - animal->getInt(12)*2 - client->getInt(18)) * 0.04f;
    }


    if(client->getInt(20) - (4 - animal->getInt(12)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(12)*2) - client->getInt(20)) * 0.06f;
    }

    if(client->getInt(19) - animal->getInt(8)*2 < 0)
    {
        totalRating += ((animal->getInt(8)*2) - client->getInt(19)) * 0.04f;
    }

    if(client->getInt(19) - (4 - animal->getInt(10)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(10)*2) - client->getInt(19)) * 0.06f;
    }


    if(client->getInt(18) - (4 - animal->getInt(11)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(11)*2) - client->getInt(18)) * 0.04f;
    }

    if(client->getInt(19) - (4 - animal->getInt(11)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(11)*2) - client->getInt(19)) * 0.04f;
    }

    if(client->getInt(18) - (4 - animal->getInt(15)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(15)*2) - client->getInt(18)) * 0.06f;
    }

    if(client->getInt(19) - (4 - animal->getInt(15)*2) < 0)
    {
        totalRating += ((4 - animal->getInt(15)*2) - client->getInt(19)) * 0.02f;
    }

    if(client->getInt(17) - animal->getInt(8)*2 < 0)
    {
        totalRating += ((animal->getInt(8)*2) - client->getInt(17)) * 0.06f;
    }

    if(client->getInt(17) - (4-animal->getInt(10)*2) < 0)
    {
        totalRating += (4-(animal->getInt(10)*2) - client->getInt(17)) * 0.02f;
    }

    if(client->getInt(18) - (4-animal->getInt(10)*2) < 0)
    {
        totalRating += (4-(animal->getInt(10)*2) - client->getInt(18)) * 0.06f;
    }

    if(client->getInt(17) - animal->getInt(9)*2 < 0)
    {
        totalRating += ((animal->getInt(9)*2) - client->getInt(17)) * 0.06f;
    }

    if((client->getInt(16) / 30) - (4-animal->getInt(10)*2))
    {
        totalRating += ((4-animal->getInt(10)*2) - (client->getInt(16) / 30)) * 0.04f;
    }

    if(animal->getInt(16) == 0 && 15 - client->getInt(16) > 0)
    {
        totalRating += ((15.0f - client->getInt(16))/15.0f) * 4 * 0.06;
    }
    else if(animal->getInt(16) == 1 && 60 - client->getInt(16) > 0)
    {
        totalRating += ((60.0f - client->getInt(16))/60.0f) * 4 * 0.06;
    }
    else if(animal->getInt(16) == 2 && 150 - client->getInt(16) > 0)
    {
        totalRating += ((150.0f - client->getInt(16))/150.0f) * 4 * 0.06;
    }


    if((client->getInt(16) / 30) - (4-animal->getInt(11)*2))
    {
        totalRating += (4-(animal->getInt(11)*2) - (client->getInt(16) / 30)) * 0.04f;
    }

    if(animal->getInt(8) == 0 && 15 - client->getInt(16) > 0)
    {
        totalRating += ((15.0f - client->getInt(16))/15.0f) * 4 * 0.06;
    }
    else if(animal->getInt(8) == 1 && 60 - client->getInt(16) > 0)
    {
        totalRating += ((60.0f - client->getInt(16))/60.0f) * 4 * 0.06;
    }
    else if(animal->getInt(8) == 2 && 150 - client->getInt(16) > 0)
    {
        totalRating += ((150.0f - client->getInt(16))/150.0f) * 4 * 0.06;
    }

    if(overCost > 0 && overCost < 0.25f)
        totalRating += overCost * 16 * 0.06;

    if(client->getBool(3))
        totalRating += (4-animal->getInt(14)*2)*0.06;

    if(client->getBool(2))
        totalRating += (4-animal->getInt(13)*2)*0.06;

    if(client->getInt(14) - (animal->getInt(5) - animal->getInt(3)) > 0)
        totalRating += (client->getInt(14) - (animal->getInt(5) - animal->getInt(3))) * 0.06;

    else if(client->getInt(14) - (animal->getInt(5) - animal->getInt(3)) < 0)
        totalRating += -1.0f * (client->getInt(14) - (animal->getInt(5) - animal->getInt(3))) * 0.06;

    //float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX)); //1.0;


    return 100.0f - ((totalRating * 100.0f)/4.0f);

}
