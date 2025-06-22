#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED
#include <iostream>

using namespace std;

class Date{
private:
    int day, month;
    int year;

protected:
    void setday(int);
    void setmonth(int);
    void setyear(int);

    int getday()const;
    int getmonth()const;
    int getyear()const;

public:
    Date(int = 0, int = 0, int = 0);
    Date(const Date &);
    ~Date();

    void setDate(int, int, int);
    
    int convertDateToDays()const;
    
    string getDate()const;

    bool isLeapYear(int);
    bool validateDate(int, int, int);

    friend std::ostream & operator<<(std::ostream &, const Date &);
    friend std::istream & operator>>(std::istream &, Date&);

    
};
#endif