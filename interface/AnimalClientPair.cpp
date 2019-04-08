#include "AnimalClientPair.h"
#include "AttributeComparator.h"
#include <sstream>
#include <algorithm>
#include <iomanip>

// Headers for detailed ACM dialog
static std::vector<std::string> commentHeader = {
    "Patience -> Affinity For People",
    "Physical Affection -> Affinity For People",
    "Previous Pet Experience -> Level of Care",
    "Previous Pet Experience -> Training Level",
    "Level of Patience -> Trainability",
    "Previous Pet Experience -> Trainability",
    "Level of Patience -> Approachability",
    "Previous Pet Experince -> Approachability",
    "Level of Mobility -> Level of Care",
    "Level of Mobility -> Training Level",

    "Level of Patience -> Training Level",
    "Level of Mobility -> Energy Level",
    "Time Availability -> Training Level",

    "Time Availability -> Required Time Commitment",
    "Time Availability -> Trainability",
    "Time Availability -> Required Care",
    "Other Pets -> Pet Friendliness",
};

// struct mapping comparator header to value
struct HeaderValue
{
   std::string header;
   float value;
};

AnimalClientPair::AnimalClientPair(UAnimal *a, UClient *c)
{
    animal = a;
    client = c;
    compatibility = AttributeComparator::calculateCompatibility(a, c);
}

UAnimal *AnimalClientPair::getAnimal()
{
    return animal;
}

UClient *AnimalClientPair::getClient()
{
    return client;
}

float AnimalClientPair::getCompatibility()
{
    return compatibility;
}

std::vector<std::string> AnimalClientPair::getCompatibilityComments()
{

    // Get values for comparators
    float values[17];
    values[0] = 100.0 - AttributeComparator::calculatePatienceAffinityForPeople(animal, client);
    values[1] = 100.0 - AttributeComparator::calculatePhysicalAffectionAffinityForPeople(animal, client);
    values[2] = 100.0 - AttributeComparator::calculatePreviousExperienceLevelOfCare(animal, client);
    values[3] = 100.0 - AttributeComparator::calculatePreviousExperienceTrainingLevel(animal, client);
    values[4] = 100.0 - AttributeComparator::calculateLevelOfPatienceTrainability(animal, client);
    values[5] = 100.0 - AttributeComparator::calculatePreviousExperienceTrainability(animal, client);
    values[6] = 100.0 - AttributeComparator::calculateLevelOfPatienceApproachability(animal, client);
    values[7] = 100.0 - AttributeComparator::calculatePreviousExperienceApproachability(animal, client);
    values[8] = 100.0 - AttributeComparator::calculateLevelOfMobilityLevelOfCare(animal, client);
    values[9] = 100.0 - AttributeComparator::calculateLevelOfMobilityTrainingLevel(animal, client);
    values[10] = 100.0 - AttributeComparator::calculateLevelOfPatienceTrainingLevel(animal, client);
    values[11] = 100.0 - AttributeComparator::calculateLevelOfMobilityLevelOfEnergy(animal, client);
    values[12] = 100.0 - AttributeComparator::calculateAvailabilityPerDayTrainingLevel(animal, client);
    values[13] = 100.0 - AttributeComparator::calculateAvailabilityPerDayTimeCommitment(animal, client);
    values[14] = 100.0 - AttributeComparator::calculateAvailabilityPerDayTrainabilityLevel(animal, client);
    values[15] = 100.0 - AttributeComparator::calculateAvailabilityPerDayLevelOfCare(animal, client);
    values[16] = 100.0 - AttributeComparator::calculateHasPetsAffinityForAnimals(animal, client);

    // Group comparator headers and their respective values
    HeaderValue pairs [17];
    for (int i=0; i<17; i++)
    {
        pairs[i].header = commentHeader[i];
        pairs[i].value = values[i];
    }

    // Sort with highest compatability first
    std::sort(pairs, pairs + 17,
              [](HeaderValue a, HeaderValue b)
    {
        return a.value > b.value;
    });

    // Populate return string
    std::vector<std::string> strings = {};
    for (int i=0; i<17; i++)
    {
        std::ostringstream stream;
        stream << pairs[i].header << " (" << pairs[i].value << "%)";
        strings.push_back(stream.str());
    }

    return strings;
}

std::string AnimalClientPair::toString()
{
    std::ostringstream stream;
    stream << "(" << compatibility << "), "
                    << animal->getName() << ", "
                    << client->getName();

    return stream.str();

}
