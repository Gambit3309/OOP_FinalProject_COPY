#ifndef global_H_INCLUDED
#define global_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Director.h"
#include "MovieBaseClass.h"

using namespace std;

extern Movie* mpointer[];
extern Director* d[];
extern int CurrentNumberOfMovies;
extern int MaxNumberOfMovies;
extern int NumberOfMovies;

class Variables{
public:
    string title = "";
    string releaseDate = "";
    string directorName = "";
    string nationality = "";
    string genre = "";

    int experience = 0;
    int rating = 0;
    int techlvl = 0;
    int FutureY = 0;
    int AnimeSyle = 0;
    int ageG = 0;
    int NoOfFights = 0;
    int genrePointer = 0;
    int directorChoice = 0;
    int day, month, year;
    
    bool aliens = false;
    bool Musical = false;
    bool Stunts = false;

    char VLvl = ' ';

    ~Variables();
    
};

#endif