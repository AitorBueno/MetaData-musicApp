#ifndef TRACKS_HPP
#define TRACKS_HPP
#include <iostream>
#include <fstream>


using namespace std;

class Tracks
{
public:
    Tracks();
    Tracks(string name, int duration);

    string getName();
    int getDuration();

    virtual void displayTrack();
    virtual void storeTrack(fstream& myFile, int nTrack);

protected:
    int _duration;
    string _name;
};

#endif // TRACKS_HPP
