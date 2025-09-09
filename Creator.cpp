#include "Creator.hpp"
#include "Podcast.hpp"

Creator::Creator()
{

}

Creator::~Creator()
{

}

Creator::Creator(string name, string nationality, string birth)
    :Person(name,nationality,birth)
{

}

Creator *Creator::createCreator()
{
    string name,nationality,birth;
    cin.ignore();
    cout << endl;
    cout << "Creator name: ";
    getline(cin,name);
    cout << "Creator nationality: ";
    getline(cin,nationality);
    cout << "Creator birth: ";
    getline(cin,birth);
    cout << endl;

    Creator* C=new Creator(name,nationality,birth);
    return C;
}

void Creator::addCollection(Collection *C)
{
    collectionList.push_back(C);

    sort(collectionList.begin(), collectionList.end(), [](Collection* C1, Collection* C2) {
        return C1->getYear() > C2->getYear();
    });

}

void Creator::displayCollectionList()
{
    cout << "Collection list: " << endl;
    for(Collection* C : collectionList){
        C->displayGroup();
        cout << endl;
    }
}

void Creator::displayCollectionPodcast(int i)
{
    for (Podcast* p : collectionList[i-1]->getPodcastList()){
        cout<<endl;
        p->displayTrack();
        cout<<endl;
    }

}

void Creator::storeCollectionPodcast(fstream& myFile)
{
    myFile << endl;
         myFile << "collection list: " << endl;
         for(Collection* C : collectionList){
             myFile <<"******************************************" << endl;
             C->storeGroup(myFile);
             myFile <<"******************************************" << endl;
             C->storePodcastList(myFile);
             myFile << endl;
         }

}

string Creator::displayCreator(){

    string output = _name + ", Nº Collections, " + to_string(collectionList.size()) + "\n";

    return output;

}

void Creator::addNewPodcast(Podcast* P,int i)
{
    collectionList[i-1]->addPodcast(P);
    cout << endl;
    cout << "-----  PODCAST ADDED CORRECTLY  -----" << endl;
    cout << endl;
}

void Creator::deleteCollection(int index){

    if(index >= 0&& index < collectionList.size()){
        collectionList.erase(collectionList.begin() + index);
        cout << endl;
        cout << "-----  COLLECTION DELETE CORRECTLY  -----" << endl;
        cout << endl;
    } else { cout << "Introduce valid position: " << endl;}
}

void Creator::deleteCollectionPodcast(int Cindex,int  Pindex)
{
    if (Cindex >= 0 && Cindex < collectionList.size()) {
                collectionList[Cindex]->deletePodcast(Pindex);
            }
            else {
                cout << "Introduce valid album position." << endl;
            }
}

vector<Collection *> Creator::getCollectionList() const
{
    return collectionList;
}

void Creator::storePerson(fstream& myFile)
{
    myFile << endl << "Creator" << endl;
    myFile << "Name: " << _name << endl;
    myFile << "Birth: " << _birth << endl;
    myFile << "Nationality: " << _nationality << endl;
}
