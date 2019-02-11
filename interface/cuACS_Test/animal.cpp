#include "animal.h"

Species::Species()
{
    speciesName="";
    breedName="";
    estimatedCostPerMonth=-1;
}
Species::Species(int eCostPerMonth, std::string sName, std::string bName)
{
    speciesName=sName;
    breedName=bName;
    estimatedCostPerMonth=eCostPerMonth;
}


Animal::Animal()
{

    name = "";
    age = 0;
    sex = ' ';
    species = Species();
}

Animal::Animal(std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    name = n;
    age = a;
    sex = sx;
    Species s(0, sp, b);
    species = s;
    levelOfCare = (cL==0) ? Level::LOW : (cL==1) ? Level::MEDIUM : Level::HIGH;
}

void Animal::populateSocial(int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    trainingLevel = (trLevel == 0) ? Level::LOW : ((trLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForPeople = (peopleLevel == 0) ? Level::LOW : ((peopleLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForChildren = (childLevel == 0) ? Level::LOW : ((childLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForAnimals = (animalLevel == 0) ? Level::LOW : ((animalLevel == 1) ? Level::MEDIUM : Level::HIGH);
    approachability = (approachLevel == 0) ? Level::LOW : ((approachLevel == 1) ? Level::MEDIUM : Level::HIGH);
    timeCommitment = (tiLevel == 0) ? Level::LOW : ((tiLevel == 1) ? Level::MEDIUM : Level::HIGH);
}

void Animal::populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist)
{
    immunized = imm;
    dietNeeds = dietString;
    mobilityNeeds = mobilityString;
    disabilityNeeds = disabilityString;
    biography = bio;
    abuseHistory = aHist;
}
