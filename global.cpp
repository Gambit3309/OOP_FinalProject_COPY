#include <iostream>
#include "global.h"
#include "Animation.h"
#include "Action.h"
#include "Scifi.h"
#include "conio.h"

using namespace std;

Movie* mpointer[55] = {nullptr};
Director* d[3] = {nullptr};
int CurrentNumberOfMovies = 0;
int MaxNumberOfMovies = 55;

Variables::~Variables(){}