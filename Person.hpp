#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>


using namespace std;

class Person
{
public:
    Person(string name,string nationality,string birth);
    Person();
    string getName();
    string getNationality();
    string getBirth();
    void displayPerson();
    virtual void storePerson(fstream& myFile);
    void displayPersonName();

protected:
    string _name;
    string _nationality;
    string _birth;

};

#endif // PERSON_HPP
