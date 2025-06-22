#include <iostream>
#include "SA.h"
#include "MovieBaseClass.h"
#include <fstream>
#include <conio.h>
#include <string>
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include "global.h"

using namespace std;



void InputMoviesFromFile(){

    fstream file("movies.txt", ios::in);

    if(!file.is_open()){
        cout << "Error could not access Movies.txt" << endl;
    }
    else{
        string line;
        file.seekg(0, ios::beg);
        for(int j = 0; j < MaxNumberOfMovies; j++){

            Variables v;
            
            for(int i = 0; i <= 8; i ++){
                getline(file,line);
                try{
                    line = line.substr(18); 

                    switch(i){
                        case 1:    
                            v.title = line;
                            break;
                        case 2:    
                            v.rating = stoi(line);
                            break;
                        case 3:    
                            v.releaseDate = line.substr(0,2);
                            v.day = stoi(v.releaseDate);
                            v.releaseDate = line.substr(3,2);
                            v.month = stoi(v.releaseDate);
                            v.releaseDate = line.substr(6,4);
                            v.year = stoi(v.releaseDate);
                            break;
                        case 4:    
                            v.genre = line;
                            if(v.genre == "Scifi"){
                                v.genrePointer = 1;
                            }
                            else if(v.genre == "Action"){
                                v.genrePointer = 2;
                            }
                            else
                                v.genrePointer = 3;
                            break;
                        case 5:
                            if(v.genrePointer == 1)    
                                v.techlvl = stoi(line);
                            else if(v.genrePointer == 3)    
                                v.AnimeSyle = stoi(line);
                            else if(v.genrePointer == 2)    
                                v.VLvl = line[0];
                            break;
                        case 6:
                            if (v.genrePointer == 1) // Scifi
                                v.aliens = (line == "Yes" || line == "yes");
                            else if (v.genrePointer == 2) // Action
                                v.Stunts = (line == "Yes" || line == "yes");
                            else if (v.genrePointer == 3) // Animation
                                v.Musical = (line == "Yes" || line == "yes");
                            break;
                        case 7:
                            if (v.genrePointer == 1) // Scifi
                                v.FutureY = stoi(line);
                            else if (v.genrePointer == 2) // Action
                                v.NoOfFights = stoi(line);
                            else if (v.genrePointer == 3) // Animation
                                v.ageG = stoi(line);
                            break;
                        case 8:
                            if(line == "Steven Spielberg")
                                v.directorChoice = 1;
                            else if(line == "Martin Scorsese")
                                v.directorChoice = 2;
                            else if(line == "Clint Eastwood")
                                v.directorChoice = 3;
                            else
                                v.directorChoice = 1;
                            break;
                        default:
                            break;
                        }
                }
                catch(const exception& e){
                    continue;
                }
            }

            if(v.genrePointer == 1){
                mpointer[CurrentNumberOfMovies++] = new scifi(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.techlvl, v.aliens,v.FutureY);
            }
            else if(v.genrePointer == 2){
                mpointer[CurrentNumberOfMovies++] = new Action(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.VLvl, v.Stunts,v.NoOfFights);
                
            }
            else if(v.genrePointer == 3){
                mpointer[CurrentNumberOfMovies++] = new Animation(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.AnimeSyle,v.Musical,v.ageG);
                
            }
            else
                continue;
        }
    }
    file.close();
}

void InputDirectorsFromFile(){
    fstream file("directors.txt", ios::in);

    if(!file.is_open()){
        cout << "Error could not access director.txt" << endl;
    }
    else{
        string fn,ln, nationality;
        int expY;
        string line;
        file.seekg(0,ios::beg);
        for(int i = 0; i < 3; i++){
            for(int i = 0; i < 5; i++){
                getline(file, line);
                try{
                    line = line.substr(18);
                    switch(i){
                        case 1:
                            fn = line;
                            break;
                        case 2:    
                            ln = line;
                            break;
                        case 3:    
                            nationality = line;
                            break;
                        case 4:    
                            expY = stoi(line);
                            break;
                    }
                }
                catch(const exception&){
                    continue;
                }
            }
            d[i] = new Director(fn, ln, expY, nationality);
        }
    }
    file.close();
}

