#ifndef COLLECTION_HPP
#define COLLECTION_HPP
#include<iostream>
#include<vector>
#include <algorithm>

#include"Podcast.hpp"
#include "Groupac.hpp"

using namespace std;

class Collection : public GroupAC
{
public:
    Collection();
    ~Collection();
    Collection(string name,string rate,int year,string theme,string summary);
    Collection* createCollection();

    string getTheme();
    void setTheme(string theme);
    string getSummary();
    void setSummary(string summary);

    void displayGroup();

    void addPodcast(Podcast* p);
    void deletePodcast(int index);
    void displayPodcastList();
    void storePodcastList(fstream& myFile);
    void storeGroup(fstream& myFile);

    void displayCollectionInfo();



    vector<Podcast *> getPodcastList() const;

private:

    string _theme;
    string _summary;
    vector<Podcast*> podcastList;

};

#endif // COLLECTION_HPP
