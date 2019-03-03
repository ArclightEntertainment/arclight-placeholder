#include "Address.h"

Address::Address()
{

}

Address::Address(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc)
{
  streetLine1 = sl1;
  streetLine2 = sl2;
  city = ct;
  subnationalDivision = sub;
  country = c;
  postalCode = pc;
}

Address::Address(const Address& a_address)
{
  
}
