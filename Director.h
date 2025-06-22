#ifndef Director_H_INCLUDED
#define Director_H_INCLUDED

#include <iostream>
#include "Name.h"
#include <fstream>

using namespace std;

class Director:public Name{
private:
    int experienceYears;
    string nationality;
protected:
    void setNationality(string);
    void setExpYears(int );

    int getExpYears()const;
    string getNationality()const;
public:
    Director(string = "", string = "", int = 0, string = "");
    Director(const Director &);
    ~Director();

    void setDirector(string, string, int, string);
    void displayDirector()const;

    Director* getDirector();
    
    friend ostream & operator <<(ostream &, const Director&);
};
#endif