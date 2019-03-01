#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
private:

  std::string streetLine1;
  std::string streetLine2;
  std::string city;
  std::string subnationalDivision;
  std::string country;
  std::string postalCode;

public:
// Constructors
  Address();
  Address(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc);

//Operator Overloads
  Address(const Address& a_address);

// Getters
  inline std::string getStreetLine1()         const {return streetLine1;}
  inline std::string getStreetLine2()         const {return streetLine2;}
  inline std::string getCity()                const {return city;}
  inline std::string getSubnationalDivision() const {return subnationalDivision;}
  inline std::string getCountry()             const {return country;}
  inline std::string getPostalCode()          const {return postalCode;}

// Setters
  inline void setStreetLine1(std::string sl1)         {streetLine1 = sl1;}
  inline void setStreetLine2(std::string sl2)         {streetLine2 = sl2;}
  inline void setCity(std::string ct)                 {city = ct;}
  inline void setSubnationalDivision(std::string sub) {subnationalDivision = sub;}
  inline void setCountry(std::string c)               {country = c;}
  inline void setPostalCode(std::string pc)           {postalCode = pc;}
};
#endif // ADDRESS_H
