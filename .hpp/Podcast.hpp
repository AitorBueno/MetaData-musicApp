#ifndef PODCAST_HPP
#define PODCAST_HPP
#include <iostream>
#include <limits>

#include"Tracks.hpp"

using namespace std;

class Podcast :public Tracks
{
public:
    Podcast();
    ~Podcast();
    Podcast(string name, int duration, string description, string publicationDate);
    Podcast* createPodcast();
    void displayTrack();
    void storeTrack(fstream& myFile, int nTrack);

    string getDescription();
    void setDescription(string description);

    string getPublicationDate();
    void setPublicationDate(string publicationDate);


private:
    string _description,_publicationDate;
};

#endif // PODCAST_HPP
