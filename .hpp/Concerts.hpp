#ifndef CONCERTS_HPP
#define CONCERTS_HPP
#include <iostream>
#include <limits>


using namespace std;


class Concerts
{
public:
    Concerts(string place,string date);
    Concerts();
    ~Concerts();
    Concerts* createConcert();
    void displayConcert();
    void storeConcert(fstream& myFile);

    string getPlace();
    void setPlace(string place);

    string getDate();
    void setDAte(string date);


private:
    string _place;
    string _date;
};

#endif // CONCERTS_HPP
