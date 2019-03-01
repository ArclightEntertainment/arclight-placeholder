#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include "species.h"

enum Level {LOW=0, MEDIUM=1, HIGH=2};

//------------------------------------------
//------------------------------------------
//---------------Animal Class---------------
//------------------------------------------
//------------------------------------------
class Animal
{
private:
//Animal Info
    //basic information
    int shelterID;
    std::string name;
    int age;
    char sex;
    Species species;
    Level levelOfCare;

    //social information
    Level trainingLevel;
    Level trainabilityLevel;
    Level affinityForPeople;
    Level affinityForChildren;
    Level affinityForAnimals;
    Level approachability;
    Level timeCommitment;

    //history information
    bool immunized;
    std::string dietNeeds;
    std::string mobilityNeeds;
    std::string disabilityNeeds;
    std::string abuseHistory;
    std::string biography;
public:
//Constructor and population functions
    Animal();
    Animal(int id, std::string n, int a, char sx, std::string sp, std::string b, int cL);
    void populateSocial(int trLevel, int taLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel);
    void populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist);

//Operator Overloads
    Animal (const Animal& a_animal);
//Getters
    //basicInfo
    inline int getShelterID() const {return shelterID;}
    inline std::string getName() const {return name;}
    inline int getAge() const {return age;}
    inline char getSex() const {return sex;}
    inline std::string getSexString() const {return (sex == 'M') ? "Male" : "Female";}
    inline std::string getSpecies() const {return species.getSpecies();}
    inline std::string getBreed() const {return species.getBreed();}
    inline int getEstimatedCost() const {return species.getCostPerMonth();}
    inline Level getLevelOfCare() const {return levelOfCare;}

    //socialInfo
    inline Level getTrainingLevel() const {return trainingLevel;}
    inline Level getTrainabilityLevel() const {return trainabilityLevel;}
    inline Level getAffForPeople() const {return affinityForPeople;}
    inline Level getAffForChildren() const {return affinityForChildren;}
    inline Level getAffForAnimals() const {return affinityForAnimals;}
    inline Level getApproachability() const {return approachability;}
    inline Level getTimeCommitment() const {return timeCommitment;}

    //historyInfo
    inline bool isImmunized() const {return immunized;}
    inline std::string getDietNeeds() const {return dietNeeds;}
    inline std::string getMobilityNeeds() const {return mobilityNeeds;}
    inline std::string getDisabilityNeeds() const {return disabilityNeeds;}
    inline std::string getAbuseHistory() const {return abuseHistory;}
    inline std::string getBiography() const {return biography;}

//Setters
    inline void setShelterID(int id) {shelterID = id;}
    inline void setName(std::string n) {name = n;}
    inline void setAge(int a) {age = a;}
    inline void setSex(char s) {sex = s;}
    inline void setSpecies(int estimate, std::string s, std::string b="") {species.setSpecies(estimate, s, b);}
    inline void setSpecies(Species *s) {species = *s;}
    inline void setDisabled(Level d) {levelOfCare = d;}
    inline void setDisabled(int l) {levelOfCare = (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}

    //social
    inline void setTraining(Level hT)       {trainingLevel=hT;}
    inline void setAffForAdults(Level a)    {affinityForPeople = a;}
    inline void setAffForChildren(Level a)  {affinityForChildren = a;}
    inline void setAffForAnimals(Level a)   {affinityForAnimals = a;}
    inline void setApproachability(Level a) {approachability = a;}
    inline void setTimeCommitment(Level tC) {timeCommitment = tC;}

    inline void setTraining         (int l) {trainingLevel =         (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}
    inline void setAffForAdults     (int l) {affinityForPeople =     (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}
    inline void setAffForChildren   (int l) {affinityForChildren =   (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}
    inline void setAffForAnimals    (int l) {affinityForAnimals =    (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}
    inline void setApproachability  (int l) {approachability =       (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}
    inline void setTimeCommitment   (int l) {timeCommitment =        (l == 0) ? Level::LOW : ((l == 1) ? Level::MEDIUM : Level::HIGH);}

    //history
    inline void setImmunized(bool imm) {immunized = imm;}
    inline void setDietNeeds(        std::string nstring) {dietNeeds = nstring;}
    inline void setMobilityNeeds(    std::string nstring) {mobilityNeeds = nstring;}
    inline void setDisabilityNeeds(  std::string nstring) {disabilityNeeds = nstring;}

    inline void addDietNeeds(        std::string nstring) {dietNeeds         .append(", "); dietNeeds         .append(nstring);}
    inline void addMobilityNeeds(    std::string nstring) {mobilityNeeds     .append(", "); mobilityNeeds     .append(nstring);}
    inline void addDisabilityNeeds(  std::string nstring) {disabilityNeeds   .append(", "); disabilityNeeds   .append(nstring);}

    inline void setAbuseHistory(std::string aH) {abuseHistory = aH;}
    inline void setBiography(std::string b) {biography = b;}
};
#endif // ANIMAL_H
