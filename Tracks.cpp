#include "Tracks.hpp"

Tracks::Tracks(){

}

Tracks::Tracks(string name,int duration)
{
    _name=name;
    _duration=duration;
}

string Tracks::getName()
{
    return _name;
}

int Tracks::getDuration()
{
    return _duration;
}

void Tracks::displayTrack(){

}

void Tracks::storeTrack(fstream& myFile, int nTrack)
{
    myFile << "Track " << nTrack <<endl;
}


