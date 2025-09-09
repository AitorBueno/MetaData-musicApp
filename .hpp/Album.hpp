#ifndef ALBUM_HPP
#define ALBUM_HPP
#include<iostream>
#include<vector>

#include "Song.hpp"
#include"Groupac.hpp"

using namespace std;

class Album : public GroupAC
{
public:
    Album();
    ~Album();
    Album(string name,string rate,int year,double totalDuration);
    Album* createAlbum();

    double getTotalDuration();
    void setTotalDuration();
    void displayGroup();
    void storeGroup(fstream& myFile);
    void addSong(Song* s);
    void deleteSong(int index);
    void displaySongList();
    void storeSongList(fstream& myFile);

    void displayAlbumInfo();
    vector<Song *> getSongList() const;

private:
    double _totalDuration;
    vector<Song*> songList;

};

#endif // ALBUM_HPP
