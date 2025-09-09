#include "Groupac.hpp"

GroupAC::GroupAC(){

}

GroupAC::GroupAC(string name, string rate, int year)
{
    _name=name;
    _rate=rate;
    _year=year;
}

string GroupAC::getName()
{
    return _name;
}

string GroupAC::getRate()
{
    return _rate;
}

int GroupAC::getYear()
{
    return _year;
}

void GroupAC::displayGroup(){
}

void GroupAC::storeGroup(fstream& myFile)
{

}
