#include<iostream>
#include <iomanip>
#include "Name.h"

using namespace std;

void Name::setFN(string fn){
    FirstName = fn;
}

void Name::setLN(string ln){
    LastName = ln;
}

string Name::getName()const{
    return FirstName + " " + LastName;
}

string Name::getFN()const{
    return FirstName;
}

string Name::getLN()const{
    return LastName;
}

Name::Name(const Name &n){
    setFN(n.getFN());
    setLN(n.getLN());   
}

Name::Name(string fn, string ln){
    setFN(fn);
    setLN(ln);
}

Name::~Name(){}

void Name::setName(string fn, string ln){
    setFN(fn);
    setLN(ln);
}

