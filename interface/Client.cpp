#include "Client.h"

//default
Client::Client()
{

}

//Basic constructor
Client::Client(std::string t, std::string fn, std::string ln, std::string pn)
{
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

//populate address
void Client::populateAddress(sl1, sl2, ct, sub, cn, pc)
{
  address.setStreetLine1(sl1);
  address.setStreetLine2(sl2);
  address.setCity(ct);
  address.setCountry(c);
  address.setPostalCode(pc);
}

//populate profile
void Client::populateProfile(int a, int lOfMobility, int ownExp, int budget, int space, float timeAvail, int lOfEnergy, int goodWithAnis)
{
  profile.setAge(a);
  profile.setLevelOfMobility(toFiveScale(goodWithAnis));
  profile.setLengthOfOwnershipExpectation(ownExp);
  profile.setBudgetPerMonth(budget);
  profile.setLivingSpaceSquareFeet(space);
  profile.setTimeAvailabilityPerDay(timeAvail);
  profile.setLevelOfEnergy(toFiveScale(goodWithAnis));
  profile.setGoodWithAnimals(toFiveScale(goodWithAnis));
}
