#ifndef ARTIST_HPP
#define ARTIST_HPP
#include <iostream>
#include <vector>
#include <algorithm>

#include "Album.hpp"
#include "Person.hpp"
#include "Concerts.hpp"


using namespace std;


class Artist : public Person
{
public:
    Artist();
    ~Artist();
    Artist(string name,string nationality,string birth);
    Artist* createArtist();

    void addAlbum(Album* A);
    void addNewSong(Song* S,int i);
    void addConcert(Concerts* Con);
    void deleteAlbum(int index);
    void displayAlbumSong(int i);
    void storeAlbumSong(fstream& myFile);
    void storePerson(fstream& myFile);

    string displayArtist();
    void deleteAlbumSong(int Aindex,int Sindex);

    vector<Album *>& getAlbumList();
    vector<Concerts *> getConcertList();

private:

    vector<Concerts*> concertList;
    vector<Album*> albumList;



};

#endif // ARTIST_HPP
