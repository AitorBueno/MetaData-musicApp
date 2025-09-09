#include "Album.hpp"
#include "Artist.hpp"

Album::Album()
{

}

Album::~Album()
{

}

Album::Album(string name, string rate, int year, double totalDuration):GroupAC(name,rate,year)
{
    this->_totalDuration=totalDuration;
}

Album* Album::createAlbum(){

    string name,rate;
    double totalDuration=0;
    int year;

    cout << endl;
    cin.ignore();
    cout << "   Album name: ";
    getline(cin,name);
    cout << "   Album rate: ";
    getline(cin,rate);
    cout << "   Album year: ";

    while (!(cin >> year)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignores the wrong value
        cout << "Invalid input. Please enter an integer: ";
    }

    cout << endl;

    Album* A=new Album(name,rate,year,totalDuration);
    return A;

}

double Album::getTotalDuration()
{

    return _totalDuration;
}

void Album::setTotalDuration()
{
    double totalDuration = 0;


        for (int i = 0; i < songList.size(); i++) {
            totalDuration += songList[i]->getDuration();
        }

        this->_totalDuration = totalDuration;

}

void Album::addSong(Song* s){
    songList.push_back(s);
    setTotalDuration();
    sort(songList.begin(), songList.end(), [](Song* s1, Song* s2) {
        return s1->getName() < s2->getName();
    });
}

void Album::deleteSong(int index){

    if (index >= 0 && index < songList.size()) {
        songList.erase(songList.begin() + index);
        cout << endl;
        cout << "-----  SONG DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else {
        cout << "Introduce a valid position." << endl;
    }
    setTotalDuration();
}

void Album::displaySongList(){

    try {
        if (songList.empty()) {
            throw string("Empty song list!");
        }
        for (Song* A : songList) {
            cout << "Song List " << endl;
            A->displayTrack();
            cout << endl;
        }
    }
    catch (string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void Album::storeSongList(fstream &myFile)
{
    try {
        if (songList.empty()) {
            throw string("Empty song list!");
        }
        int nTrack=1;
        for (Song* A : songList) {
            myFile << "Song List " << endl;
            A->storeTrack(myFile, nTrack);
            myFile << endl;
            nTrack++;
        }
    }
    catch (string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void Album::displayGroup(){

    cout << "   Name: " << getName() << endl;
    cout <<"   Rate: " << getRate() << endl;
    cout <<"   Year: " << getYear() << endl;
    cout <<"   Total duration: " << getTotalDuration() << endl;
}

void Album::storeGroup(fstream& myFile)
{
    myFile << "Name: " << getName() << endl;
    myFile << "Rate: " << getRate() << endl;
    myFile << "Year: " << getYear() << endl;
    myFile << "Total duration: " << getTotalDuration() << endl;
}

void Album::displayAlbumInfo(){

    cout << getName() + ", Nº Songs, " + to_string(songList.size()) + "\n";

}

vector<Song *> Album::getSongList() const
{
    return songList;
}

