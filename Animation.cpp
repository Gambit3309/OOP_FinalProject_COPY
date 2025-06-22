#include <iostream>
#include "Animation.h"
#include <fstream>
#include <iomanip>

using namespace std;

void Animation::setanimationStyle(int t){
        animationStyle = t;
}

void Animation::setageGroup(int f){
    ageGroup = f;
}

void Animation::setisMusical(bool a){
    isMusical = a;
}

int Animation::getanimationStyle()const{
    return animationStyle;
}

int Animation::getageGroup()const{
    return ageGroup;
}

bool Animation::getisMusical()const{
    return isMusical;
}

Animation::Animation(string title, int rating, int day, int month, int year,int director,int animation, bool musical, int agegroup): Movie(title, rating,day, month, year, director){
    setanimationStyle(animation);
    setisMusical(musical);
    setageGroup(agegroup);
}

Animation::Animation(const Animation &s):Movie(s){
    setanimationStyle(s.getanimationStyle());
    setisMusical(s.getisMusical());
    setageGroup(s.getageGroup());
}


Animation::~Animation(){}

string Animation::getgenre()const{
    return genre;
}

// void Animation::displayDetails()const{
//     Movie::displayDetails();
//     cout << setw(15) << left << "Genre" << ": " << getgenre() << endl;
//     cout << setw(15) << left << "Animation Style" << ": " << getanimationStyle() << endl;
//     cout << setw(15) << left << "Musical" << ": " << (getisMusical()? "Yes": "No") << endl;
//     cout << setw(15) << left << "Age Group" << ": " << getageGroup() << endl;
// }

int Animation::calculateScore()const{
    return (Movie::calculateScore() * (getageGroup() / getanimationStyle()))%10;
}

string Animation::suggestMerchandise()const{
    if(getanimationStyle() > 1)
        return "Cool";
    return "Not Cool";
}

bool Animation::isFamilyFriendly()const{
    if((getageGroup() == 18 && getisMusical()) || ((getageGroup() == 5 || getageGroup() == 7) && !getisMusical()) || getanimationStyle() == 3 )
        return true;
    return false;
}

void Animation::changeAnimationStyle(int newStyle) {
    setanimationStyle(newStyle);
}

void Animation::setmovie(string title, int rating, int day, int month, int year, int animation, bool musical, int agegroup){
        Movie::setmovie(title,rating,day,month,year);
        setanimationStyle(animation);
        setisMusical(musical);
        setageGroup(agegroup);
    }

    ostream & operator <<(ostream & out, const Animation& a){
        a.displayDetails(out);
        return out;
}

void Animation::displayDetails(ostream& out)const{
    Movie::displayDetails(out);
    out << setw(15) << left << "Genre" << ": " << getgenre() << endl;
    out << setw(15) << left << "Animation Style" << ": " << getanimationStyle() << endl;
    out << setw(15) << left << "Musical" << ": " << (getisMusical()? "Yes": "No") << endl;
    out << setw(15) << left << "Age Group" << ": " << getageGroup() << endl;
}