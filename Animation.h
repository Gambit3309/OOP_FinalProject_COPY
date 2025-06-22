#ifndef Animation_H_INCLUDED
#define Animation_H_INCLUDED

#include <iostream>
#include "MovieBaseClass.h"
#include <fstream>
#include "Date.h"

using namespace std;

class Animation:public Movie{
private:
    int animationStyle = 0;
    bool isMusical;
    int ageGroup;
    
    string genre = "Animation";

protected:
    void setanimationStyle(int);
    void setisMusical(bool);
    void setageGroup(int);

    int getanimationStyle()const;
    int getageGroup()const;
    bool getisMusical()const;
    
    void displayDetails(ostream &)const override;
    
public:
    Animation(string = "", int = 0,int = 0,int = 0,int = 0,int = 0,int = 0, bool = false, int = 0);
    ~Animation();
    Animation(const Animation &);

    //void displayDetails()const override;
    void changeAnimationStyle(int);
    void setmovie(string, int, int, int ,int, int, bool, int);
    
    int calculateScore()const override;
    
    string getgenre()const override;
    string suggestMerchandise()const;
    
    bool isFamilyFriendly()const;

    friend ostream & operator <<(ostream &, const Animation&);
};

#endif