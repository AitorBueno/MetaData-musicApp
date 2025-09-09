#ifndef APP_MENU_HPP
#define APP_MENU_HPP
#include <iostream>
#include <vector>

#include "Song.hpp"
#include "Album.hpp"
#include "Podcast.hpp"
#include "Collection.hpp"
#include "Groupac.hpp"
#include "Artist.hpp"
#include "APP.hpp"
#include"Person.hpp"
#include "Creator.hpp"
#include "General.hpp"
#include "Concerts.hpp"
#include "Playlist.hpp"

class APP_menu
{
public:

    APP_menu();
    ~APP_menu();

    //Function for menu
    int menu();
    int submenu(int option,string a, string b);
    void APPmenu();
    string another(string & answer, string a);

    //Function for create
    Song* createSong(PlayList& P);
    Podcast* createPodcast(PlayList& P);
    Album* createAlbum(PlayList& P);
    Collection* createCollection(PlayList& P);
    Artist* createArtist(PlayList& P);
    Creator* createCreator(PlayList& P);

    //Function to read the .txt file
    void readArtist(General* g);
    void readCreator(General* g);
    void readPlayListSong(PlayList P);
    void readPlayListPodcast(PlayList P);

    int getsizeA();
    void setSizeA(General& g);
    int getsizeC();
    void setSizeC(General& g);

private:
    int _sizeA;
    int _sizeC;
    General* g;
    Song* s;
    Podcast* p;
    Album* A;
    Collection* C;
    Artist* Ar;
    Creator* Cr;
    Concerts* Con;
    PlayList play;



};

//Plus template function to introduce the option in MENU, SUBMENU and ANOTHER
template <typename T>
T selection(){
    T select;
    cout << "Select the option: " << endl;
    cin >> select;
    return select;

}
#endif // APP_MENU_HPP
