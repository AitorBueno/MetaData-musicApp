#include "Concerts.hpp"
#include <fstream>

Concerts::Concerts(string place, string date)
{
    _place = place;
    _date = date;
}

Concerts::Concerts()
{

}

Concerts::~Concerts()
{

}
string Concerts::getPlace()
{
    return _place;
}
Concerts* Concerts::createConcert(){

    string place,date;

    cout << "-------------------------------" << endl;
    cout << "Concert information " << endl;
    cout << "-------------------------------" << endl;

    cin.ignore();
    cout << "Concert place: ";
    getline(cin,place);
    cout << "Concert date: ";
    getline(cin,date);

    Concerts* Concert=new Concerts(place,date);
    return Concert;
}

void Concerts::setPlace(string place)
{
    _place = place;
}

string Concerts::getDate()
{
    return _date;
}

void Concerts::setDAte(string date)
{
    _date = date;
}

void Concerts::displayConcert(){

    cout << endl;
    cout << "Concert place: " << getPlace() << endl;
    cout << "Concert date: " << getDate() << endl;
    cout << endl;
}

void Concerts::storeConcert(fstream& myFile){

    myFile << endl;
    myFile << "Concert place: " << getPlace() << endl;
    myFile << "Concert date: " << getDate() << endl;
    myFile << endl;
}
