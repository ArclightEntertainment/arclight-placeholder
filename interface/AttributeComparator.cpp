#include <cstdlib>
#include <ctime>
#include "AttributeComparator.h"


float AttributeComparator::calculateCompatibility(UAnimal *animal, UClient *client)
{
    float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX));
    return random;
    /*
    //Temporary
    float totalRating = 0.0f;
    float overCost = (animal->species.eCostPerMonth - client->profile.budgetPerMonth)/client->profile.budgetPerMonth;
    if(overCost < 0){
        overCost = 0.0f;
    }
    if(overCost > 0.25)
    {
        return -1;
    }

    if(animal->affinityForChildren == 0 && client->hasChildrenUnder12)
    {
        return -1;
    }


    if((int)client->profile.levelOfPatience - (4 - (int)animal->affinityForPeople*2) < 0)
    {
        totalRating += ((4 - (int)animal->affinityForPeople*2) - (int)client->profile.levelOfPatience) * 0.04f;
    }

    if((int)client->profile.physicalAffection - (4 - (int)animal->affinityForPeople)*2 < 0)
    {
        totalRating += ((4 - (int)animal->affinityForPeople*2) - (int)client->profile.physicalAffection) * 0.06f;
    }

    if((int)client->profile.previousExperience - (int)animal->levelOfCare*2 < 0)
    {
        totalRating += (((int)animal->levelOfCare*2) - (int)client->profile.previousExperience) * 0.04f;
    }

    if((int)client->profile.previousExperience - (4 - (int)animal->trainingLevel*2) < 0)
    {
        totalRating += ((4 - (int)animal->trainingLevel*2) - (int)client->profile.previousExperience) * 0.06f;
    }

    if((int)client->profile.levelOfPatience - (4 - (int)animal->trainabilityLevel*2) < 0)
    {
        totalRating += ((4 - (int)animal->trainabilityLevel*2) - (int)client->profile.levelOfPatience) * 0.04f;
    }

    if((int)client->profile.previousExperience - (4 - (int)animal->trainabilityLevel*2) < 0)
    {
        totalRating += ((4 - (int)animal->trainabilityLevel*2) - (int)client->profile.previousExperience) * 0.04f;
    }

    if((int)client->profile.levelOfPatience - (4 - (int)animal->approachability*2) < 0)
    {
        totalRating += ((4 - (int)animal->approachability*2) - (int)client->profile.levelOfPatience) * 0.06f;
    }

    if((int)client->profile.previousExperience - (4 - (int)animal->approachability*2) < 0)
    {
        totalRating += ((4 - (int)animal->approachability*2) - (int)client->profile.previousExperience) * 0.02f;
    }

    if((int)client->profile.levelOfMobility - (int)animal->levelOfCare*2 < 0)
    {
        totalRating += (((int)animal->levelOfCare*2) - (int)client->profile.levelOfMobility) * 0.06f;
    }

    if((int)client->profile.levelOfMobility - (4-(int)animal->trainingLevel*2) < 0)
    {
        totalRating += ((4-((int)animal->trainingLevel)*2) - (int)client->profile.levelOfMobility) * 0.02f;
    }

    if((int)client->profile.levelOfPatience - (4-(int)animal->trainingLevel*2) < 0)
    {
        totalRating += ((4-((int)animal->trainingLevel)*2) - (int)client->profile.levelOfPatience) * 0.06f;
    }

    if((int)client->profile.levelOfMobility - (int)animal->levelOfEnergy*2 < 0)
    {
        totalRating += (((int)animal->levelOfEnergy*2) - (int)client->profile.levelOfMobility) * 0.06f;
    }

    if((client->profile.timeAvailabilityPerDay / 30) - (4-(int)animal->trainingLevel*2))
    {
        totalRating += ((4-(int)animal->trainingLevel*2) - (client->profile.timeAvailabilityPerDay / 30)) * 0.04f;
    }

    if((int)animal->timeCommitment == 0 && 15 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((15.0f - client->profile.timeAvailabilityPerDay)/15.0f) * 4 * 0.06;
    }
    else if((int)animal->timeCommitment == 1 && 60 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((60.0f - client->profile.timeAvailabilityPerDay)/60.0f) * 4 * 0.06;
    }
    else if((int)animal->timeCommitment == 2 && 150 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((150.0f - client->profile.timeAvailabilityPerDay)/150.0f) * 4 * 0.06;
    }


    if((client->profile.timeAvailabilityPerDay / 30) - (4-(int)animal->trainabilityLevel*2))
    {
        totalRating += ((4-((int)animal->trainabilityLevel)*2) - (client->profile.timeAvailabilityPerDay / 30)) * 0.04f;
    }

    if((int)animal->levelOfCare == 0 && 15 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((15.0f - client->profile.timeAvailabilityPerDay)/15.0f) * 4 * 0.06;
    }
    else if((int)animal->levelOfCare == 1 && 60 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((60.0f - client->profile.timeAvailabilityPerDay)/60.0f) * 4 * 0.06;
    }
    else if((int)animal->levelOfCare == 2 && 150 - client->profile.timeAvailabilityPerDay > 0)
    {
        totalRating += ((150.0f - client->profile.timeAvailabilityPerDay)/150.0f) * 4 * 0.06;
    }

    if(overCost > 0 && overCost < 0.25f)
        totalRating += overCost * 16 * 0.06;

    if(client->hasPets)
        totalRating += (4-(int)animal->affinityForAnimals*2)*0.06;

    if(client->hasChildrenUnderTwelve)
        totalRating += (4-(int)animal->affinityForChildren*2)*0.06;

    //ownership expectation

    //float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX)); //1.0;

    return totalRating;
    */
}
