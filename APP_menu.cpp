#include <limits>
#include "APP_menu.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>


APP_menu::APP_menu()
{

}

APP_menu::~APP_menu()
{

}

int APP_menu::menu()
{   
    setSizeA(*g);
    setSizeC(*g);

    cout << "MUSIC. ON " << endl;
    cout << "Artist created = "<< getsizeA() << endl;
    cout << "Creators created = " << getsizeC() << endl;
    cout << "*******************************" << endl;
    cout << "1. Create artist / creator" << endl;
    cout << "2. Add information" << endl;
    cout << "3. Delete information " << endl;
    cout << "4. Show the tree structure " << endl;
    cout << "5. Add / Display concert " << endl;
    cout << "6. Playlist" << endl;
    cout << "7. Close APP " << endl;
    cout << "*******************************" << endl;

   return selection<int>();
}

int APP_menu::submenu(int option,string a, string b)
{
    if (option==1){
        cout << "*******************************" << endl;
        cout << "1. Create a" << a << endl;
        cout << "2. Create a" << b << endl;
        cout << "*******************************" << endl;

    }
    if (option==2){
        cout << "*******************************" << endl;
        cout << "1. Add album " << endl;
        cout << "2. Add collection" << endl;
        cout << "3. Add song" << endl;
        cout << "4. Add podcast " << endl;
        cout << "*******************************" << endl;
    }
    if(option==3){
        cout << "*******************************" << endl;
        cout << "1. Delete a" << a << endl;
        cout << "2. Delete a" << b << endl;
        cout << "*******************************" << endl;
    }
    if(option==4){

        cout << "*******************************" << endl;
        cout << "1. " << a << " Artist tree structure" << endl;
        cout << "2. " << a << " Creator tree structure" << endl;
        cout << "*******************************" << endl;
    }
    if(option==5){
        cout << "*******************************" << endl;
        cout << "1. Create concert list" << a << endl;
        cout << "2. Display concert list" << b << endl;
        cout << "*******************************" << endl;

    }

    if(option==6){
        cout << "*******************************" << endl;
        cout << "1. Add a " << a << endl;
        cout << "2. Delete a  " << a << endl;
        cout << "3. Display PlayList" << endl;
        cout << "4. Return to the menu" << endl;
        cout << "*******************************" << endl;
    }

    return selection<int>();
}

