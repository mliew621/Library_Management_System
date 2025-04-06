#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <vector>
#include <string>
#include "book.hpp"

//Forward Declaration
class Student;
class Teacher;

using namespace std;


class Library {
    vector <Book*> library_pointers;
    vector <Book> is_borrowed;

public:
    //constructors
    Library();
    Library(vector <Book*> new_library);

    //insertion, second one BONUS
    void insertion(Book* new_book);
    void insertion(string new_title, string new_author, int new_year, string new_genre);

    //removal, second one BONUS
    void removal(Book book_remove);
    void removal(string title_remove, string author_remove, int year_remove, string genre_remove);

    //search
    void advanced_search(string title_substr, string author_substr, string genre_substr);

    //borrowing and returning
    void borrow_book(Student &user, string title);
    void borrow_book(Teacher &user, string title);
    void return_book(Student &user, string title);
    void return_book(Teacher &user, string title);

    //print 
    void print();

};

#endif