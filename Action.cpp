#include <iostream>
#include <fstream>
#include "Action.h"
#include <iomanip>

using namespace std;

void Action::setviolenceLevel(char v){
    violenceLevel = v;

}

void Action::setnoOfFightScenes(int f){
    noOfFightScenes = f;
}

void Action::sethasStunts(bool a){
    hasStunts = a;
}

char Action::getviolenceLevel()const{
    return violenceLevel;
}

int Action::getnoOfFightScenes()const{
    return noOfFightScenes;
}

bool Action::gethasStunts()const{
    return hasStunts;
}

Action::Action(string title, int rating, int day, int month, int year,int director, char violence, bool stunt, int fightscene): Movie(title, rating, day, month, year, director){
    setviolenceLevel(violence);
    sethasStunts(stunt);
    setnoOfFightScenes(fightscene);
}

Action::Action(const Action &s):Movie(s){
    setviolenceLevel(s.getviolenceLevel());
    sethasStunts(s.gethasStunts());
    setnoOfFightScenes(s.getnoOfFightScenes());
}


Action::~Action(){}

string Action::getgenre()const{
    return genre;
}

/*void Action::displayDetails()const{
    Movie::displayDetails();
    cout << setw(14) << left << "Genre" << ": " << getgenre() << endl;
    cout << setw(14) << left << "Violence Level" << ": " << getviolenceLevel() << endl;
    cout << setw(14) << left << "Stunts" << ": " << (gethasStunts()? "Yes": "No") << endl;
    cout << setw(14) << left << "Fight Scenes" << ": " << getnoOfFightScenes() << endl;
}*/

void Action::displayDetails(ostream &out)const{
    Movie::displayDetails(out);
    out << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    out << setw(15) << left << "Violence Level" << ": " << getviolenceLevel() << endl;
    out << setw(15) << left << "Stunts" << ": " << (gethasStunts()? "Yes": "No") << endl;
    out << setw(15) << left << "Fight Scenes" << ": " << getnoOfFightScenes() << endl;
}

int Action::calculateScore()const{
    return (Movie::calculateScore() * ((getnoOfFightScenes() > 7? 2:getnoOfFightScenes())/countExplosions()))%10;
}

string Action::assessCensorship()const{
    if(getviolenceLevel() == 'D')
        return "Domestic Violence";
    else if(getviolenceLevel() == 'M')
        return "Mafia";
    return "Ultra Cool";
}

string Action::stuntCoordinatorReport()const{
    if(gethasStunts() && (getnoOfFightScenes() >= 5 && getnoOfFightScenes() <= 10))
        return "Cool";
    return "Might be boring";
}

int Action::countExplosions()const{
    if(getnoOfFightScenes() > 5)
        return 8;
    return 2;
}

void Action::setmovie(string title, int rating, int day, int month, int year, char violenceLevel, bool stunts, int fightscene){
        Movie::setmovie(title,rating,day,month,year);
        setviolenceLevel(violenceLevel);
        sethasStunts(stunts);
        setnoOfFightScenes(fightscene);
    }

ostream & operator <<(ostream & out, const Action& a){
    a.displayDetails(out);
    return out;
}