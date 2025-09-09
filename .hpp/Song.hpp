#ifndef SONG_HPP
#define SONG_HPP
#include <iostream>
#include <vector>

#include "Tracks.hpp"


using namespace std;

class Song : public Tracks
{
public:
    Song();
    Song(string title, int duration, string genre, string lyrics);
    Song* createSong();
    ~Song();
    void displayTrack();
    void storeTrack(fstream& myFile, int nTrack);

    string getGenre();
    void setGenre(string genre);

    string getLyrics();
    void setLyrics(string lyrics);

    void addSongX(Song* s);


private:
    string _genre,_lyrics;
};

#endif // SONG_HPP
