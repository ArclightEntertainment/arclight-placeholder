#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include "species.h"
#include "Levels.h"
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
    ThreeScale levelOfCare;

    //social information
    ThreeScale trainingLevel;
    ThreeScale trainabilityLevel;
    ThreeScale affinityForPeople;
    ThreeScale affinityForChildren;
    ThreeScale affinityForAnimals;
    ThreeScale approachability;
    ThreeScale timeCommitment;

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
    Animal(std::string n, int a, char sx, std::string sp, std::string b, int cL);
    Animal(int sid, std::string n, int a, char sx, std::string sp, std::string b, int cL);
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
    inline ThreeScale getLevelOfCare() const {return levelOfCare;}

    //socialInfo
    inline ThreeScale getTrainingLevel() const {return trainingLevel;}
    inline ThreeScale getTrainabilityLevel() const {return trainabilityLevel;}
    inline ThreeScale getAffForPeople() const {return affinityForPeople;}
    inline ThreeScale getAffForChildren() const {return affinityForChildren;}
    inline ThreeScale getAffForAnimals() const {return affinityForAnimals;}
    inline ThreeScale getApproachability() const {return approachability;}
    inline ThreeScale getTimeCommitment() const {return timeCommitment;}

    //historyInfo
    inline bool isImmunized() const {return immunized;}
    inline std::string getDietNeeds() const {return dietNeeds;}
    inline std::string getMobilityNeeds() const {return mobilityNeeds;}
    inline std::string getDisabilityNeeds() const {return disabilityNeeds;}
    inline std::string getAbuseHistory() const {return abuseHistory;}
    inline std::string getBiography() const {return biography;}

    inline std::string getLevelOfCareString()const{return (levelOfCare == 0) ? "Low" : (levelOfCare == 1) ? "Average" : "High";}
    inline std::string getTrainingString()const{return (trainingLevel == 0) ? "Untrained" : (trainingLevel == 1) ? "House Trained" : "Well Trained";}
    inline std::string getTrainabilityString()const{return (trainabilityLevel == 0) ? "Disobedient" : (trainabilityLevel == 1) ? "Basic" : "High Level";}
    inline std::string getAffForPeopleString()const{return (affinityForPeople == 0) ? "Low" : (affinityForPeople == 1) ? "Average" : "High";}
    inline std::string getAffForChildrenString()const{return (affinityForChildren == 0) ? "Low" : (affinityForChildren == 1) ? "Average" : "High";}
    inline std::string getAffForAnimalsString()const{return (affinityForAnimals == 0) ? "Low" : (affinityForAnimals == 1) ? "Average" : "High";}
    inline std::string getApproachabilityString()const{return (approachability == 0) ? "Shy" : (approachability == 1) ? "Tentative" : "Comfortable";}
    inline std::string getTimeCommitmentString()const{return (timeCommitment == 0) ? "Low" : (timeCommitment == 1) ? "Average" : "High";}


//Setters
    inline void setShelterID(int id) {shelterID = id;}
    inline void setName(std::string n) {name = n;}
    inline void setAge(int a) {age = a;}
    inline void setSex(char s) {sex = s;}
    inline void setSpecies(int estimate, std::string s, std::string b="") {species.setSpecies(estimate, s, b);}
    inline void setSpecies(Species *s) {species = *s;}
    inline void setDisabled(ThreeScale d) {levelOfCare = d;}
    inline void setDisabled(int l) {levelOfCare = (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}

    //social
    inline void setTraining(ThreeScale hT)       {trainingLevel=hT;}
    inline void setAffForAdults(ThreeScale a)    {affinityForPeople = a;}
    inline void setAffForChildren(ThreeScale a)  {affinityForChildren = a;}
    inline void setAffForAnimals(ThreeScale a)   {affinityForAnimals = a;}
    inline void setApproachability(ThreeScale a) {approachability = a;}
    inline void setTimeCommitment(ThreeScale tC) {timeCommitment = tC;}

    inline void setTraining         (int l) {trainingLevel =         (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}
    inline void setAffForAdults     (int l) {affinityForPeople =     (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}
    inline void setAffForChildren   (int l) {affinityForChildren =   (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}
    inline void setAffForAnimals    (int l) {affinityForAnimals =    (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}
    inline void setApproachability  (int l) {approachability =       (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}
    inline void setTimeCommitment   (int l) {timeCommitment =        (l == 0) ? ThreeScale::LOW : ((l == 1) ? ThreeScale::MEDIUM : ThreeScale::HIGH);}

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
