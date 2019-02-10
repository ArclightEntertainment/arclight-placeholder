#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include<vector>

enum Level {LOW=0, MEDIUM=1, HIGH=2};


//------------------------------------------
//------------------------------------------
//--------------Species Class---------------
//------------------------------------------
//------------------------------------------

class Species
{
private:
    std::string speciesName;
    std::string breedName;
    int estimatedCostPerMonth;
public:
    inline std::string getSpecies(){return speciesName;}
    inline std::string getBreed(){return breedName;}
    inline int getCostPerMonth(){return estimatedCostPerMonth;}
    inline void setSpecies(int eCostPerMonth, std::string sName, std::string bName=""){speciesName=sName; breedName=bName; estimatedCostPerMonth=eCostPerMonth;}
    Species(int eCostPerMonth, std::string sName, std::string bName="");
    Species();
};

//------------------------------------------
//------------------------------------------
//--------------Animal Structs--------------
//------------------------------------------
//------------------------------------------

struct basicInfo{
    std::string name;
    int age;
    char sex;
    Species species;
};
struct socialInfo{
    Level trainingLevel;
    Level affinityForPeople;
    Level affinityForChildren;
    Level affinityForAnimals;
    Level approachability;
    Level timeCommitment;
};
struct historyInfo{
    int disabled;
    bool immunized;
    std::string dietNeeds;
    std::string mobilityNeeds;
    std::string disabilityNeeds;
    std::string abuseHistory;
    std::string biography;
};

//------------------------------------------
//------------------------------------------
//---------------Animal Class---------------
//------------------------------------------
//------------------------------------------
class Animal
{
private:
//Static Animal Info
    struct basicInfo basic;
    struct socialInfo social;
    struct historyInfo history;
public:
    Animal();
    Animal(std::string n, int a, char sx, std::string sp, std::string b);
    void populateSocial(int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel);
    void populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist);
//Getters
    //basicInfo
    inline std::string getName() {return basic.name;}
    inline int getAge() {return basic.age;}
    inline char getSex() {return basic.sex;}
    inline std::string getSexString() {return (basic.sex == 'M') ? "Male" : "Female";}
    inline std::string getSpecies() {return basic.species.getSpecies();}
    inline std::string getBreed() {return basic.species.getBreed();}

    //socialInfo
    inline Level getTrainingLevel() {return social.trainingLevel;}
    inline Level getAffForPeople() {return social.affinityForPeople;}
    inline Level getAffForChildren() {return social.affinityForChildren;}
    inline Level getAffForAnimals() {return social.affinityForAnimals;}
    inline Level getApproachability() {return social.approachability;}
    inline Level getTimeCommitment() {return social.timeCommitment;}

    //historyInfo
    inline bool isDisabled() {return history.disabled;}
    inline std::string getDietNeeds() {return history.dietNeeds;}
    inline std::string getMobilityNeeds() {return history.mobilityNeeds;}
    inline std::string getDisabilityNeeds() {return history.disabilityNeeds;}
    inline std::string getAbuseHistory() {return history.abuseHistory;}
    inline std::string getBiography() {return history.biography;}

//Setters
    inline void setName(std::string n) {basic.name = n;}
    inline void setAge(int a) {basic.age = a;}
    inline void setSex(char s) {basic.sex = s;}
    inline void setSpecies(int estimate, std::string s, std::string b="") {basic.species.setSpecies(estimate, s, b);}
    inline void setSpecies(Species *s) {basic.species = *s;}

    //social
    void setLevel(std::string field, int level);
    inline void setTraining(Level hT) {social.trainingLevel=hT;}
    inline void setAffForAdults(Level a) {social.affinityForPeople = a;}
    inline void setAffForChildren(Level a) {social.affinityForChildren = a;}
    inline void setAffForAnimals(Level a) {social.affinityForAnimals = a;}
    inline void setApproachability(Level a) {social.approachability = a;}
    inline void setTimeCommitment(Level tC) {social.timeCommitment = tC;}

    //history
    inline void setDisabled(bool d) {history.disabled = d;}
    inline void setDietNeeds(        std::string nstring) {history.dietNeeds = nstring;}
    inline void setMobilityNeeds(    std::string nstring) {history.mobilityNeeds = nstring;}
    inline void setDisabilityNeeds(  std::string nstring) {history.disabilityNeeds = nstring;}

    inline void addDietNeeds(        std::string nstring) {history.dietNeeds         .append(", "); history.dietNeeds         .append(nstring);}
    inline void addMobilityNeeds(    std::string nstring) {history.mobilityNeeds     .append(", "); history.mobilityNeeds     .append(nstring);}
    inline void addDisabilityNeeds(  std::string nstring) {history.disabilityNeeds   .append(", "); history.disabilityNeeds   .append(nstring);}

    inline void setAbuseHistory(std::string aH) {history.abuseHistory = aH;}
    inline void setBiography(std::string b) {history.biography = b;}
};
#endif // ENTITY_H
