#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Song.hpp"
#include "Podcast.hpp"
#include "Tracks.hpp"

using namespace std;


class PlayList
{
public:
    PlayList();
    ~PlayList();
    PlayList(string name,double duration);
    void addSongX(Song* s);
    void addPodcastX(Podcast* p);

    void addPlayListSong(Song* s);
    void addPlaylistPodcast(Podcast* p);

    void deleteSongX();
    void deletePodcastX();

    void addTrack(int i1);

    int sizeLIST(int i1,int i2);
    void storePlayListSongs(fstream& myFile);
    void storePlayListPodcat(fstream& myFile);

    void displayAllTracks(int i);
    void displayPlayList(int i);

    vector<Song *> getPlayListSongs();
    vector<Podcast *> getPlayListPodcast();

    double getTimeS();
    void setTimeS();

    double getTimeP();
    void setTimeP();

private:

    double _timeS;
    double _timeP;
    vector <Song*> allSongs;
    vector<Song*> playListSongs;
    vector<Podcast*> allPodcast;
    vector<Podcast*> playListPodcast;
};

#endif // PLAYLIST_HPP
