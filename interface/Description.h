#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include <string>
#include <iostream>
template <class T>
class Description
{
public:
    Description():name(""), attributeID(), value(){}
    Description(std::string n, int aID, T v) : name(n), attributeID(aID), value(v){}
    Description(const Description<T> & desc) {name = desc.getName(); attributeID = desc.getAttributeID(); value = desc.getValue();}
    ~Description(){}
    T getValue() const {return value;}
    int getAttributeID() const {return attributeID;}
    std::string getName() const {return name;}
    void setValue(T v) {value=v;}
    void setAttributeID(int i) {attributeID=i;}
    void setName(std::string n) {name=n;}
private:
    std::string name;
    int attributeID;
    T value;
};

#endif // DESCRIPTION_H
