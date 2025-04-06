#include <iostream>
#include <string>
#include "book.hpp"
using namespace std;

//no parameters. Since year is an int, default is set to 0
Book::Book() : title("n/a"), author("n/a"), year_published(0), genre("n/a") {}

//all parameters
Book::Book(string new_title, string new_author, int new_year, string new_genre) 
: title(new_title), author(new_author), year_published(new_year), genre(new_genre) {}

//no genre
Book::Book(string new_title, string new_author, int new_year)
: title(new_title), author(new_author), year_published(new_year), genre("n/a") {}

//only title and author
Book::Book(string new_title, string new_author) : title(new_title), author(new_author), year_published(0), genre("n/a") {}

//only title
Book::Book(string new_title) : title(new_title), author("n/a"), year_published(0), genre("n/a") {}

//Input: none
//Processing: prints information on book
//Output: none (void)
void Book::print() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year Published: " << year_published << endl;
    cout << "Genre: " << genre << endl;
}

//getter methods
string Book::get_title() { return title; }
string Book::get_author() { return author; }
int Book::get_year() { return year_published; }
string Book::get_genre() { return genre; }

//Input: book object
//Processing: checks if the attributes of the target book are equal to the other book in consideration. 
//Output: bool (true or false)
bool Book::operator==(Book target) {
    if ((target.title == title) 
    && (target.author == author || target.author == "n/a") 
    && (target.year_published == year_published || target.year_published == 0) 
    && (target.genre == genre || target.genre == "n/a")) {
        return true;
    }
    return false;
}