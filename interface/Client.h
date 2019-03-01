#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Levels.h"
#include "Address.h"
#include "ClientProfile.h"

//------------------------------------------
//------------------------------------------
//---------------Client Class---------------
//------------------------------------------
//------------------------------------------
class Client
{
private:

    //contact information
    std::string title;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;

    //extended information
    Address address;
    ClientProfile profile;

public:
//Constructor and population functions
    Client();
    Client(std::string t, std::string fn, std::string ln, std::string pn);
    void populateAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc);
    void populateProfile(int a, FiveScale lOfMobility, FiveScale ownExp, int budget, int space, float timeAvail, FiveScale lOfEnergy, FiveScale goodWithAnis);

//Operator Overloads
    Client(const Client& a_client);
//Getters
    //contact information
    inline std::string getName()          const {return firstName + " " + lastName;}
    inline std::string getNameWithTitle() const {return title + " " + firstName + " " + lastName;}
    inline std::string getFirstName()     const {return firstName;}
    inline std::string getLastName()      const {return lastName;}
    inline std::string getPhoneNumber()   const {return phoneNumber;}
    inline std::string getAddress()

    inline Address& getAddress() {return address;}
    inline ClientProfile& getClientProfile() {return clientProfile;}

//Setters
    //contact information
    inline void setTitle(std::string t)         {title = t;}
    inline void setFirstName(std::string fn)    {firstName = fn;}
    inline void setLastName(std::string ln)     {lastName = ln;}
    inline void setPhoneNumber(std::string pn)  {phoneNumber = pn;}

};
#endif // CLIENT_H
