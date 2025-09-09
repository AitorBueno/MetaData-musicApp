#include "Playlist.hpp"

PlayList::PlayList()
{

}

PlayList::~PlayList()
{

}

void PlayList::addSongX(Song *s)
{
    allSongs.push_back(s);
}

void PlayList::addPodcastX(Podcast *p)
{
    allPodcast.push_back(p);
}

void PlayList::addPlayListSong(Song *s)
{
    playListSongs.push_back(s);
}

void PlayList::addPlaylistPodcast(Podcast *p)
{
    playListPodcast.push_back(p);
}

void PlayList::deleteSongX()
{
    string name;
    cout << "Introduce the song name to delete: " << endl;
    cin >> name;

    for (auto it = playListSongs.begin(); it != playListSongs.end(); ++it) {
        if ((*it)->getName() == name) {
            playListSongs.erase(it);
            cout << endl;
            cout << "-----  SONG DELETED CORRECTLY  -----" << endl;
            cout << endl;
            return;
        }
    }
    cout << "ERROR: Song not found" << endl;
}

void PlayList::deletePodcastX()
{
    string name;
    cout << "Introduce the podcast name to delete: " << endl;
    cin >> name;

    for (auto it = playListPodcast.begin(); it != playListPodcast.end(); ++it) {
        if ((*it)->getName() == name) {
            playListPodcast.erase(it);
            cout << endl;
            cout << "-----  PODCAST DELETED CORRECTLY  -----" << endl;
            cout << endl;
            return;
        }
    }
    cout << "ERROR: Podcast not found" << endl;
}

void PlayList::addTrack(int i) // Save song and podcast in sort order
{
    if(i==1){

        string name;
        int i=0;
        cout << "Introduce the name of the song to add" << endl;
        cin >> name;

        for (auto Song : allSongs) {
            if (Song->getName() == name) {
                playListSongs.push_back(Song);
                cout << endl;
                cout << "-----  SONG ADDED CORRECTLY  -----" << endl;
                cout << endl;


            }
            if(Song->getName()!=name){
                i++;
            }
        }
        if(i==allSongs.size()){
            cout << "ERROR: Song not found" << endl;
        }

        sort(playListSongs.begin(), playListSongs.end(), [](Song* s1, Song* s2) {
            return s1->getName() < s2->getName();
        });

    }
    if(i==2){
        string name;
        int i=0;
        cout << "Introduce the name of the podcast to add" << endl;
        cin >> name;

        for (auto Podcast : allPodcast) {
            if (Podcast->getName() == name) {
                playListPodcast.push_back(Podcast);
                cout << endl;
                cout << "-----  PODCAST ADDED CORRECTLY  -----" << endl;
                cout << endl;
            }
            if (Podcast->getName() != name) {
                i++;
            }
        }
        if(i==allPodcast.size()){
            cout << "ERROR: Podcast not found" << endl;
        }

        sort(playListPodcast.begin(), playListPodcast.end(), [](Podcast* p1, Podcast* p2) {
            return p1->getName() < p2->getName();
        });

    }
}

int PlayList::sizeLIST(int i1, int i2)
{

    if(i1==1){
        if(i2==1){
           int size = allSongs.size();
            return size;
        }
        if(i2==2 || i2==3){
            int size = playListSongs.size();
            return size;
        }
    }
    if(i1==2){
        if(i2==1){
           int size = allPodcast.size();
            return size;
        }
        if(i2==2 || i2==3){
            int size = playListPodcast.size();
            return size;
        }

    }
}

void PlayList::storePlayListSongs(fstream &myFile)
{
    try {
        if (playListSongs.empty()) {
            throw string("Any song playlist save");
        }
        myFile << "-------------------------------" << endl;
        myFile << " PLAYLIST " << endl;
        myFile << "-------------------------------" << endl;
        int nTrack=1;
        for (Song* A : playListSongs) {

            A->storeTrack(myFile, nTrack);
            myFile << endl;
            nTrack++;
        }
    }
    catch (string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void PlayList::storePlayListPodcat(fstream &myFile)
{
    try {
        if (playListPodcast.empty()) {
            throw string("Any podcast playlist save");
        }
        myFile << "-------------------------------" << endl;
        myFile << " PLAYLIST " << endl;
        myFile << "-------------------------------" << endl;
        int nTrack=1;
        for (Podcast* p : playListPodcast) {

            p->storeTrack(myFile, nTrack);
            myFile << endl;
            nTrack++;
        }
    }
    catch (string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void PlayList::displayAllTracks(int i){

    if(i==1){
        for(Song* s : this->allSongs){
            s->displayTrack();
        }
    }
    if(i==2){
        for(Podcast* p : this->allPodcast){
            p->displayTrack();
        }
    }

}

void PlayList::displayPlayList(int i)
{
    if(i==1){
        setTimeS();
        cout << "-------------------------------" << endl;
        cout << " PLAYLIST, total duration " << getTimeS() << " min " << endl;
        cout << "-------------------------------" << endl;

        for(Song* s : this->playListSongs){
            cout << endl;
            s->displayTrack();
            cout << endl;
        }
    }
    if(i==2){
        setTimeP();
        cout << "-------------------------------" << endl;
        cout << " PLAYLIST, total duration " << getTimeP() << " min " << endl;
        cout << "-------------------------------" << endl;

        for(Podcast* p : this->playListPodcast){
            cout << endl;
            p->displayTrack();
            cout << endl;
        }
    }
}

vector<Song *> PlayList::getPlayListSongs()
{
    return playListSongs;
}

vector<Podcast *> PlayList::getPlayListPodcast()
{
    return playListPodcast;
}

double PlayList::getTimeS()
{
    return _timeS;
}

void PlayList::setTimeS()
{
    double time = 0;


        for (int i = 0; i < playListSongs.size(); i++) {
            time += playListSongs[i]->getDuration();
        }

        this->_timeS = time;
}

double PlayList::getTimeP()
{
    return _timeP;
}

void PlayList::setTimeP()
{
    double time = 0;


        for (int i = 0; i < playListPodcast.size(); i++) {
            time += playListPodcast[i]->getDuration();
        }

        this->_timeP = time;
}




