#include "species.h"

Species::Species()
{
    speciesName="";
    breedName="";
}
Species::Species(int eCostPerMonth, std::string sName, std::string bName)
{
    speciesName=sName;
    breedName=bName;
}
