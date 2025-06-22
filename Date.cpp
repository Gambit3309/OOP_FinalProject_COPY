#include "Date.h"
#include <iostream>
#include "SA.h"
#include <conio.h>

using namespace std;

void Date::setday(int d){
    day = d;
}

void Date::setmonth(int m){
    month = m;        
}

void Date::setyear(int y){
    year = y;
}

int Date::getday()const{
    return day;
}

int Date::getmonth()const{
    return month;
}

int Date::getyear()const{
    return year;
}

Date::Date(int d, int m, int y){
    setday(d);
    setmonth(m);
    setyear(y);
}

Date::Date(const Date &d){
    setday(d.getday());
    setmonth(d.getmonth());
    setyear(d.getyear());
}

Date::~Date(){}


string Date::getDate()const{
    string date = to_string(getday()) + "/" + to_string(getmonth()) + "/" + to_string(getyear());
    return date;
}

bool Date::isLeapYear(int y){
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        return true;
    return false;
}

ostream & operator<<(ostream &out, const Date &d){
    out << d.getday() << "/" << d.getmonth() << "/" << d.getyear() << endl;
    return out;
}

void Date::setDate(int d, int m, int y){
        setday(d);
        setmonth(m);
        setyear(y);
}

istream & operator>>(istream &in, Date &d){
    int day, month, year;
    cout << "Enter" << endl;
    cout << "Day: ";
    in >> day;
    cout << "Month: ";
    in >> month;
    cout << "Year: ";
    in >> year;
    d.setday(day);
    d.setmonth(month);
    d.setyear(year);
    return in;
}

    int Date::convertDateToDays()const{
        return getday() + (getmonth()*30) + (getyear()*365);
    }

