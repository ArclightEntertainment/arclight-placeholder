#include "Animal.h"
//default
Animal::Animal()
{
    shelterID = 0;
    name = "";
    age = 0;
    sex = ' ';
    species = Species();
}

//Basic constructor
Animal::Animal(std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    shelterID = 0;
    name = n;
    age = a;
    sex = sx;
    Species s(0, sp, b);
    species = s;
    levelOfCare = (cL==0) ? Level::LOW : (cL==1) ? Level::MEDIUM : Level::HIGH;
}
//constructor coming from Database
Animal::Animal(int sid, std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    shelterID = sid;
    name = n;
    age = a;
    sex = sx;
    Species s(0, sp, b);
    species = s;
    levelOfCare = (cL==0) ? Level::LOW : (cL==1) ? Level::MEDIUM : Level::HIGH;
}

//populate social values. Input ints, convert to Levels
void Animal::populateSocial(int trLevel, int taLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    trainingLevel = (trLevel == 0) ? Level::LOW : ((trLevel == 1) ? Level::MEDIUM : Level::HIGH);
    trainabilityLevel = (taLevel == 0) ? Level::LOW : ((taLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForPeople = (peopleLevel == 0) ? Level::LOW : ((peopleLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForChildren = (childLevel == 0) ? Level::LOW : ((childLevel == 1) ? Level::MEDIUM : Level::HIGH);
    affinityForAnimals = (animalLevel == 0) ? Level::LOW : ((animalLevel == 1) ? Level::MEDIUM : Level::HIGH);
    approachability = (approachLevel == 0) ? Level::LOW : ((approachLevel == 1) ? Level::MEDIUM : Level::HIGH);
    timeCommitment = (tiLevel == 0) ? Level::LOW : ((tiLevel == 1) ? Level::MEDIUM : Level::HIGH);
}

//populate history values,
void Animal::populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist)
{
    immunized = imm;
    dietNeeds = dietString;
    mobilityNeeds = mobilityString;
    disabilityNeeds = disabilityString;
    biography = bio;
    abuseHistory = aHist;
}

//copy constructor
Animal::Animal(const Animal &a_animal)
{
    //basic information
    shelterID = a_animal.getShelterID();
    name = a_animal.getName();
    age = a_animal.getAge();
    sex = a_animal.getSex();
    species = Species(a_animal.getEstimatedCost(), a_animal.getSpecies(), a_animal.getBreed());
    levelOfCare = a_animal.getLevelOfCare();

    //social information
    trainingLevel = a_animal.getTrainingLevel();
    trainabilityLevel = a_animal.getTrainabilityLevel();
    affinityForPeople = a_animal.getAffForPeople();
    affinityForChildren = a_animal.getAffForChildren();
    affinityForAnimals = a_animal.getAffForAnimals();
    approachability = a_animal.getApproachability();
    timeCommitment = a_animal.getTimeCommitment();

    //history information
    immunized = a_animal.isImmunized();
    dietNeeds = a_animal.getDietNeeds();
    mobilityNeeds = a_animal.getMobilityNeeds();
    disabilityNeeds = a_animal.getDisabilityNeeds();
    abuseHistory = a_animal.getAbuseHistory();
    biography = a_animal.getBiography();
}