void DeleteAllPointers(){
    for(int i = 0; i < MaxNumberOfMovies; i++){
            delete mpointer[i];
        }
    for(int i = 0; i < 3; i++){
        delete d[i];
    }
}

bool AddNewMovie(){

    if(CurrentNumberOfMovies == MaxNumberOfMovies){
        return false;
    }
    
    Variables v;

    system("cls");

    cout << "--------------ADDING NEW MOVIE--------------" << endl;

    cout << "Enter" << endl;
    cout << "Movie Title: ";

    cin.ignore();
    getline(cin, v.title);

    cout << "Rating: ";

    cin >> v.rating;

    cout << "Release Date in Numeric for dd/mm/yyyy " << endl;
    cout << "Day: " << endl;
    cin >> v.day;

    cout << "Month: " << endl;
    cin >> v.month;

    cout << "Year: " << endl;
    cin >> v.year;    
    
    cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
    cin >> v.directorChoice;
    if(v.directorChoice < 1 || v.directorChoice > 3 || d[v.directorChoice-1] == nullptr){
        v.directorChoice = 0; 
    }

    cout << "Select Genre of the Movie you would like to add" << endl;
    cout << "1. Science Fiction" << endl
         << "2. Action" << endl
         << "3. Animation" << endl;
    
    int choice;
    cin >> choice;

    if(choice == 1){
        cout << "Select Tech Level" << endl << "1. Tech Level 1" << endl << "2. Tech Level 2" << endl << "3. Tech Level 3" << endl;
        cin >> v.techlvl;

        cout << "Does it Have Aliens (Y/N)";
        char ch = getche();
        cin.ignore();
        if(ch == 'Y' || ch == 'y')
            v.aliens = true;
        
        cout << "Future Year: ";
        cin >> v.FutureY;

        mpointer[CurrentNumberOfMovies++] = new scifi(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.techlvl, v.aliens,v.FutureY);
    }
    else if(choice == 2){
        cout << "Select Violence Level" << endl;
        cout << "1. Domestic Violence" << endl << "2. Mafia Level" << endl << "3. Ultra Cool" << endl;
        int violenceChoice;
        cin >> violenceChoice;

        switch(violenceChoice) {
            case 1: 
                v.VLvl = 'D'; 
                break;
            case 2: 
                v.VLvl = 'M'; 
                break;
            case 3: 
                v.VLvl = 'U'; 
                break;
            default: 
                v.VLvl = ' '; 
                break;
        }

        cout << "Does it Have Stunts (Y/N)";
        char ch = getche();
        cin.ignore();

        if(ch == 'Y' || ch == 'y')
            v.Stunts = true;
        
        cout << "Number of Fight Scenes: ";
        cin >> v.NoOfFights;

        mpointer[CurrentNumberOfMovies++] = new Action(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.VLvl, v.Stunts,v.NoOfFights);    }
    else{

        cout << "Animation Style" << endl << "1. Animation Style 1" << endl << "2. Animation Style 2" << endl << "3. Animation Style 3" << endl;
        cin >> v.AnimeSyle;

        cout << "Is it a Musical (Y/N)";
        char ch = getche();
        cin.ignore();

        if(ch == 'Y' || ch == 'y')
            v.Musical = true;
        
        cout << "Select Age Group "<< endl << "1. 5 Years" << endl << "2. 7 Years" << endl << "3. 18 Years" << endl;
        int ch1;
        cin >> ch1;
        if(ch1 == 1)
            v.ageG = 5;
        else if(ch1 == 2)
            v.ageG = 7; 
        else if(ch1 == 3)
            v.ageG = 18;
        else
            v.ageG = 404;
        mpointer[CurrentNumberOfMovies++] = new Animation(v.title, v.rating, v.day,v.month,v.year, v.directorChoice, v.AnimeSyle,v.Musical,v.ageG);
    }

    fstream file("movies.txt" , ios::app);
        file << endl << "-------Movie Details-------" << endl;
        file << "Title           : " << v.title << endl;
        file << "Rating          : " << v.rating << endl;
        file << "Release Date    : " << v.day << "/" << v.month << "/" << v.year << endl;

    if(choice == 1){
        file << "Genre           : " << "Scifi" << endl;
        file << "Tech Level      : " << v.techlvl << endl;
        file << "Aliens          : " << (v.aliens? "Yes":"No") << endl;
        file << "Future Year     : " << v.FutureY << endl;
    }
    else if(choice == 2){
        file << "Genre           : " << "Action" << endl;
        file << "Violence Level  : " << v.VLvl << endl;
        file << "Stunts          : " << (v.Stunts? "Yes":"No") << endl;
        file << "Fight Scenes    : " << v.NoOfFights << endl;
    }
    else if(choice == 3){
        file << "Genre           : " << "Animation" << endl;
        file << "Animation Style : " << v.AnimeSyle << endl;
        file << "Musical         : " << (v.Musical? "Yes": "No") << endl;
        file << "Age Group       : " << v.ageG << endl;
    }
    file.close();

    return true;
}

