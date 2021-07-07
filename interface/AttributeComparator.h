#ifndef ATTRIBUTECOMPARATOR_H
#define ATTRIBUTECOMPARATOR_H

#include "EntityBuilder.h"
#include "AttributeComparator.h"

class AttributeComparator
{
public:
    static float calculateCompatibility(UAnimal *animal, UClient *client);
    static float calculatePatienceAffinityForPeople(UAnimal *animal, UClient *client);
    static float calculatePhysicalAffectionAffinityForPeople(UAnimal *animal, UClient *client);
    static float calculatePreviousExperienceLevelOfCare(UAnimal *animal, UClient *client);
    static float calculatePreviousExperienceTrainingLevel(UAnimal *animal, UClient *client);
    static float calculateLevelOfPatienceTrainability(UAnimal *animal, UClient *client);
    static float calculatePreviousExperienceTrainability(UAnimal *animal, UClient *client);
    static float calculateLevelOfPatienceApproachability(UAnimal *animal, UClient *client);
    static float calculatePreviousExperienceApproachability(UAnimal *animal, UClient *client);
    static float calculateLevelOfMobilityLevelOfCare(UAnimal *animal, UClient *client);
    static float calculateLevelOfMobilityTrainingLevel(UAnimal *animal, UClient *client);
    static float calculateLevelOfPatienceTrainingLevel(UAnimal *animal, UClient *client);
    static float calculateLevelOfMobilityLevelOfEnergy(UAnimal *animal, UClient *client);
    static float calculateAvailabilityPerDayTrainingLevel(UAnimal *animal, UClient *client);
    static float calculateAvailabilityPerDayTimeCommitment(UAnimal *animal, UClient *client);
    static float calculateAvailabilityPerDayTrainabilityLevel(UAnimal *animal, UClient *client);
    static float calculateAvailabilityPerDayLevelOfCare(UAnimal *animal, UClient *client);
    static float calculateOvercost(UAnimal *animal, UClient *client);
    static float calculateHasPetsAffinityForAnimals(UAnimal *animal, UClient *client);
    static float calculateHasChildrenAffinityForChildren(UAnimal *animal, UClient *client);
    static float calculateLengthOfOwnership(UAnimal *animal, UClient *client);
};
#endif // ATTRIBUTECOMPARATOR_H
