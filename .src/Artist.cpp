#include <vector>
#include "Artist.hpp"
#include "Album.hpp"
#include "Song.hpp"
#include "Concerts.hpp"

Artist::Artist(){

}

Artist::~Artist()
{

}

Artist::Artist(string name,string nationality,string birth)
    :Person(name,nationality,birth)
{

}

Artist* Artist::createArtist(){

    string name,nationality,birth;
    cin.ignore();
    cout << endl;
    cout << "Artist name: ";
    getline(cin,name);
    cout << "Artist nationality: ";
    getline(cin,nationality);
    cout << "Artist birth: ";
    getline(cin,birth);
    cout << endl;

    Artist* Ar=new Artist(name,nationality,birth);
    return Ar;
}

void Artist::addAlbum(Album *A)
{
    albumList.push_back(A);

    sort(albumList.begin(), albumList.end(), [](Album* A1, Album* A2) {
        return A1->getYear() > A2->getYear();
    });

}

void Artist::addNewSong(Song *S,int i)
{
    albumList[i-1]->addSong(S);
    cout << endl;
    cout << "-----  SONG ADDED CORRECTLY  -----" << endl;
    cout << endl;
}

void Artist::addConcert(Concerts *Con)
{
    concertList.push_back(Con);

    sort(concertList.begin(), concertList.end(), [](Concerts* Con1, Concerts* Con2) {
        return Con1->getDate() > Con2->getDate();
    });
}

void Artist::deleteAlbum(int index){

    if(index >= 0&& index < albumList.size()){
        albumList.erase(albumList.begin() + index);
        cout << endl;
        cout << "-----  ALBUM DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else { cout << "Introduce valid position: " << endl;}

}

void Artist::displayAlbumSong(int i){

    sort(albumList.begin(), albumList.end(), [](Album* A1, Album* A2) {
        return A1->getYear() > A2->getYear();
    });


    for (Song* s : albumList[i-1]->getSongList()){
        cout<<endl;
        s->displayTrack();
        cout<<endl;
    }

}

void Artist::storeAlbumSong(fstream& myFile){

        myFile << endl;
        myFile << "album list: " << endl;
        for(Album* A : albumList){
            myFile <<"******************************************" << endl;
            A->storeGroup(myFile);

            myFile <<"******************************************" << endl;
            A->storeSongList(myFile);
            myFile << endl;
        }

}

void Artist::storePerson(fstream &myFile)
{

        myFile << endl << "Artist" << endl;
        myFile << "Name: " << _name << endl;
        myFile << "Birth: " << _birth << endl;
        myFile << "Nationality: " << _nationality << endl;

}

string Artist::displayArtist(){

    string output = _name + ", Nº Albums, " + to_string(albumList.size()) + "\n";

    return output;

}

void Artist::deleteAlbumSong(int Aindex, int Sindex)
{
    if (Aindex >= 0 && Aindex < albumList.size()) {
                albumList[Aindex]->deleteSong(Sindex);
            }
            else {
                cout << "Introduce valid album position." << endl;
            }
}

vector<Concerts *> Artist::getConcertList()
{
    return concertList;
}

vector<Album *> &Artist::getAlbumList()
{
    return albumList;
}



