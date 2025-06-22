#ifndef Scifi_H_INCLUDED
#define Scifi_H_INCLUDED

#include <iostream>
#include <fstream>
#include "MovieBaseClass.h"
#include "Date.h"

using namespace std;

class scifi:public Movie{
private:
    int techLevel;
    bool hasAliens;
    int futureYear;
    string genre = "Scifi";

protected:
    void settechLevel(int);
    void sethasAliens(bool);
    void setfutureYear(int);

    int gettechLevel()const;
    int getfutureYear()const;
    bool gethasAliens()const;

    void displayDetails(ostream&)const override;
    
public:
    
    scifi(string = "", int = 0, int = 0,int = 0,int = 0,int = 0,int = 0, bool = false, int = 0);
    ~scifi();
    scifi(const scifi &);
    
    //void displayDetails()const override;
    void toggleAlienInvasion();
    void setmovie(string, int, int, int ,int, int, bool, int);

    int calculateScore()const override;
    
    string getgenre()const override;
    string simulateFutureScenario()const;
    string showTechAnalysis()const;
    
    
    friend ostream& operator << (ostream &, const scifi&);
};

#endif