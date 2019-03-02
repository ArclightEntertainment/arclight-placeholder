#include "Species.h"

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
