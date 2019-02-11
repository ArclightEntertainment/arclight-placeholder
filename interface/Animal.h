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
//---------------Animal Class---------------
//------------------------------------------
//------------------------------------------
class Animal
{
private:
//Static Animal Info
    //basic information
    int shelterID;
    std::string name;
    int age;
    char sex;
    Species species;
    Level levelOfCare;

    //social information
    Level trainingLevel;
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
    Animal();
    Animal(int id, std::string n, int a, char sx, std::string sp, std::string b, int cL);
    void populateSocial(int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel);
    void populateHistory(bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist);
//Getters
    //basicInfo
    inline int getShelterID() {return shelterID;}
    inline std::string getName() {return name;}
    inline int getAge() {return age;}
    inline char getSex() {return sex;}
    inline std::string getSexString() {return (sex == 'M') ? "Male" : "Female";}
    inline std::string getSpecies() {return species.getSpecies();}
    inline std::string getBreed() {return species.getBreed();}
    inline bool isDisabled() {return levelOfCare;}

    //socialInfo
    inline Level getTrainingLevel() {return trainingLevel;}
    inline Level getAffForPeople() {return affinityForPeople;}
    inline Level getAffForChildren() {return affinityForChildren;}
    inline Level getAffForAnimals() {return affinityForAnimals;}
    inline Level getApproachability() {return approachability;}
    inline Level getTimeCommitment() {return timeCommitment;}

    //historyInfo
    inline std::string getDietNeeds() {return dietNeeds;}
    inline std::string getMobilityNeeds() {return mobilityNeeds;}
    inline std::string getDisabilityNeeds() {return disabilityNeeds;}
    inline std::string getAbuseHistory() {return abuseHistory;}
    inline std::string getBiography() {return biography;}

//Setters
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
    inline void setDietNeeds(        std::string nstring) {dietNeeds = nstring;}
    inline void setMobilityNeeds(    std::string nstring) {mobilityNeeds = nstring;}
    inline void setDisabilityNeeds(  std::string nstring) {disabilityNeeds = nstring;}

    inline void addDietNeeds(        std::string nstring) {dietNeeds         .append(", "); dietNeeds         .append(nstring);}
    inline void addMobilityNeeds(    std::string nstring) {mobilityNeeds     .append(", "); mobilityNeeds     .append(nstring);}
    inline void addDisabilityNeeds(  std::string nstring) {disabilityNeeds   .append(", "); disabilityNeeds   .append(nstring);}

    inline void setAbuseHistory(std::string aH) {abuseHistory = aH;}
    inline void setBiography(std::string b) {biography = b;}
};
#endif // ENTITY_H
