#include <string>
#include <iostream>
#include "lib.hpp"
#include "book.hpp"
#include "lib_user.hpp"
#include <vector>
using namespace std;


//constructors
Library::Library() {}

Library::Library(vector <Book*> new_library) {
    library_pointers = new_library;
}

//INPUT: pointer to a book object 
//PROCESSING: iterates through the library to see if the current book already exists, if so doesn't allow to insert that book and 
//prints that book is already in library, if not it adds the book to the library and prints that it has been inserted into the library 
//OUTPUT: void function (n/a)
void Library::insertion(Book* new_book) {
    //check if book exists
    bool book_exists = false;
    for (int i = 0; i < library_pointers.size(); i++) {
        if(*new_book == *library_pointers[i]) {
            book_exists = true;
        }
    }
    if(book_exists) {
        cout << "This book already exists in the library." << endl;
    }
    else {
        library_pointers.push_back(new_book);
        cout << new_book->get_title() << " has been successfully inserted into the library." << endl;
    }
}

//OPTIONAL METHOD
//INPUT: takes book information (title, author, year published, genre)
//PROCESSING: iterates through the library to see if the current book already exists, if so doesn't allow to insert that book and 
//prints that book is already in library, if not it adds the book to the library and prints that it has been inserted into the library. 
//difference from the previous method is that it creates a book object 
//OUTPUT: void function (n/a)
void Library::insertion(string new_title, string new_author, int new_year, string new_genre) {
    bool book_exists = false;
    for (int i = 0; i < library_pointers.size(); i++) {
        if (new_title == library_pointers[i]->get_title()) {
            book_exists = true;
        }
    }
    
    if (book_exists) {
        cout << new_title << " already exists in the library." << endl;
    }
    else {
        Book new_book(new_title, new_author, new_year, new_genre);
        Book* new_book_address = &new_book;
        library_pointers.push_back(new_book_address);
        cout << new_title << " has successfully been added to the library." << endl;
    }
}

//INPUT: book object 
//PROCESSING: iterates through the library vector to check if the book you want to remove exists. if it exists, then it is erased from the library, 
//otherwise nothing happens and the code prints that that book does not exist
//OUTPUT: void function (n/a)
void Library::removal(Book book_remove) {
    bool book_exists = false;
    for (int i = 0; i < library_pointers.size(); i++) {
        if (book_remove == *library_pointers[i]) {
            book_exists = true;
            library_pointers.erase(library_pointers.begin()+i);
            library_pointers[i] = nullptr;
            cout << book_remove.get_title() << " has been successfully removed from the library." << endl;
        }
    }
    if (!book_exists) {
        cout << book_remove.get_title() << " does not exist in the library." << endl;
    }
}

//OPTIONAL method 
//INPUT: book information (title, author, year of publication, genre)
//PROCESSING: iterates through the library vector to check if the book you want to remove exists. if it exists, then it is erased from the library, 
//otherwise nothing happens and the code prints that that book does not exist
//OUTPUT: void function (n/a)
void Library::removal(string title_remove, string author_remove, int year_remove, string genre_remove) {
    bool book_exists = false;
    for (int i = 0; i < library_pointers.size(); i++) {
        if (title_remove == library_pointers[i]->get_title()
         && (author_remove == library_pointers[i]->get_author() || author_remove == "n/a")
         && (year_remove == library_pointers[i]->get_year() || year_remove == 0)
         && (genre_remove == library_pointers[i]->get_genre() || genre_remove == "n/a")) {
            book_exists = true;
            library_pointers.erase(library_pointers.begin()+i);
            library_pointers[i] = nullptr;      
        }
    }
    if (!book_exists) {
        cout << title_remove << " does not exist in the library." << endl;
    }
}

