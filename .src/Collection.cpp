#include "Collection.hpp"
#include <fstream>

Collection::Collection(){

}

Collection::~Collection()
{

}

Collection::Collection(string name,string rate,int year,string theme,string summary):GroupAC(name,rate,year)
{
    this->_theme=theme;
    this->_summary=summary;
}

void Collection::addPodcast(Podcast* p)
{
  podcastList.push_back(p);

  sort(podcastList.begin(), podcastList.end(), [](Podcast* p1, Podcast* p2) {
      return p1->getName() < p2->getName();
  });
}

void Collection::deletePodcast(int index)
{
    if(index >= 0&& index < podcastList.size()){
        podcastList.erase(podcastList.begin() + index);
        cout << endl;
        cout << "-----  PODCAST DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else { cout << "Introduce valid position: " << endl;}

}

void Collection::displayPodcastList()
{

        try {
            if (podcastList.empty()) {
                throw string("Empty song list!");
            }
            for (Podcast* C : podcastList) {
                cout << "Song List " << endl;
                C->displayTrack();
                cout << endl;
            }
        }
        catch (string& errorMessage) {
            cout << "Error: " << errorMessage << endl;
        }
}

string Collection::getTheme()
{
    return _theme;
}

void Collection::setTheme(string theme)
{
    _theme = theme;
}

string Collection::getSummary()
{
    return _summary;
}

void Collection::setSummary(string summary)
{
    _summary = summary;
}

void Collection::storePodcastList(fstream& myFile){
    try {
        if (podcastList.empty()) {
            throw string("Empty song list!");
        }
        int nTrack=1;
        for (Podcast* C : podcastList) {

            C->storeTrack(myFile, nTrack);
            myFile << endl;
            nTrack++;
        }
    }
    catch (string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

Collection* Collection::createCollection(){

    string name,rate,theme,summary;
    int year;
    cin.ignore();
    cout << endl;
    cout << "   Collection name: ";
    getline(cin,name);
    cout << "   Collection rate: ";
    getline(cin,rate);
    cout << "   Collection year: ";

    while (!(cin >> year)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }

    cin.ignore();
    cout << "   Collection theme: " ;
    getline(cin,theme);
    cout << "   Collection summary: ";
    getline(cin,summary);
    cout << endl;

    Collection* C=new Collection(name,rate,year,theme,summary);
    return C;
}

void Collection::displayGroup(){

    cout << "   Name: " << getName() << endl;
    cout << "   Rate: " << getRate() << endl;
    cout << "   Year: " << getYear() << endl;
    cout << "   Theme: " << getTheme() << endl;
    cout << "   Summary: " << getSummary() << endl;


}

void Collection::storeGroup(fstream& myFile){

    myFile << "Name: " << getName() << endl;
    myFile << "Rate: " << getRate() << endl;
    myFile << "Year: " << getYear() << endl;
    myFile << "Theme: " << getTheme() << endl;
    myFile << "Summary: " << getSummary() << endl;


}

void Collection::displayCollectionInfo(){

     cout << getName() + ", Nº Podcast, " + to_string(podcastList.size()) + "\n";
}

vector<Podcast *> Collection::getPodcastList() const
{
    return podcastList;
}
