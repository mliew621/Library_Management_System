#include <iostream>
#include <string>
#include <vector>
#include "book.hpp"
#include "lib.hpp"

using namespace std;

#ifndef LIB_USER_H
#define LIB_USER_H

class LibraryUser {

    string name;
    int user_id;
    int borrowed_count;

public:

    //constructors
    LibraryUser();
    LibraryUser(string new_name, int new_id, int new_borrowed_count);

    //getter methods
    string get_name();
    int get_user_id();
    int get_borrowed_count();

    //borrowing and returning
    void borrow();
    void returns();

    //print
    void print_user();
};

class Student : public LibraryUser {
    bool is_graduated;
    int borrow_limit;
    vector <string> valid_genres;

public: 
    //constructors
    Student();
    Student(string name, int id, int borrowed_count, bool new_is_graduated, int new_borrow_limit, vector <string> allowed_genres);

    //getter methods
    int get_borrow_limit();

    void print();
};

class Teacher : public LibraryUser {
    int borrow_limit;
    vector <string> valid_genres;

public:
    Teacher();
    Teacher(int new_borrow_limit, LibraryUser new_user_info, vector <string> allowed_genres);

    int get_borrow_limit();

    void add_book_to_library(Library library_to_add, Book* book_pointer);
    void update_book_details();

    void print();

};

#endif