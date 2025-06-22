#include <iostream>
#include <iomanip>
#include "Director.h"
#include <fstream>

using namespace std;



void Director::setExpYears(int e){
    experienceYears = e;
}

void Director::setNationality(string n){
    nationality = n;
}

int Director::getExpYears()const{
    return experienceYears;
}

string Director::getNationality()const{
    return nationality;
}

Director::Director(string fn, string ln, int expY, string n): Name(fn,ln){
    setExpYears(expY);
    setNationality(n);
}

Director::Director(const Director &d):Name(d.getFN(), d.getLN()){
    setExpYears(d.getExpYears());
    setNationality(d.getNationality());
}

void Director::setDirector(string fn, string ln, int expY, string n){
    setName(fn, ln);
    setNationality(n);
    setExpYears(expY);
}

Director* Director::getDirector(){
    return this;
}

Director::~Director(){}

void Director::displayDirector()const{
    cout << "-------Director Details-------" << endl;
    cout << setw(15) << left << "Name" << ": " << getName() << endl;
    cout << setw(15) << left  << "Exprience " << ": " << getExpYears() << endl;
    cout << setw(15) << left  << "Nationality" << ": " << getNationality() << endl;
}

ostream & operator << (ostream& out, const Director & d){
    out << "-------Director Details-------" << endl;
    out << setw(15) << left << "Name" << ": " << d.getName() << endl;
    out << setw(15) << left  << "Exprience " << ": " << d.getExpYears() << endl;
    out << setw(15) << left  << "Nationality" << ": " << d.getNationality() << endl;
    return out;
}