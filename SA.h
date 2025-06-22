#ifndef SA_H_INCLUDED
#define SA_H_INCLUDED

#include<iostream>

using namespace std;


void InputMoviesFromFile();
void InputDirectorsFromFile();
void DeleteAllPointers();

bool AddNewMovie();
bool AddNewDirector();

void DisplayAllMovies();
void DisplayAllDirectors();

void DisplayAllMoviesByGenre(string);
void DisplayAllMoviesByRating(int);

void DisplayByDirector(string);
void DisplayByYear(int);
void DisplayByTitle(string);
void DisplayByRating(int);
void DisplayByScore(int);

void SortByTitle();
void SortMoviesByYear();

int SearchTitle(string);

void RequestToAssignNewDirector();

void writeMoviesToNewFile();

string StringToLowercase(string);
#endif 