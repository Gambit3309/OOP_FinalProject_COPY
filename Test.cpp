#include <iostream>
#include "MovieBaseClass.h"
#include "Date.h"
#include "Director.h"
#include "Scifi.h"
#include "Action.h"
#include "Animation.h"
#include <string>
#include "global.h"
#include "SA.h"

using namespace std;

int main()
{
    InputDirectorsFromFile();
    InputMoviesFromFile();
    DisplayByRating(8);
    DeleteAllPointers();
}
