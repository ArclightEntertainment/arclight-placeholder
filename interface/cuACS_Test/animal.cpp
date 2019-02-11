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

    basic.name = "";
    basic.age = 0;
    basic.sex = ' ';
    basic.species = Species();
}

Animal::Animal(std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    basic.name = n;
    basic.age = a;
    basic.sex = sx;
    Species s(0, sp, b);
    basic.species = s;
    basic.levelOfCare = (cL==0) ? Level::LOW : (cL==1) ? Level::MEDIUM : Level::HIGH;
}

void Animal::populateSocial(int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    social.trainingLevel = (trLevel == 0) ? Level::LOW : ((trLevel == 1) ? Level::MEDIUM : Level::HIGH);
    social.affinityForPeople = (peopleLevel == 0) ? Level::LOW : ((peopleLevel == 1) ? Level::MEDIUM : Level::HIGH);
    social.affinityForChildren = (childLevel == 0) ? Level::LOW : ((childLevel == 1) ? Level::MEDIUM : Level::HIGH);
    social.affinityForAnimals = (animalLevel == 0) ? Level::LOW : ((animalLevel == 1) ? Level::MEDIUM : Level::HIGH);
    social.approachability = (approachLevel == 0) ? Level::LOW : ((approachLevel == 1) ? Level::MEDIUM : Level::HIGH);
    social.timeCommitment = (tiLevel == 0) ? Level::LOW : ((tiLevel == 1) ? Level::MEDIUM : Level::HIGH);
}

void Animal::populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist)
{
    history.immunized = imm;
    history.dietNeeds = dietString;
    history.mobilityNeeds = mobilityString;
    history.disabilityNeeds = disabilityString;
    history.biography = bio;
    history.abuseHistory = aHist;
}
