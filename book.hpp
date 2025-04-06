#include <string>
#include <iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{
    string title, author, genre;
    int year_published;

public:
//constructors
Book();
Book (string new_title, string new_author, int new_year, string new_genre);
Book (string new_title, string new_author, int new_year);
Book (string new_title, string new_author);
Book (string new_title);

//print information
void print();

//getter methods
string get_title();
string get_author();
string get_genre();
int get_year();

//operator
bool operator==(Book target_book);
};

#endif