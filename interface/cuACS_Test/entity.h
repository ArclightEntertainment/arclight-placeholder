#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include<vector>

typedef struct addressStruct
{
    std::string st1;
    std::string st2;
    std::string city;
    std::string prov;
    std::string country;
    std::string pcode;
}Address;
typedef struct nameStruct
{
    std::string fname;
    std::string lname;
    std::string title;
}Name;


class Animal
{
public:
    Animal();
private:
/*
shit that animals need
Physical Characteristics:
    Age
    Name
    Sex
    Energy level
    Disabilities
    Species
        Breed
Training:
    House Training
    Obedience
    Requisite Time Commitment
Mental/Personality
    Affinity for other Animals/People
    History of Abuse
Biography
*/
};
#endif // ENTITY_H
