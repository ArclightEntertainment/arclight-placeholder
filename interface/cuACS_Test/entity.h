#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <string.h>
#include<vector>

enum Level {LOW, MEDIUM, HIGH};

struct basicInfo{
    std::string name;
    int age;
    char sex;
    std::string species;
    std::string breed;
};
struct socialInfo{
    bool houseTrained;
    Level obedience;
    Level affinityForMen;
    Level affinityForWomen;
    Level affinityForChildren;
    Level affinityForAnimals;
    Level timeCommitment;
};
struct historyInfo{
    bool disabled;
    std::vector<std::string> specialNeeds;
    bool abused;
    std::string abuseHistory;
    std::string biography;
};

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
//Getters
    //basicInfo
    inline std::string getName() {return basic.name;}
    inline int getAge() {return basic.age;}
    inline char getSex() {return basic.sex;}
    inline std::string getSexString() {return (basic.sex == 'M') ? "Male" : "Female";}
    inline std::string getSpecies() {return basic.species;}
    inline std::string getBreed() {return basic.breed;}

    //socialInfo
    inline bool isHouseTrained() {return social.houseTrained;}
    inline Level getObedience() {return social.obedience;}
    inline Level getAffForMen() {return social.affinityForMen;}
    inline Level getAffForWomen() {return social.affinityForWomen;}
    inline Level getAffForChildren() {return social.affinityForChildren;}
    inline Level getAffForAnimals() {return social.affinityForAnimals;}
    inline Level getTimeCommitment() {return social.timeCommitment;}

    //historyInfo
    inline bool isDisabled() {return history.disabled;}
    inline std::vector<std::string> getSpecialNeeds() {return history.specialNeeds;}
    inline bool isAbused() {return history.abused;}
    inline std::string getAbuseHistory() {return history.abuseHistory;}
    inline std::string getBiography() {return history.biography;}

//Setters
    inline void setName(std::string n) {basic.name = n;}
    inline void setAge(int a) {basic.age = a;}
    inline void setSex(char s) {basic.sex = s;}
    inline void setSpecies(std::string s) {basic.species = s;}
    inline void setBreed(std::string b) {basic.breed = b;}

    //social
    inline void setHouseTrained(bool hT) {social.houseTrained = hT;}
    inline void setObedience(Level o) {social.obedience = o;}
    inline void setAffForMen(Level a) {social.affinityForMen = a;}
    inline void setAffForWomen(Level a) {social.affinityForWomen = a;}
    inline void setAffForChildren(Level a) {social.affinityForChildren = a;}
    inline void setAffForAnimals(Level a) {social.affinityForAnimals = a;}
    inline void setTimeCommitment(Level tC) {social.timeCommitment = tC;}

    //history
    inline void setDisabled(bool d) {history.disabled = d;}
    inline void addSpecialNeed(std::string n) {history.specialNeeds.push_back(n);}
    inline void setAbused(bool a) {history.abused = a;}
    inline void setAbuseHistory(std::string aH) {history.abuseHistory = aH;}
    inline void setBiography(std::string b) {history.biography = b;}
};
#endif // ENTITY_H
