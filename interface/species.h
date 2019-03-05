#ifndef SPECIES_H
#define SPECIES_H
#include <string>

class Species
{
private:
    std::string speciesName;
    std::string breedName;
    int estimatedCostPerMonth;
public:
    inline std::string getSpecies() const {return speciesName;}
    inline std::string getBreed() const {return breedName;}
    inline int getCostPerMonth() const {return estimatedCostPerMonth;}
    inline void setSpecies(int eCostPerMonth, std::string sName, std::string bName=""){speciesName=sName; breedName=bName; estimatedCostPerMonth=eCostPerMonth;}
    Species(int eCostPerMonth, std::string sName, std::string bName="");
    Species();
};


#endif // SPECIES_H
