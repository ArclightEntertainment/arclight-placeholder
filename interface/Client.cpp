#include "Client.h"
#include <iostream>
//default
Client::Client()
{

}

//Basic constructor
Client::Client(int id, std::string t, std::string fn, std::string ln, std::string pn)
{
  clientID = id;
  title = t;
  firstName = fn;
  lastName = ln;
  phoneNumber = pn;
  address = Address();
  profile = ClientProfile();
}

//copy constructor
Client::Client(const Client &a_client)
{

}

std::string Client::getPhoneNumberString()
{
    std::string startString = getPhoneNumber();
    std::string totalString = "";
    for (int i = 0; i < startString.length(); i++)
    {
        if (isdigit(startString[i]))
        {
            totalString += startString[i];
            //std::cout << totalString << std::endl;
        }
    }

    std::string areaString = totalString.substr(totalString.length() - 10, 3);
    std::string threeString = totalString.substr(totalString.length() - 7, 3);
    std::string fourString = totalString.substr(totalString.length() - 4, 4);
    std::string specialString = totalString.substr(0, totalString.length() - 10);
    std::string retString = "";

    if (specialString.length() > 0)
    {
        retString.append(specialString);
        retString.append("+");
    }
    retString.append("(");
    retString.append(areaString);
    retString.append(") ");
    retString.append(threeString);
    retString.append("-");
    retString.append(fourString);
    return retString;
}

//populate address
void Client::populateAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string cn, std::string pc)
{
  address.setStreetLine1(sl1);
  address.setStreetLine2(sl2);
  address.setCity(ct);
  address.setSubnationalDivision(sub);
  address.setCountry(cn);
  address.setPostalCode(pc);
}

//populate profile
void Client::populateProfile(int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, FiveScale lOfMobility, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect)
{
  profile.setAge(a);
  profile.setHasChildrenUnderTwelve(hasUnderTwelve);
  profile.setHasPets(hasPet);
  profile.setLevelOfMobility(lOfMobility);
  profile.setLengthOfOwnershipExpectation(ownExp);
  profile.setBudgetPerMonth(budget);
  profile.setTimeAvailabilityPerDay(timeAvail);
  profile.setLevelOfPatience(lOfPatience);
  profile.setPreviousExperience(prevExp);
  profile.setPhysicalAffection(physAffect);
}
