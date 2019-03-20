#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include <string>

template <class T>
class Description
{
public:
    Description(){}
    Description(std::string n, int aID, T v) : name(n), attributeID(aID), value(v){}
    ~Description(){}
    T getValue() {return value;}
    int getAttributeID() {return attributeID;}
    std::string getName() {return name;}
private:
    T value;
    int attributeID;
    std::string name;
};

#endif // DESCRIPTION_H