void writeMoviesToNewFile(){
        fstream file("movies1.txt", ios::out | ios::trunc);
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        file << *mpointer[i];
    }
        file.close();
}

bool AddNewDirector(){
    // Check if we have space for more directors
    int currentDirectorCount = 0;
    for(int i = 0; i < 3; i++){
        if(d[i] != nullptr) currentDirectorCount++;
    }
    
    if(currentDirectorCount >= 3){
        cout << "Maximum number of directors (3) already reached." << endl;
        return false;
    }
    
    string firstName, lastName, nationality;
    int experienceYears;
    
    system("cls");
    cout << "--------------ADDING NEW DIRECTOR--------------" << endl;
    
    cout << "Enter Director Details:" << endl;
    
    cout << "First Name: ";
    cin.ignore();
    getline(cin, firstName);
    
    cout << "Last Name: ";
    getline(cin, lastName);
    
    cout << "Nationality: ";
    getline(cin, nationality);
    
    cout << "Experience Years: ";
    cin >> experienceYears;
    
    int slot = 0;
    for(int i = 0; i < 3; i++){
        if(d[i] == nullptr){
            slot = i;
            break;
        }
    }
    d[slot] = new Director(firstName, lastName, experienceYears, nationality);


    fstream file("directors.txt", ios::app);
    if(file.is_open()){
        file << endl << "-----------Director " << (slot + 1) << " Details-----------" << endl;
        file << "First Name      : " << firstName << endl;
        file << "Last Name       : " << lastName << endl;
        file << "Nationality     : " << nationality << endl;
        file << "Experience Years: " << experienceYears << " years" << endl;
        file.close();
    }
    
    cout << "Director " << firstName << " " << lastName << " added successfully!" << endl;
    return true;
}

