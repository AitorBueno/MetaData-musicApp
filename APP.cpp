#include "APP.hpp"

APP::APP()
{

}

void APP::initializeAPP(){
    Collection a1("Name","1","1","1","1");
    int option=0;
    int index;
    string answer;

    while (option != 4){
        cout << "*********************************" << endl;
        cout << "APP Menu: " << endl;
        cout << "1.Create album:" << endl;
        cout << "2.Show album:" << endl;
        cout << "3.Delete a song:" << endl;
        cout << "*********************************" << endl;

        cout << "Introduce option: " << endl;
        cin >> option;


        switch (option){

        case 1:
            do{
            a1.createPodcast();
            cout << "Another song ?(s/n) " << endl;
            cin >> answer;
            }while (answer=="s");
            break;
        case 2:
           a1.displayCollection();
            break;
        case 3:
            cout<< "Select the song to eliminate: " << endl;
            cin >> index;
           a1.deletePodcast(index -1);

            cout << "Final album:" << endl;
            a1.displayCollection();
            break;

        }
    }
}