//INPUT: book information (title, author, genre)
//PROCESSING: iterates through the library and compares given substring with the corressponding piece of book info (ex. title, author, or genre), 
//if a match is found prints that book, if not, prints no match found
//OUTPUT: void (n/a)
void Library::advanced_search(string title_substr, string author_substr, string genre_substr) {
    int index = 0;
    for (int i = 0; i < library_pointers.size(); i++) {
        bool book_found = false;
        if ((!title_substr.empty() && (library_pointers[i]->get_title().find(title_substr) != string::npos))
        || (!author_substr.empty() && library_pointers[i]->get_author().find(author_substr) != string::npos)
        || (!genre_substr.empty() && library_pointers[i]->get_genre().find(genre_substr) != string::npos)) {
            book_found = true;
        }
        if (book_found) {
            library_pointers[i]->print();
            index++;
        }
    }
    if (index == 0) {
        cout << "No match found." << endl;
    }
    
}
//INPUT: user and title of book that wants to be borrowed
//PROCESSING: iterates through the borrowed books vector to check if that book is currently borrowed, if it is, then the user cannot borrow the book. 
//if it is not currently borrowed and under the user's borrowing limit (checked in the if statement) then prints a message, addds to that users 
//borrowing count and adds it to the is_borrowed vector.
//OUTPUT: void (n/a)
void Library::borrow_book(Student &user, string title) {
    bool currently_borrowed = false;
    for (int i = 0; i < is_borrowed.size(); i++) {
        if (title == is_borrowed[i].get_title()) {
            currently_borrowed = true;
        }
    }

    if((!currently_borrowed) && user.get_borrowed_count() < user.get_borrow_limit()) {
        for (int i = 0; i < library_pointers.size(); i++) {
            if (title == library_pointers[i]->get_title()) {
                is_borrowed.push_back(*library_pointers[i]);
            }
        }
        user.borrow();
        cout << title << " has been borrowed by " << user.get_name() << "." << endl;
    }
    else {
        cout << "Book cannot be borrowed." << endl;
    }
}
void Library::borrow_book(Teacher &user, string title) {
    bool currently_borrowed = false;
    for (int i = 0; i < is_borrowed.size(); i++) {
        if (title == is_borrowed[i].get_title()) {
            currently_borrowed = true;
        }
    }
    if(!currently_borrowed && user.get_borrowed_count() < user.get_borrow_limit()) {
         for (int i = 0; i < library_pointers.size(); i++) {
            if (title == library_pointers[i]->get_title()) {
                is_borrowed.push_back(*library_pointers[i]);
            }
        }
        user.borrow();
        cout << title << " has been borrowed by " << user.get_name() << "." << endl;

    }
    else {
        cout << "Book cannot be borrowed." << endl;
    }
}

//INPUT: user object and title of book that wants to be returned 
//PROCESSING: iterates through is_borrowed vector to find the borrowed book and erases it from the is_borrowed vector, 
//decreases the borrowed count of the user, and prints a returned message. otherwise prints that return is unsuccessful. 
//OUTPUT: void (n/a)
void Library::return_book(Student &user, string title) {
    bool currently_borrowed = false;
    int index;
    for (int i = 0; i < is_borrowed.size(); i++) {
        if (title == is_borrowed[i].get_title()) {
            currently_borrowed = true;
            is_borrowed.erase(is_borrowed.begin()+i);
        }
    }
    if (currently_borrowed) {
        cout << user.get_name() << " has returned " << title << endl;
        user.returns();
    }

    else{
        cout << "Return unsuccessful." << endl;
    }
}
void Library::return_book(Teacher &user, string title) {
    bool currently_borrowed = false;
    int index;
    for (int i = 0; i < is_borrowed.size(); i++) {
        if (title == is_borrowed[i].get_title()) {
            currently_borrowed = true;
            is_borrowed.erase(is_borrowed.begin()+i);
        }
    }
    if (currently_borrowed) {
        cout << user.get_name() << " has returned " << title << endl;
        user.returns();
    }
}

//INPUT: n/a
//PROCESSING: prints information of each book in the library
//OUTPUT: void (n/a)
void Library::print() {
    cout << "Here is the information on each book in the library: " << endl;
    for (int i = 0; i < library_pointers.size(); i++) {
        cout << "Book " << i+1 << ":" << endl;
        library_pointers[i]->Book::print();
    }
}
