#ifndef CREATOR_HPP
#define CREATOR_HPP
#include <iostream>
#include <vector>
#include <algorithm>

#include"Collection.hpp"
#include "Person.hpp"

using namespace std;

class Creator : public Person
{
public:
    Creator();
    ~Creator();
    Creator(string name,string nationality,string birth);
    Creator* createCreator();

    void addCollection(Collection* C);
    void displayCollectionList();
    void displayCollectionPodcast(int i);
    void storeCollectionPodcast(fstream& myFile);
    string displayCreator();
    void storePerson(fstream& myFile);
    void addNewPodcast(Podcast* P,int i);
    void deleteCollection(int index);

    void deleteCollectionPodcast(int Cindex, int Pindex);


    vector<Collection *> getCollectionList() const;

private:
    vector<Collection*> collectionList;
};

#endif // CREATOR_HPP