void DisplayAllMovies(){
    system("cls");
    cout << "--------------ALL Movies--------------" << endl;
    
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            cout << "\nMovie " << (i + 1) << ":" << endl;
            cout << *mpointer[i] << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayAllDirectors(){
    system("cls");
    cout << "--------------ALL Directors--------------" << endl;
    
    bool found = false;
    for(int i = 0; i < 3; i++){
        if(d[i] != nullptr){
            cout << "Director " << (i + 1) << ":" << endl;
            cout << *d[i] << endl;
            found = true;
        }
    }
    
    if(!found){
        cout << "No Directors found in the system." << endl;
    }
}

void DisplayAllMoviesByGenre(string genre){
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            if(mpointer[i]->getgenre() == genre){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayAllMoviesByRating(int rating){
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            if(mpointer[i]->calculateScore() == rating){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayByDirector(string director){
    director = StringToLowercase(director);
    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i] != nullptr){
            string MDirector = StringToLowercase(mpointer[i]->getDirectorName());
            if(MDirector == director){
                cout << "\nMovie " << (i + 1) << ":" << endl;
                cout << *mpointer[i] << endl;
                found = true;
            }
        }
    }
    if(!found){
        cout << "No Movies found in the system." << endl;
    }
}

void DisplayByYear(int year){
    int size = CurrentNumberOfMovies;
    for(int i = 0; i < size; i++){
        int MovieYear;
        string releaseDate = mpointer[i]->displayReleaseDate();
        int last_slash = releaseDate.find_last_of('/');
        releaseDate = releaseDate.substr(last_slash + 1);
        MovieYear = stoi(releaseDate);
        if(MovieYear == year)
            cout << *mpointer[i];
    }
}

void DisplayByTitle(string title){
    int Index = SearchTitle(title);
    if(Index != 3309)
    cout << *mpointer[Index];
    else
    cout << "No Moive Found" << endl;
}

int SearchTitle(string title){
        string MovieTitle;
        
        title = StringToLowercase(title);

        for(int i = 0; i < CurrentNumberOfMovies; i++){
            MovieTitle = StringToLowercase(mpointer[i]->getTitle());
            if(MovieTitle == title)
                return i;
        }
        return 3309;
}


void SortMoviesByYear(){
    int size = CurrentNumberOfMovies;
    int MovieYear[size];
    int MovieIndex[size];

    for(int i = 0; i < size; i++){
        string releaseDate = mpointer[i]->displayReleaseDate();
        int last_slash = releaseDate.find_last_of('/');
        releaseDate = releaseDate.substr(last_slash + 1);
        MovieYear[i] = stoi(releaseDate);
        MovieIndex[i] = i;
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(MovieYear[j] > MovieYear[j + 1]){
                swap(MovieYear[j], MovieYear[j + 1]);
                swap(MovieIndex[j], MovieIndex[j + 1]);
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << *mpointer[MovieIndex[i]];
    }
}

void RequestToAssignNewDirector(){

    string title;
    int directorChoice;
    
    cout << "Enter the Title of the movie for which you would like to assign an existing Director to: ";
    
    cin.ignore();
    getline(cin, title);

    cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
    cin >> directorChoice;

    if(directorChoice < 1 || directorChoice > 3 || d[directorChoice - 1] == nullptr || directorChoice == 99){
        directorChoice = 0; 
    }

    if(directorChoice == 99){
        system("cls");
        int dc;
        cout << "Select Director" << endl << "1. Steven Spielberg" << endl << "2. Martin Scorsese" << endl << "3. Clint Eastwood" << endl;
        cin >> dc;


    }
    if(SearchTitle(title)){
        fstream file("UserRequest.txt", ios::app);
        if(file.is_open()){
            file << "User would like to Assign " << d[directorChoice - 1]->getName() << " as Director of " << title << endl;
            cout << "Your Request has been registered\nWaiting for admin" << endl;
        }
        else 
            cout << "Error in registering request" << endl;
    }
    else
        cout << "Movie does not Exist or incorrect title was entered" << endl;
}

string StringToLowercase(string s){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

void DisplayByRating(int rating){
    int MovieIndex[CurrentNumberOfMovies];
    int MovieRating[CurrentNumberOfMovies];
    int tot_M_toSort = 0;

    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i]->getRating() >= rating){
            MovieIndex[tot_M_toSort] = i;
            MovieRating[tot_M_toSort] = mpointer[i]->getRating();
            tot_M_toSort++;
            found = true;
        }
    }
    
    for(int i = 0; i < tot_M_toSort - 1; i++){
        for(int j = 0; j < tot_M_toSort - 1 - i; j++){
            if(MovieRating[j] < MovieRating[j + 1]){
                swap(MovieRating[j] , MovieRating[j + 1]);
                swap(MovieIndex[j] , MovieIndex[j + 1]);
            }
        }
    }
    system("cls");
    for(int i = 0; i < tot_M_toSort; i++){
        cout << *mpointer[MovieIndex[i]];
    }

    if(!found)
        cout << "No Movies Found" << endl;
}

void DisplayByScore(int score){
    int MovieIndex[CurrentNumberOfMovies];
    int MovieRating[CurrentNumberOfMovies];
    int tot_M_toSort = 0;

    bool found = false;
    for(int i = 0; i < CurrentNumberOfMovies; i++){
        if(mpointer[i]->calculateScore() >= score){
            MovieIndex[tot_M_toSort] = i;
            MovieRating[tot_M_toSort] = mpointer[i]->getRating();
            tot_M_toSort++;
            found = true;
        }
    }
    
    for(int i = 0; i < tot_M_toSort - 1; i++){
        for(int j = 0; j < tot_M_toSort - 1 - i; j++){
            if(MovieRating[j] < MovieRating[j + 1]){
                swap(MovieRating[j] , MovieRating[j + 1]);
                swap(MovieIndex[j] , MovieIndex[j + 1]);
            }
        }
    }
    system("cls");
    for(int i = 0; i < tot_M_toSort; i++){
        cout << *mpointer[MovieIndex[i]];
    }

    if(!found)
        cout << "No Movies Found" << endl;
}