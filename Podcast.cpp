#include "Podcast.hpp"

Podcast::Podcast(){

}

Podcast::~Podcast()
{

}

Podcast::Podcast(string title,int duration,string description,string publicationDate):Tracks(title,duration)
{
    _description=description;
    _publicationDate=publicationDate;
}

Podcast* Podcast::createPodcast(){

    string title,description,publicationDate;
    int duration;
    cin.ignore();
    cout << endl;
    cout << "       Podcast title: ";
    getline(cin,title);
    cout << "       Podcast duration: ";

    while (!(cin >> duration)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }

    cin.ignore();
    cout << "       Podcast description: ";
    getline(cin,description);
    cout << "       Podcast publication date: ";
    getline(cin,publicationDate);
    cout << endl;
    Podcast* p=new Podcast(title,duration,description,publicationDate);
    return p;
}

void Podcast::displayTrack(){

    cout << endl;
    cout << "       Name: " << getName() << endl;
    cout << "       Duration: " << getDuration() << endl;
    cout << "       Description" << getDescription() << endl;
    cout << "       Publication date: " << getPublicationDate() << endl;
    cout << endl;
}

void Podcast::storeTrack(fstream& myFile, int nTrack)
{
    myFile << endl;
    myFile << "Episode " << nTrack <<endl;
    myFile << "Name: " << getName() << endl;
    myFile << "Duration: " << getDuration() << endl;
    myFile << "Description: " << getDescription() << endl;
    myFile << "Publication date: " << getPublicationDate() << endl;
}

string Podcast::getDescription()
{
    return _description;
}

void Podcast::setDescription(string description)
{
    _description = description;
}

string Podcast::getPublicationDate()
{
    return _publicationDate;
}

void Podcast::setPublicationDate(string publicationDate)
{
    _publicationDate = publicationDate;
}
