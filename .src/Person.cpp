#include "Person.hpp"
#include <fstream>

Person::Person()
{

}

Person::Person(string name, string nationality, string birth)
{
    _name = name;
    _nationality = nationality;
    _birth = birth;
}

string Person::getName()
{
   return _name;
}

string Person::getNationality()
{
    return _nationality;
}

string Person::getBirth()
{
    return _birth;
}

void Person::displayPerson()
{
    cout << endl;
    cout << "Name: " << getName() << endl;
    cout << "Birth: " << getBirth() << endl;
    cout << "Nationality: " << getNationality() << endl;
    cout << endl;
}

void Person::displayPersonName(){
    cout << getName() << endl;
}

void Person::storePerson(fstream& myFile)
{

}


