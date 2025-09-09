#ifndef GROUPAC_HPP
#define GROUPAC_HPP
#include <iostream>
#include <fstream>

using namespace std;


class GroupAC
{
public:

    GroupAC(string name,string rate,int year);
    GroupAC();

    string getName();
    string getRate();
    int getYear();

    virtual void displayGroup();
    virtual void storeGroup(fstream& myFile);

protected:
    string _name;
    string _rate;
    int _year;
};

#endif // GROUPAC_HPP