void APP_menu::APPmenu()
{

    int option,option2;
    string answer;

        APP_menu miAPP;
        g = new General();
        s = nullptr;
        p = nullptr;
        A = nullptr;
        C = nullptr;
        Ar = nullptr;
        Cr = nullptr;
        Con = nullptr;

        //The program iniciates the .txt docs to read

        ifstream InArtist("ArtistTreeStructure.txt");
        ifstream InCreator("CreatorTreeStructure.txt");
        ifstream InPlayListSong("PlayListSong.txt");
        ifstream InPlayListPodcast("PlayListPodcast.txt");

        //With read functions the program reads the documents and save the information

        readArtist(g);
        readCreator(g);
        readPlayListSong(play);
        readPlayListPodcast(play);

        //Create file to save the information

        fstream OutArtist;
        OutArtist.open("ArtistTreeStructure.txt", ios::out);
        fstream OutCreator;
        OutCreator.open("CreatorTreeStructure.txt", ios::out);
        fstream OutPlayListSong;
        OutPlayListSong.open("PlayListSong.txt", ios::out);
        fstream OutPlayListPodcast;
        OutPlayListPodcast.open("PlayListPodcast.txt", ios::out);

        //First Menu

        cout << endl;
        cout << "-----  MUSIC.ON  -----" << endl;
        cout << " Delivered by: " << endl;
        cout << "    Jose Bailon Lobo " << endl;
        cout << "    Aitor Bueno Ulacia " << endl;
        cout << endl;
        cout << "Press ENTER to start " << endl;

   do{
        cin.ignore();

        system("clear");
        option = menu();


        try{ //We make sure that it is an integer
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw 'c';
        }
        throw option;
        }
        catch(char o){
        cout << "Invalid option, repeat" << endl;
        option = miAPP.menu();
        }
        catch(int o){}


    switch (option){

        case 1: // Create artist / creator

            system("clear");
            option2 = miAPP.submenu(option,"n Artist", " Creator");

            switch(option2){

                case 1: //Create artist
                    Ar = createArtist(play);
                    g->addArtist(Ar);
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;

                case 2: //Create creator
                    Cr = createCreator(play);
                    g->addCreator(Cr);
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
            }
            break;

        case 2: // Add information

            if(g->seeMEMORY() == 0 ){
                cout << endl;
                cout << "----- NO INFORMATION ABOUT ARTIST NEITHER CREATROR  -----" << endl;
                cout << endl;
                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;
            }
            system("clear");

            option2 = miAPP.submenu(option,"", "");

            switch (option2){
                int i;

                case 1: // Add album

                    if(g->displayArtistList() == 0){
                        cout << endl;
                        cout << "----- NO INFORMATION ARTIST  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                    }

                    cout << "Select the artist to add the album " << endl;
                    cin >> i;

                    A=createAlbum(play);
                    g->addNewAlbum(A,i);
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();

                    break;

                case 2: // Add collection

                    if(g->displayCreatorList() == 0 ){
                        cout << endl;
                        cout << "----- NO INFORMATION ABOUT CREATROR  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                    }

                    cout << "Select the creator to add the collection " << endl;
                    cin >> i;
                    C = createCollection(play);
                    g->addNewCollection(C,i);
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();

                    break;

                case 3: // Add song

                    if(g->displayArtistList() == 0){
                        cout << endl;
                        cout << "----- NO INFORMATION ARTIST  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                    }


                    cout << "Select the artist to add the song " << endl;
                    cin >> i;

                    g->displayArtistAlbumList(i);


                    cout << "Select the album to add the song " << endl;
                    cin >> i;

                    s = createSong(play);
                    Ar->addNewSong(s,i);
                    cout << "Press enter to RETURN to the MENU " << endl;

                    break;

                case 4: // Add podcast

                    if(g->displayCreatorList() == 0 ){
                        cout << endl;
                        cout << "----- NO INFORMATION ABOUT CREATROR  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                    }



                    cout << "Select the creator to add the song " << endl;
                    cin >> i;

                    g->displayCreatorCollectionList(i);


                    cout << "Select the album to add the song " << endl;
                    cin >> i;

                    p = createPodcast(play);
                    Cr->addNewPodcast(p,i);
                    cout << "Press enter to RETURN to the MENU " << endl;

                    break;

        }

        break;

        case 3: // Delete information

            if(g->seeMEMORY()==0 ){
                cout << endl;
                cout << "----- NO INFORMATION ABOUT ARTIST NEITHER CREATROR  -----" << endl;
                cout << endl;
                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;
            }

            system("clear");
            int select;
            cout << "*******************************" << endl;
            cout << "1. Delete artist / creator" << endl;
            cout << "2. Delte album / collection" << endl;
            cout << "3. Delete song / podcast " << endl;
            cout << "*******************************" << endl;
            select = selection<int>();

            switch (select){

                int index;

                case 1: // Delete person

                option2 = miAPP.submenu(option,"n Artist", " Creator");

                switch(option2){

                    case 1: // Delete artist

                        if(g->displayArtistList() == 0){

                            cout << endl;
                            cout << "----- ARTIST LIST IS EMPTY  -----" << endl;
                            cout << endl;
                            cout << "Press enter to RETURN to the MENU " << endl;
                            getchar();
                            break;
                        }

                        cout << "**********************" << endl;
                        cout << "Select Artist to be erased" << endl;
                        cin >> index;
                        g->deleteArtist(index -1);
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;

                case 2: // Delete creator

                    if(g->displayCreatorList() == 0){

                        cout << endl;
                        cout << "----- CREATOR LIST IS EMPTY  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                    }

                    cout << "**********************" << endl;
                    cout << "Select Creator to be erased" << endl;
                    cin >> index;
                    g->deleteCreator(index-1);
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }
                break;

            case 2: // Delete GroupAc

                option2 = miAPP.submenu(option,"n Album", " Collection");

                switch(option2){
                    int i;

                    case 1: // Delete Album

                        if(g->displayArtistList() == 0 ){
                        cout << endl;
                        cout << "----- NO INFORMATION ABOUT ARTIST  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                        }

                        cout << "Select the artist " << endl;
                        cin >> i;

                        g->displayArtistAlbumList(i);

                        cout << "Select the album to being deleted" << endl;
                        cin >> i;

                        Ar->deleteAlbum(i-1);
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;

                    case 2: // Delete collection

                        if(g->displayCreatorList() == 0 ){
                        cout << endl;
                        cout << "----- NO INFORMATION ABOUT CREATROR  -----" << endl;
                        cout << endl;
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                        }

                        cout << "Select the artist " << endl;
                        cin >> i;

                        g->displayCreatorCollectionList(i);

                        cout << "Select the album to being deleted" << endl;
                        cin >> i;

                        Cr->deleteCollection(i-1);
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                }
                break;


            case 3: // Delete Track

                option2 = miAPP.submenu(option," Song", " Podcast");

                switch(option2){
                    int i,Aindex,Sindex,Cindex,Pindex;

                    case 1: //Delete Song

                        if(g->displayArtistList() == 0 ){
                            cout << endl;
                            cout << "----- NO INFORMATION ABOUT ARTIST  -----" << endl;
                            cout << endl;
                            cout << "Press enter to RETURN to the MENU " << endl;
                            getchar();
                            break;
                        }

                        cout << "Select the artist " << endl;
                        cin >> i;

                        g->displayArtistAlbumList(i);

                        cout << "Select the album " << endl;
                        cin >> Aindex;

                        Ar->displayAlbumSong(Aindex);

                        cout << "Select the song to be deleted " << endl;
                        cin >> Sindex;

                        Ar->deleteAlbumSong(Aindex-1,Sindex-1);
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;

                case 2: // Delete Podcast

                        if(g->displayCreatorList() == 0 ){
                            cout << endl;
                            cout << "----- NO INFORMATION ABOUT CREATROR  -----" << endl;
                            cout << endl;
                            cout << "Press enter to RETURN to the MENU " << endl;
                            getchar();
                            break;
                        }

                        g->displayCreatorList();

                        cout << "Select the creator" << endl;
                        cin >> i;

                        g->displayCreatorCollectionList(i);

                        cout << "Select the collection" << endl;
                        cin >> Cindex;

                        Cr->displayCollectionPodcast(Cindex);

                        cout << "Select the podcast to be erased" << endl;
                        cin>>Pindex;

                        Cr->deleteCollectionPodcast(Cindex-1,Pindex-1);
                        cout << "Press enter to RETURN to the MENU " << endl;
                        getchar();
                        break;
                }
                break;

        }
        break;


        case 4: // Show tree structure

            if(g->seeMEMORY()==0 ){
                cout << endl;
                cout << "----- NO INFORMATION ABOUT ARTIST NEITHER CREATROR  -----" << endl;
                cout << endl;
                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;
            }
            system("clear");
            option2 = miAPP.submenu(option,"", "");

            switch(option2){

            int i;

            case 1: // Show artist tree structure

                if(g->displayArtistList() == 0){
                    cout << endl;
                    cout << "----- ARTIST LIST IS EMPTY  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                cout << "Select the artist to display tree structure " << endl;
                cin >> i;
                system("clear");
                cout << "-------------------------------" << endl;
                cout << " ARTIST TREE STRUCTURE " << endl;
                cout << "-------------------------------" << endl;
                g->displayTreeStructureArtist(i, Con);
                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();

                break;

            case 2:  //Show creator tree structure

                if (g->displayCreatorList() == 0){
                    cout << endl;
                    cout << "----- CREATOR LIST IS EMPTY  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                cout << "Select the artist to display tree structure" << endl;
                cin >> i;
                cout << "-------------------------------" << endl;
                cout << " CREATOR TREE STRUCTURE " << endl;
                cout << "-------------------------------" << endl;
                g->displayTreeStructureCreator(i);
                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

            }

        break;


    case 5://Concerts

        if(g->seeMEMORY() == 0){
            cout << endl;
            cout << "----- NO INFORMATION ARTIST  -----" << endl;
            cout << endl;
            cout << "Press enter to RETURN to the MENU " << endl;
            getchar();
            break;
        }
        system("clear");
        option2 = miAPP.submenu(option,"","");

        switch (option2){
        int i;

            case 1: //Create concert
                g->displayArtistList();
                cout << "Select the artist to add the concert " << endl;
                cin >> i;
                Con=Con->createConcert();
                g->addConcertToArtist(Con,i);

                cout << "Press enter to RETURN to the MENU " << endl;
                break;

            case 2: //Display concerts
                g->displayArtistList();
                cout << "---- Select an Artist ----" << endl;
                cin >> i;
                g->displayConcertList(i);
                cout << endl;

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;
        }
        break;

    case 6: // Playlist

        int optionP;
        int SoP;

        cout << "*******************************" << endl;
        cout << "1. Songs playList" << endl;
        cout << "2. Podcast playList" << endl;
        cout << "*******************************" << endl;
        cin >> SoP;

        switch(SoP){

        case 1: // Playlist Song

            do{
            getchar();
            system("clear");
            optionP =miAPP.submenu(option,"Song","");

            switch (optionP){

                case 1: // Add song to playlist
                if ( play.sizeLIST(SoP,optionP)== 0){
                    cout << endl;
                    cout << "----- NO SONGS SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                play.displayAllTracks(SoP);
                play.addTrack(SoP);

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

                case 2: // Delete a song in playlist
                if ( play.sizeLIST(SoP,2)== 0){
                    cout << endl;
                    cout << "----- NO SONGS SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }


                play.displayPlayList(SoP);
                play.deleteSongX();

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

                case 3: //Show PLAYLIST

                if ( play.sizeLIST(SoP,3)== 0){
                    cout << endl;
                    cout << "----- NO SONGS SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                play.displayPlayList(SoP);

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

            }
            }while(optionP!=4);
            break;

        case 2: //Playlist Podcast

            do{
            getchar();
            system("clear");
            optionP =miAPP.submenu(option,"Podcast", "");

            switch (optionP){

                case 1: // Add podcast to playlist
                if ( play.sizeLIST(SoP,optionP)== 0){
                    cout << endl;
                    cout << "----- NO PODCAST SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                play.displayAllTracks(SoP);
                play.addTrack(SoP);

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

                case 2: // Delete a podcast in playlist
                if ( play.sizeLIST(SoP,2)== 0){
                    cout << endl;
                    cout << "----- NO PODCAST SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                play.displayPlayList(SoP);
                play.deletePodcastX();

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

                case 3: //Show PLAYLIST

                if ( play.sizeLIST(SoP,3)== 0){
                    cout << endl;
                    cout << "----- NO PODCAST SAVE  -----" << endl;
                    cout << endl;
                    cout << "Press enter to RETURN to the MENU " << endl;
                    getchar();
                    break;
                }

                play.displayPlayList(SoP);

                cout << "Press enter to RETURN to the MENU " << endl;
                getchar();
                break;

            }
            }while(optionP!=4);
        break;
   }
   break;

   case 7: // Close APP
        cout << "Thanks. APP closed " << endl;
        cout << "Savind data..." << endl;
        break;


    }
    }while(option != 7 );

    // At this point the program reads the information created ones the app is closed

    if(OutArtist.is_open()){
        for(Artist* Ar : g->getArtistList()){
            g->storeTreeStructureArtist(Ar,OutArtist, Con);
        }
    }else cout << "Not working. " << endl;

    if(OutCreator.is_open()){
        for(Creator* Cr : g->getCreatorList()){
            g->storeTreeStructureCreator(Cr,OutCreator);
        }
    }else cout << "Not working. " << endl;

    if(OutPlayListSong.is_open()){
            play.storePlayListSongs(OutPlayListSong);

    }else cout << "Not working. " << endl;

    if(OutPlayListPodcast.is_open()){
            play.storePlayListPodcat(OutPlayListPodcast);

    }else cout << "Not working. " << endl;


    OutCreator.close();
    OutArtist.close();
    OutPlayListSong.close();


}

string APP_menu::another(string & answer, string a)
{

    cout << "**********************" << endl;
    cout << "Another " << a << " ?(s/n) " << endl;
    cout << "**********************" << endl;

    return answer=selection<string>();
}

  //Functions to create objects

Song* APP_menu::createSong(PlayList& P)
{
    Song* s=new Song();
    cout << "-------------------------------" << endl;
    cout << "Song information"<< endl;
    cout << "-------------------------------" << endl;
    s=s->createSong();
    P.addSongX(s);

    return s;
}

Podcast* APP_menu::createPodcast(PlayList& P)
{
    Podcast* p=new Podcast();
    cout << "-------------------------------" << endl;
    cout << "Podcast information"<< endl;
    cout << "-------------------------------" << endl;
    p=p->createPodcast();
    P.addPodcastX(p);

    return p;
}

Album* APP_menu::createAlbum(PlayList& P)
{
    Album* A = new Album();
    cout << "-------------------------------" << endl;
    cout << "Album information " << endl;
    cout << "-------------------------------" << endl;
    A = A->createAlbum();

    Song* s = new Song();
    string answer;

    cout << "-------------------------------" << endl;
    cout << "Song information,press enter to create the song list" << endl;
    cout << "-------------------------------" << endl;

    do {
        s = s->createSong();
        A->addSong(s);
        P.addSongX(s);
        another(answer, "Song");
    } while (answer == "s");

    return A;
}

Collection* APP_menu::createCollection(PlayList& P)
{
    Collection* C=new Collection();
    cout << "-------------------------------" << endl;
    cout << "Collection information" << endl;
    cout << "-------------------------------" << endl;
    C=C->createCollection();

    Podcast* p=new Podcast();
    string answer;
    cout << "-------------------------------" << endl;
    cout << "Podcast information,press enter to create the podcast list" << endl;
    cout << "-------------------------------" << endl;

    do{
    p=p->createPodcast();
    C->addPodcast(p);
    P.addPodcastX(p);
    another(answer, "Episode");
    }while (answer=="s");

    return C;
}

Artist* APP_menu::createArtist(PlayList& P)
{
    Artist* Ar=new Artist();
    Album* A=new Album();
    Song* s=new Song();

    cout << "-------------------------------" << endl;
    cout << "ARTIST INFORMATION" << endl;
    cout << "-------------------------------" << endl;

    Ar=Ar->createArtist();

    string answer1,answer2;
    int number=1;

    do{
      cout << "-------------------------------" << endl;
      cout << "ALBUM NUMBER " << number << endl;
      cout << "-------------------------------" << endl;
      ++number;
      A=A->createAlbum();
      Ar->addAlbum(A);
      cout << "-------------------------------" << endl;
      cout << "SONG LIST INFORMATION" << endl;
      cout << "-------------------------------" << endl;
      cout << endl;

      do{
      s=s->createSong();
      A->addSong(s);
      P.addSongX(s);
      another(answer2, "Song");

      }while (answer2=="s");

        another(answer1, "Album");

      }while (answer1=="s");

      cout << endl;
      cout << "-----  ARTIST CREATED CORRECTLY  -----" << endl;
      cout << endl;

      return Ar;
}

Creator* APP_menu::createCreator(PlayList& P)
{
    Creator* Cr=new Creator();
    Collection* C=new Collection();
    Podcast* p=new Podcast();

    cout << "-------------------------------" << endl;
    cout << "CREATOR INFORMATION" << endl;
    cout << "-------------------------------" << endl;

    Cr=Cr->createCreator();

    string answer1,answer2;
    int number=1;

    do{
      cout << "-------------------------------" << endl;
      cout << "COLLECTION NUMBER " << number << endl;
      cout << "-------------------------------" << endl;
      ++number;
      C=C->createCollection();
      Cr->addCollection(C);
      cout << "-------------------------------" << endl;
      cout << "PODCAST LIST INFORMATION" << endl;
      cout << "-------------------------------" << endl;

      do{
      p=p->createPodcast();
      C->addPodcast(p);
      P.addPodcastX(p);
      another(answer2, "Podcast");

      }while (answer2=="s");

      another(answer1, "Collection");

      }while (answer1=="s");

      cout << endl;
      cout << "-----  CREATOR CREATED CORRECTLY  -----" << endl;
      cout << endl;

    return Cr;
}

void APP_menu::readArtist(General* g)
{

    ifstream InArtist("ArtistTreeStructure.txt");


  //Read the file

  cout << "Reading Artist tree structure... " << endl;

      string artist_text((istreambuf_iterator<char>(InArtist)), istreambuf_iterator<char>());


      if (artist_text.size() < 1) cout << "There is nothing stored in the file." << endl; //The file does not have info
      else {

          bool anotherArtist=true;
          bool anotherAlbum=true;
          bool anotherSong=true;
          bool anotherConcert=true;
          do{
          //Name
          artist_text.erase(0, artist_text.find("Artist"));//In this part we are errasing the text while we store the important data in variables
          artist_text.erase(0, 13);
          size_t position=artist_text.find("Birth");
          string nameAr=artist_text.substr(0, position-1);

          //Birth
          artist_text.erase(0, artist_text.find("Birth")+7);
          position=artist_text.find("Nationality");
          string birthAr=artist_text.substr(0, position-1);
          //Nationality
          artist_text.erase(0, artist_text.find("Nationality")+13);
          position=artist_text.find("*");
          string nationalityAr=artist_text.substr(0, position-1);

          Ar=new Artist(nameAr,nationalityAr,birthAr);
          g->addArtist(Ar);

          //Concerts
          do{
              anotherConcert=true;

          if (artist_text.find("Concert")<artist_text.find("Album")){

              //Concert place
              artist_text.erase(0, artist_text.find("Concert")-1);
              artist_text.erase(0, artist_text.find("place")+7);
              position=artist_text.find("Concert");
              string placeCon=artist_text.substr(0, position-1);
              //Concert Date
              artist_text.erase(0, artist_text.find("date")+6);
              position=artist_text.find("\n");
              string dateCon=artist_text.substr(0, position-1);
              Con=new Concerts(placeCon, dateCon);
              Ar->addConcert(Con);
          }
          else anotherConcert=false;
          }while(anotherConcert==true);

          //Albums
          anotherAlbum=true;
          do{

          //Name
          artist_text.erase(0, artist_text.find("Album")-1);
          artist_text.erase(0, artist_text.find("Name")+6);
          position=artist_text.find("Rate");
          string nameA=artist_text.substr(0, position-1);
          //Rate
          artist_text.erase(0, artist_text.find("Rate")+6);
          position=artist_text.find("Year");
          string rateA=artist_text.substr(0, position-1);
          //Year
          artist_text.erase(0, artist_text.find("Year")+6);
          position=artist_text.find("Total duration");
          int yearA = std::stod(artist_text.substr(0, position-1));
          //Total duration
          artist_text.erase(0, artist_text.find("duration")+10);
          position=artist_text.find("*");
          double TdurationA =stod(artist_text.substr(0, position-1));

          A=new Album(nameA,rateA,yearA,TdurationA);
          Ar->addAlbum(A);

          //Song

          anotherSong=true;
          do{
          //Name
          artist_text.erase(0, artist_text.find("Song")-1);
          artist_text.erase(0, artist_text.find("Name")+6);
          position=artist_text.find("Duration");
          string nameS=artist_text.substr(0, position-1);
          //Duration
          artist_text.erase(0, artist_text.find("Duration")+10);
          position=artist_text.find("Genre");
          double durationS = std::stod(artist_text.substr(0, position-1));
          //Genre
          artist_text.erase(0, artist_text.find("Genre")+7);
          position=artist_text.find("Lyrics");
          string genreS=artist_text.substr(0, position-1);
          //Lyrics
          artist_text.erase(0, artist_text.find("Lyrics")+8);
          position=artist_text.find("\n");
          string lyricsS=artist_text.substr(0, position);

          s=new Song(nameS,durationS,genreS,lyricsS);
          A->addSong(s);
          play.addSongX(s);


          if (artist_text.find("Song")>7) anotherSong=false;
          }while(anotherSong);
          if (artist_text.find("Album")>50) anotherAlbum=false;
          }while(anotherAlbum);
          if (artist_text.find("Artist") == string::npos) anotherArtist=false;
          }while(anotherArtist);
      }

      InArtist.close();

}

void APP_menu::readCreator(General *g)
{
    ifstream InCreator("CreatorTreeStructure.txt");


      //Read the file

      cout << "Reading Creator tree structure... " << endl;

          string creator_text((istreambuf_iterator<char>(InCreator)), istreambuf_iterator<char>());


          if (creator_text.size() < 1) cout << "There is nothing stored in the file." << endl; //The file does not have info
          else {

              bool anotherCreator=true;
              bool anotherCollection=true;
              bool anotherPodcast=true;
              do{
              //Name
              creator_text.erase(0, creator_text.find("Creator"));//In this part we are errasing the text while we store the important data in variables
              creator_text.erase(0, 14);
              size_t position=creator_text.find("Birth");
              string nameAr=creator_text.substr(0, position-1);
              //Birth
              creator_text.erase(0, creator_text.find("Birth")+7);
              position=creator_text.find("Nationality");
              string birthAr=creator_text.substr(0, position-1);
              //Nationality
              creator_text.erase(0, creator_text.find("Nationality")+13);
              position=creator_text.find("*");
              string nationalityAr=creator_text.substr(0, position-1);

              Cr=new Creator(nameAr,nationalityAr,birthAr);
              g->addCreator(Cr);

              //Albums
              anotherCollection=true;
              do{

              //Name
              creator_text.erase(0, creator_text.find("Collection")-1); //We leave collection to check if we have another one
              creator_text.erase(0, creator_text.find("Name")+6);
              position=creator_text.find("Rate");
              string nameA=creator_text.substr(0, position-1);
              //Rate
              creator_text.erase(0, creator_text.find("Rate")+6);
              position=creator_text.find("Year");
              string rateA=creator_text.substr(0, position-1);
              //Year
              creator_text.erase(0, creator_text.find("Year")+6);
              position=creator_text.find("Theme");
              int yearA = std::stod(creator_text.substr(0, position-1));
              //Theme
              creator_text.erase(0, creator_text.find("Theme")+7);
              position=creator_text.find("Summary");
              string themeA=creator_text.substr(0, position-1);
              //Summary
              creator_text.erase(0, creator_text.find("Summary")+9);
              position=creator_text.find("*");
              string summaryA=creator_text.substr(0, position-1);

              C=new Collection(nameA,rateA,yearA,themeA, summaryA);
              Cr->addCollection(C);

              //Song

              anotherPodcast=true;
              do{
              //Name
              creator_text.erase(0, creator_text.find("Episode")-1);
              creator_text.erase(0, creator_text.find("Name")+6);
              position=creator_text.find("Duration");
              string nameS=creator_text.substr(0, position-1);
              //Duration
              creator_text.erase(0, creator_text.find("Duration")+10);
              position=creator_text.find("Description");
              double durationS = std::stod(creator_text.substr(0, position-1));
              //Description
              creator_text.erase(0, creator_text.find("Description")+13);
              position=creator_text.find("Publication");
              string descriptionS=creator_text.substr(0, position-1);
              //Publication Date
              creator_text.erase(0, creator_text.find("date")+6);
              position=creator_text.find("\n");
              string PdateS=creator_text.substr(0, position);

              p=new Podcast(nameS,durationS,descriptionS,PdateS);
              C->addPodcast(p);
              play.addPodcastX(p);


              if (creator_text.find("Episode")>7) anotherPodcast=false;
              }while(anotherPodcast);
              if (creator_text.find("Collection")>50) anotherCollection=false;
              }while(anotherCollection);
              if (creator_text.find("Creator") == string::npos) anotherCreator=false;
              }while(anotherCreator);
          }
          InCreator.close();

}

void APP_menu::readPlayListSong(PlayList)
{
    ifstream PlayList("PlayListSong.txt");

    cout << "Reading play list..." << endl;

    string PlayList_text((istreambuf_iterator<char>(PlayList)), istreambuf_iterator<char>());
    if (PlayList_text.size() < 1) cout << "There is nothing stored in the file." << endl;
    else {

        bool anotherSong = true;
        anotherSong=true;
        do{
        //Name
        PlayList_text.erase(0, PlayList_text.find("Song")-1);
        PlayList_text.erase(0, PlayList_text.find("Name")+6);
        size_t position=PlayList_text.find("Duration");
        string nameS=PlayList_text.substr(0, position-1);
        //Duration
        PlayList_text.erase(0, PlayList_text.find("Duration")+10);
        position=PlayList_text.find("Genre");
        double durationS = std::stod(PlayList_text.substr(0, position-1));
        //Genre
        PlayList_text.erase(0, PlayList_text.find("Genre")+7);
        position=PlayList_text.find("Lyrics");
        string genreS=PlayList_text.substr(0, position-1);
        //Lyrics
        PlayList_text.erase(0, PlayList_text.find("Lyrics")+8);
        position=PlayList_text.find("\n");
        string lyricsS=PlayList_text.substr(0, position);

        s=new Song(nameS,durationS,genreS,lyricsS);
        play.addPlayListSong(s);


        if (PlayList_text.find("Song")>7) anotherSong=false;
        }while(anotherSong);
    }
}

void APP_menu::readPlayListPodcast(PlayList)
{
    ifstream PlayList("PlayListPodcast.txt");

    cout << "Reading play list..." << endl;

    string PlayListPodcast_text((istreambuf_iterator<char>(PlayList)), istreambuf_iterator<char>());
    if (PlayListPodcast_text.size() < 1) cout << "There is nothing stored in the file." << endl;
    else {

        bool anotherPodcast = true;
        anotherPodcast=true;

        do{
            //Name
            PlayListPodcast_text.erase(0, PlayListPodcast_text.find("Episode")-1);
            PlayListPodcast_text.erase(0, PlayListPodcast_text.find("Name")+6);
            size_t position=PlayListPodcast_text.find("Duration");
            string nameS=PlayListPodcast_text.substr(0, position-1);
            //Duration
            PlayListPodcast_text.erase(0, PlayListPodcast_text.find("Duration")+10);
            position=PlayListPodcast_text.find("Description");
            double durationS = std::stod(PlayListPodcast_text.substr(0, position-1));
            //Description
            PlayListPodcast_text.erase(0, PlayListPodcast_text.find("Description")+13);
            position=PlayListPodcast_text.find("Publication");
            string descriptionS=PlayListPodcast_text.substr(0, position-1);
            //Publication Date
            PlayListPodcast_text.erase(0, PlayListPodcast_text.find("date")+6);
            position=PlayListPodcast_text.find("\n");
            string PdateS=PlayListPodcast_text.substr(0, position);

            p=new Podcast(nameS,durationS,descriptionS,PdateS);
            play.addPlaylistPodcast(p);


            if (PlayListPodcast_text.find("Episode")>7) anotherPodcast=false;
        }while(anotherPodcast);
    }
}

int APP_menu::getsizeA()
{
    return _sizeA;
}

void APP_menu::setSizeA(General& g)
{
    int sizeA;

    sizeA = g.getArtistList().size();

    _sizeA = sizeA;
}

int APP_menu::getsizeC()
{
    return _sizeC;
}

void APP_menu::setSizeC(General& g){

    int sizeC;
    sizeC = g.getCreatorList().size();
    _sizeC = sizeC;
}




