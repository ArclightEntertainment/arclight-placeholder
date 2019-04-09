#include <cstdlib>
#include <ctime>
#include "AttributeComparator.h"
#include "Attributes.h"

float AttributeComparator::calculatePatienceAffinityForPeople(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE) -
            (4 - animal->getInt((int)AnimalAttribute::AFFINITY_FOR_PEOPLE)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::AFFINITY_FOR_PEOPLE)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE)) * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculatePhysicalAffectionAffinityForPeople(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::PHYSICAL_AFFECTION) -
            (4 - animal->getInt((int)AnimalAttribute::AFFINITY_FOR_PEOPLE)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::AFFINITY_FOR_PEOPLE)*2) -
                        client->getInt((int)ClientAttribute::PHYSICAL_AFFECTION)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculatePreviousExperienceLevelOfCare(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE) -
            animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE)*2 < 0)
    {
        totalRating += ((animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE)*2) -
                        client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE)) * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculatePreviousExperienceTrainingLevel(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE) -
            (4 - animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) -
                        client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfPatienceTrainability(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE) -
            (4 - animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE)) * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculatePreviousExperienceTrainability(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE) -
            (4 - animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) -
                        client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE)) * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfPatienceApproachability(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE) -
            (4 - animal->getInt((int)AnimalAttribute::APPROACHABILITY)*2) < 0)
    {
        totalRating += ((4 - animal->getInt((int)AnimalAttribute::APPROACHABILITY)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfMobilityLevelOfCare(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY) -
            animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE)*2 < 0)
    {
        totalRating += ((animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfMobilityTrainingLevel(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY) -
            (4-animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) < 0)
    {
        totalRating += (4-(animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY)) * 0.02f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfPatienceTrainingLevel(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE) -
            (4-animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) < 0)
    {
        totalRating += (4-(animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_PATIENCE)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculateLevelOfMobilityLevelOfEnergy(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY) -
            animal->getInt((int)AnimalAttribute::LEVEL_OF_ENERGY)*2 < 0)
    {
        totalRating += ((animal->getInt((int)AnimalAttribute::LEVEL_OF_ENERGY)*2) -
                        client->getInt((int)ClientAttribute::LEVEL_OF_MOBILITY)) * 0.06f;
    }
    return totalRating;
}

float AttributeComparator::calculateAvailabilityPerDayTrainingLevel(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if((client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) / 30) -
            (4-animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) < 0)
    {
        if((client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) / 30) -
                (4-animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) < 4)
        {
        totalRating += ((4-animal->getInt((int)AnimalAttribute::TRAINING_LEVEL)*2) -
                        (client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) / 30)) * 0.04f;
        }
        else
            totalRating += 4 * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculateAvailabilityPerDayTimeCommitment(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(animal->getInt((int)AnimalAttribute::TIME_COMMITMENT) == 0 &&
            15 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0 &&
            15 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) <= 15)
    {
        totalRating += ((15.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/15.0f) * 4 * 0.06;
    }

    else if(animal->getInt((int)AnimalAttribute::TIME_COMMITMENT) == 1 &&
            60 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0 &&
            60 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) <= 60)
    {
        totalRating += ((60.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/60.0f) * 4 * 0.06;
    }

    else if(animal->getInt((int)AnimalAttribute::TIME_COMMITMENT) == 2 &&
            150 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0 &&
            150 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) <= 150)
    {
        totalRating += ((150.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/150.0f) * 4 * 0.06;
    }
    return totalRating;
}

float AttributeComparator::calculateAvailabilityPerDayTrainabilityLevel(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if((client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) / 30) -
            (4-animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) < 0)
    {
        totalRating += (4-(animal->getInt((int)AnimalAttribute::TRAINABILITY_LEVEL)*2) -
                        (client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) / 30)) * 0.04f;
    }
    return totalRating;
}

float AttributeComparator::calculateAvailabilityPerDayLevelOfCare(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE) == 0 && 15 -
            client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0)
    {
        totalRating += ((15.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/15.0f) * 4 * 0.06;
    }

    else if(animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE) == 1 &&
            60 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0)
    {
        totalRating += ((60.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/60.0f) * 4 * 0.06;
    }

    else if(animal->getInt((int)AnimalAttribute::LEVEL_OF_CARE) == 2 &&
            150 - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY) > 0)
    {
        totalRating += ((150.0f - client->getInt((int)ClientAttribute::AVAILABILITY_PER_DAY))/150.0f) * 4 * 0.06;
    }
    return totalRating;
}

