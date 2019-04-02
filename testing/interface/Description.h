#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include <string>

template <class T>
class Description
{
public:
    Description():name(""), attributeID(), value(){}
    Description(std::string n, int aID, T v) : name(n), attributeID(aID), value(v){}
    ~Description(){}
    T getValue() {return value;}
    int getAttributeID() {return attributeID;}
    std::string getName() {return name;}
private:
    std::string name;
    int attributeID;
    T value;
};

#endif // DESCRIPTION_H