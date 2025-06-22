#ifndef MovieBaseClass_H_INCLUDED
#define MovieBaseClass_H_INCLUDED

#include<iostream>
#include<fstream>
#include "Date.h"
#include "Director.h"

using namespace std;

class Movie{
private:
    string title;
    int director = 0;
    Date releaseDate;
    int rating;

protected:
    void setTitle(string);
    void setRating(int);
    void setDirectorNum(int);
    
    virtual void displayDetails(ostream&)const;
public:

    Movie(string = "", int  = 0, int = 0, int = 0, int = 0, int = 0);
    Movie(const Movie&);
    ~Movie();

    //virtual void displayDetails()const;
    virtual int calculateScore()const;
    virtual void setmovie(string, int, int, int, int);
    virtual string getgenre()const = 0;

    string displayReleaseDate()const;
    string getDirectorName()const;
    string getTitle()const;

    int getRating()const;
    int getDirectorNum()const;

    friend ostream & operator<<(ostream &,const Movie&);
};

#endif