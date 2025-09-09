#include <limits>
#include<iostream>
#include "Song.hpp"


using namespace std;

Song::Song(){

}
Song::~Song()
{

}

Song::Song(string title,int duration,string genre, string lyrics):Tracks(title,duration)
{ 
    _genre = genre;
    _lyrics = lyrics;
}

Song* Song::createSong(){

    string title,genre,lyrics;
    int duration;

    cin.clear();cin.ignore(10000,'\n');
    cout << "       Song title: ";
    getline(cin,title);
    cout << "       Song genre: ";
    getline(cin,genre);
    cout << "       Song duration (min): ";
    while (!(cin >> duration)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }
    cin.ignore();
    cout << "       Song lyrics: ";
    getline(cin,lyrics);

    cout << endl;

    Song* s=new Song(title,duration,genre,lyrics);
    return s;
}

void Song::displayTrack(){

    cout << endl;
    cout << "       Name: " << getName() << endl;
    cout << "       Duration: " << getDuration() << endl;
    cout << "       Genre: " << getGenre() << endl;
    cout << "       Lyrics: " << getLyrics() << endl;
    cout << endl;
}

void Song::storeTrack(fstream& myFile, int nTrack)
{
    myFile << endl;
    myFile << "Song " << nTrack <<endl;
    myFile << "Name: " << getName() << endl;
    myFile << "Duration: " << getDuration() << endl;
    myFile << "Genre: " << getGenre() << endl;
    myFile << "Lyrics: " << getLyrics() << endl;
}

string Song::getGenre()
{
    return _genre;
}

void Song::setGenre(string genre)
{
    _genre = genre;
}

string Song::getLyrics()
{
    return _lyrics;
}

void Song::setLyrics(string lyrics)
{
    _lyrics = lyrics;
}


