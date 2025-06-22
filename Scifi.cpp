#include <iostream>
#include "Scifi.h"
#include <fstream>
#include <iomanip>

using namespace std;

void scifi::settechLevel(int t){
        techLevel = t;
}

void scifi::setfutureYear(int f){
    futureYear = f;
}

void scifi::sethasAliens(bool a){
    hasAliens = a;
}

int scifi::gettechLevel()const{
    return techLevel;
}

int scifi::getfutureYear()const{
    return futureYear;
}

bool scifi::gethasAliens()const{
    return hasAliens;
}

scifi::scifi(string title, int rating, int day, int month, int year,int director, int tech, bool aliens, int futureY): Movie(title, rating, day, month, year, director){
    settechLevel(tech);
    sethasAliens(aliens);
    setfutureYear(futureY);
}

scifi::scifi(const scifi &s):Movie(s){
    settechLevel(s.gettechLevel());
    sethasAliens(s.gethasAliens());
    setfutureYear(s.getfutureYear());
}


scifi::~scifi(){}

string scifi::getgenre()const{
    return genre;
}

/*void scifi::displayDetails()const{
    Movie::displayDetails();
    cout << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(15) << left << "Tech Level" << ": " << gettechLevel() << endl;
    cout << setw(15) << left << "Aliens" << ": " << (gethasAliens()? "Yes": "No") << endl;
    cout << setw(15) << left << "Future Year" << ": " << getfutureYear() << endl;
}*/


void scifi::displayDetails(ostream &out)const{
    Movie::displayDetails(out);
    out << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    out << setw(15) << left << "Tech Level" << ": " << gettechLevel() << endl;
    out << setw(15) << left << "Aliens" << ": " << (gethasAliens()? "Yes": "No") << endl;
    out << setw(15) << left << "Future Year" << ": " << getfutureYear() << endl;
}

int scifi::calculateScore()const{
    return (Movie::calculateScore() * gettechLevel())%10;
}

string scifi::showTechAnalysis()const{
    if(calculateScore() > 7)
        return "Awesome";
    return "Not so Awesome";
}

string scifi::simulateFutureScenario()const{
    if((calculateScore() > 7) && hasAliens)
        return "Future is Bright";
    return "Future is not Bright";
}

void scifi::toggleAlienInvasion(){
    hasAliens = !hasAliens;
}

void scifi::setmovie(string title, int rating, int day, int month, int year, int techl, bool Aliens, int futureY){
        Movie::setmovie(title,rating,day,month,year);
        settechLevel(techl);
        sethasAliens(Aliens);
        setfutureYear(futureY);
    }

    ostream & operator <<(ostream & out, const scifi& a){
        a.displayDetails(out);
        return out;
}