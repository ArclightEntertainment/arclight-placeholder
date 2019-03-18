#ifndef SPECIES_H
#define SPECIES_H
#include <string>

class Species
{
private:
    std::string speciesName;
    std::string breedName;
public:
    inline std::string getSpecies() const {return speciesName;}
    inline std::string getBreed() const {return breedName;}
    Species(int eCostPerMonth, std::string sName, std::string bName="");
    Species();
};


#endif // SPECIES_H
