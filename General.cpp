#include "General.hpp"


General::General()
{

}

General::~General()
{

}

//Functions for add and delete

void General::addArtist(Artist *Ar)
{
    artistList.push_back(Ar);

    sort(artistList.begin(), artistList.end(), [](Artist* Ar1, Artist* Ar2) {
        return Ar1->getName() < Ar2->getName();
    });
}

void General::addCreator(Creator *Cr)
{
    creatorList.push_back(Cr);

    sort(creatorList.begin(), creatorList.end(), [](Creator* Cr1, Creator* Cr2) {
        return Cr1->getName() < Cr2->getName();
    });
}

void General::addNewAlbum(Album* A,int i){

    artistList[i-1]->addAlbum(A);
    cout << endl;
    cout << "-----  ALBUM ADDED CORRECTLY  -----" << endl;
    cout << endl;
}

void General::addNewCollection(Collection* C,int i){

    creatorList[i-1]->addCollection(C);
    cout << endl;
    cout << "-----  COLLECTION ADDED CORRECTLY  -----" << endl;
    cout << endl;
}

void General::addConcertToArtist(Concerts *Con, int i)
{
    artistList[i-1]->addConcert(Con);
    cout << endl;
    cout << "-----  CONCERT ADDED CORRECTLY  -----" << endl;
    cout << endl;
}

void General::deleteArtist(int index)
{
    if(index >= 0 && static_cast<vector<Artist*>::size_type>(index) < artistList.size()){
        artistList.erase(artistList.begin() + index);
        cout << endl;
        cout << "-----  ARTIST DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else { cout << "Introduce valid position: " << endl;}

}

void General::deleteCreator(int index)
{
    if(index >= 0 && static_cast<vector<Artist*>::size_type>(index) < creatorList.size()){
        creatorList.erase(creatorList.begin() + index);
        cout << endl;
        cout << "-----  CREATOR DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else { cout << "Introduce valid position: " << endl;}
}

//Functions for display information

int General::displayArtistList()
{

    try {
        if (artistList.empty()) {

            throw "Error";
        }

        cout << "Artist list: " << endl;
        int i = 1;
        for (Artist* Ar : artistList) {
            cout<< endl;
            cout << i << "." << Ar->displayArtist();
            cout << endl;
            i++;
        }
    } catch (const char* error) {
        cout << error << endl;
        return 0;
    }

    return 1;
}

int General::displayCreatorList()
{

    try {
        if (creatorList.empty()) {

            throw "Error";
        }
        cout << "Creator list: " << endl;
        int i = 1;
        for (Creator* Cr : creatorList) {
            cout << endl;
            cout << i << "." << Cr->displayCreator();
            cout << endl;
            i++;
        }
    } catch (const char* error) {
        cout << error << endl;
        return 0;
    }

    return 1;
}

void General::displayTreeStructureArtist(int i, Concerts *Con)
{
    artistList[i-1]->displayPerson();
    int numberA=1,numberS;
    if (Con != nullptr){//Displays the concerts
        cout << "****************************************" << endl;
        for (Concerts* Con : artistList[i-1]->getConcertList()){
            cout << "Concert " << numberA << endl;
            numberA++;
            Con->displayConcert();
        }
    }
    numberA=1;

    for(Album* A : artistList[i-1]->getAlbumList()){

        cout << "****************************************" << endl;
        cout << "Album " << numberA << endl;
        numberA++;
        A->displayGroup();
        cout << "****************************************" << endl;
        numberS=0;

        for(Song* s : A->getSongList()){
            numberS++;
            cout << "Song " << numberS << endl;
            s->displayTrack();

        }
    }
    cout << "****************************************" << endl;
    cout << endl;
}

void General::displayTreeStructureCreator(int i)
{
    creatorList[i-1]->displayPerson();
    int numberC=1,numberP;

    for(Collection* C : creatorList[i-1]->getCollectionList()){

        cout << "****************************************" << endl;
        cout << "Collection " << numberC << endl;
        numberC++;
        C->displayGroup();
        cout << "****************************************" << endl;
        numberP = 0;

        for(Podcast* p : C->getPodcastList()){
            numberP++;
            cout << "Podcast " << numberP << endl;
            p->displayTrack();

        }
    }
    cout << "****************************************" << endl;
    cout << endl;
        }

void General::displayArtistAlbumList(int i){

    int number=1;

    for(Album* A : artistList[i-1]->getAlbumList()){

        cout << "****************************************" << endl;
        cout << "Album " << number << endl;
        number++;
        A->displayAlbumInfo();
        cout << endl;

    }

}

void General::displayCreatorCollectionList(int i)
{
    int number=1;

    for(Collection* C : creatorList[i-1]->getCollectionList()){

        cout << "****************************************" << endl;
        cout << "Collection " << number << endl;
        number++;
        C->displayCollectionInfo();

    }
}

void General::displayConcertList(int i)
{
    int number = 1;

    for(Concerts* Con: artistList[i-1]->getConcertList()){
        cout <<"Concert " << number << endl;
        Con->displayConcert();
        cout << endl;

    }

}

//Functions for store

void General::storeTreeStructureArtist(Artist* Ar, fstream& myFile, Concerts* Con)
{

    int nAlbum =1;
    int nSong =1;
    Ar->storePerson(myFile);
    if (Con != nullptr){//Stores the concerts
        myFile << "****************************************" << endl;
        for (Concerts* Con : Ar->getConcertList()){
            myFile << "Concert " << nAlbum << endl;
            nAlbum++;
            Con->storeConcert(myFile);
        }
    }
    nAlbum=1;

    for(Album* A : Ar->getAlbumList()){

        myFile << "****************************************" << endl;
        myFile << "Album " << nAlbum << endl;
        nAlbum++;
        A->storeGroup(myFile);
        myFile << "****************************************" << endl;

        for(Song* s : A->getSongList()){
            s->storeTrack(myFile, nSong);

        }
    }
    myFile <<"******************************************" << endl;
}

void General::storeTreeStructureCreator(Creator *Cr, fstream &myFile)
{
    int nCollection=1;
    int nPodcast=1;
    Cr->storePerson(myFile);

    for(Collection* C : Cr->getCollectionList()){

        myFile << "****************************************" << endl;
        myFile << "Collection " << nCollection << endl;
        nCollection++;
        C->storeGroup(myFile);
        myFile << "****************************************" << endl;

        for(Podcast* p : C->getPodcastList()){
            p->storeTrack(myFile, nPodcast);

        }
    }
    myFile <<"******************************************" << endl;
}



vector<Artist *> General::getArtistList()
{
    return artistList;
}

vector<Creator *> General::getCreatorList()
{
    return creatorList;
}

int General::seeMEMORY(){

    if  (artistList.empty() && creatorList.empty()){
        return 0;
    }
    return 1;
}
