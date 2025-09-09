#ifndef GENERAL_HPP
#define GENERAL_HPP
#include <iostream>
#include <vector>
#include <algorithm>

#include "Artist.hpp"
#include "Creator.hpp"
#include "Playlist.hpp"


using namespace std;


class General
{
public:

    General();
    ~General();

    //Functions for add and delete
    void addArtist(Artist* Ar);
    void addCreator(Creator* Cr);
    void addNewAlbum(Album* A,int i);
    void addNewCollection(Collection* C, int i);
    void addConcertToArtist(Concerts* Con,int i);
    void deleteArtist(int index);
    void deleteCreator(int index);

    //Functions for display information
    int displayArtistList();
    int displayCreatorList();
    void displayTreeStructureArtist(int i, Concerts* Con);
    void displayTreeStructureCreator(int i);
    void displayArtistAlbumList(int i);
    void displayCreatorCollectionList(int i);
    void displayConcertList(int i);


    //Functions for store
    void storeTreeStructureArtist(Artist* Ar, fstream& myFile, Concerts* Con);
    void storeTreeStructureCreator(Creator* Cr, fstream& myFile);

    int seeMEMORY();
    vector<Artist *> getArtistList();
    vector<Creator *> getCreatorList();

private:

    vector <Artist*> artistList;
    vector <Creator*> creatorList;

};

#endif // GENERAL_HPP