float AttributeComparator::calculateOvercost(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    float overCost = (animal->getInt((int)AnimalAttribute::MONTHLY_EXPENDITURE) -
                      client->getInt((int)ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL))/
            client->getInt((int)ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL);

    if(overCost < 0)
    {
        overCost = 0.0f;
    }

    if(overCost > 0 && overCost < 0.25f)
        totalRating += overCost * 16 * 0.06;

    return totalRating;
}

float AttributeComparator::calculateHasPetsAffinityForAnimals(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getBool((int)ClientAttribute::HAS_PETS))
        totalRating += (4-animal->getInt((int)AnimalAttribute::AFFINITY_FOR_ANIMALS)*2)*0.06;
    return totalRating;
}

float AttributeComparator::calculateHasChildrenAffinityForChildren(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getBool((int)ClientAttribute::HAS_CHILDREN_UNDER_TWELVE))
        totalRating += (4-animal->getInt((int)AnimalAttribute::AFFINITY_FOR_CHILDREN)*2)*0.06;
    return totalRating;
}

float AttributeComparator::calculateLengthOfOwnership(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
            (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) - animal->getInt((int)3)) > 0)
        totalRating += (client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
                       (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) - animal->getInt((int)3))) * 0.06;
    else if(client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
            (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) - animal->getInt((int)3)) < 0)
        totalRating += -1.0f * (client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
                       (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) - animal->getInt((int)3))) * 0.06;
    return totalRating;
}

float AttributeComparator::calculatePreviousExperienceApproachability(UAnimal *animal, UClient *client)
{
    float totalRating = 0.0;
    if(client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE) -
            (4-animal->getInt((int)AnimalAttribute::APPROACHABILITY)*2) < 0)
    {
        totalRating += (4-(animal->getInt((int)AnimalAttribute::APPROACHABILITY)*2) -
                        client->getInt((int)ClientAttribute::PREVIOUS_EXPERIENCE)) * 0.02f;
    }
    return totalRating;
}

float AttributeComparator::calculateCompatibility(UAnimal *animal, UClient *client)
{
    //float random = 100.0f*(static_cast <float> (rand()) / static_cast <float>(RAND_MAX));
    //return random;

    //Temporary
    float totalRating = 0.0f;
    float overCost = (animal->getInt((int)AnimalAttribute::MONTHLY_EXPENDITURE) -
                      client->getInt((int)ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL))/
            client->getInt((int)ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL);

    if(overCost < 0)
    {
        overCost = 0.0f;
    }

    if(overCost > 0.25)
    {
        return -1;
    }

    if(animal->getInt((int)AnimalAttribute::AFFINITY_FOR_CHILDREN) == 0 &&
            client->getBool((int)ClientAttribute::HAS_CHILDREN_UNDER_TWELVE))
    {
        return -1;
    }

    if(client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
            (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) -
             animal->getInt((int)AnimalAttribute::AGE)) > 4 ||
            client->getInt((int)ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION) -
            (animal->getInt((int)AnimalAttribute::LIFE_EXPECTANCY) -
             animal->getInt((int)AnimalAttribute::AGE)) < -4.0f)
        return -1;

    totalRating += calculatePatienceAffinityForPeople(animal, client);
    totalRating += calculatePhysicalAffectionAffinityForPeople(animal, client);
    totalRating += calculatePreviousExperienceLevelOfCare(animal, client);
    totalRating += calculatePreviousExperienceTrainingLevel(animal, client);
    totalRating += calculateLevelOfPatienceTrainability(animal, client);
    totalRating += calculatePreviousExperienceTrainability(animal, client);
    totalRating += calculateLevelOfPatienceApproachability(animal, client);
    totalRating += calculatePreviousExperienceApproachability(animal, client);
    totalRating += calculateLevelOfMobilityLevelOfCare(animal, client);
    totalRating += calculateLevelOfMobilityTrainingLevel(animal, client);
    totalRating += calculateLevelOfPatienceTrainingLevel(animal, client);
    totalRating += calculateLevelOfMobilityLevelOfEnergy(animal, client);
    totalRating += calculateAvailabilityPerDayTrainingLevel(animal, client);
    totalRating += calculateAvailabilityPerDayTimeCommitment(animal, client);
    totalRating += calculateAvailabilityPerDayTrainabilityLevel(animal, client);
    totalRating += calculateAvailabilityPerDayLevelOfCare(animal, client);
    totalRating += calculateOvercost(animal, client);
    totalRating += calculateHasPetsAffinityForAnimals(animal, client);
    totalRating += calculateHasChildrenAffinityForChildren(animal, client);
    totalRating += calculateLengthOfOwnership(animal, client);
    return 100.0f - ((totalRating * 100.0f)/4.0f);

}
