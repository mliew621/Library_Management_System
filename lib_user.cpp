#include <iostream>
#include <string>
#include <vector>
#include "lib_user.hpp"
#include "book.hpp"
#include "lib.hpp"
using namespace std;

//constructors
LibraryUser::LibraryUser() {
    name = "n/a";
    user_id = 0;
    borrowed_count = 0;
}
LibraryUser::LibraryUser(string new_name, int new_id, int new_borrowed_count) : name(new_name), user_id(new_id), borrowed_count(new_borrowed_count) {}

//getter methods
string LibraryUser::get_name() { return name; }
int LibraryUser::get_user_id() { return user_id; }
int LibraryUser::get_borrowed_count() { return borrowed_count; }

//Processing: increase borrow count by one
void LibraryUser::borrow() {
    borrowed_count++;
}
//Processing: decrease borrow count by one
void LibraryUser::returns() {
    borrowed_count--;
}

//Input: none
//Processing: prints the information of the library user
//Output: none
void LibraryUser::print_user() {
    cout << "Name: " << name << endl;
    cout << "User ID: " << user_id << endl;
    cout << "Borrowed Count: " << borrowed_count << endl;
}

//student constructors
Student::Student() : LibraryUser(), is_graduated(false), borrow_limit(1){}
Student::Student(string name, int id, int borrowed_count, bool new_is_graduated, int new_borrow_limit, vector <string> allowed_genres)
 : LibraryUser(name, id, borrowed_count), is_graduated(new_is_graduated), borrow_limit(new_borrow_limit), valid_genres(allowed_genres) {}

//teacher constructors
Teacher::Teacher() : LibraryUser(), borrow_limit(2){}
Teacher::Teacher(int new_borrow_limit, LibraryUser new_user_info, vector <string> allowed_genres) 
 : LibraryUser(new_user_info), borrow_limit(new_borrow_limit), valid_genres(allowed_genres) {}

//getter methods
int Student::get_borrow_limit() { return borrow_limit; }
int Teacher::get_borrow_limit() { return borrow_limit; }

//Input: Library that the book is to be added to, and pointer to book that is added to the lbirary
//Processing: uses library::insertion method to add the book to the library
//Output: none (void)
void Teacher::add_book_to_library(Library library_to_add, Book* book_pointer) {
    library_to_add.insertion(book_pointer);
}

//print methods
void Student::print(){
    cout << "Information on Student:" << endl;
    LibraryUser::print_user();
}

//Input: none
//Processing: uses LibraryUser::print() to print information on student or teacher, and identifies whether the user is a student or teacher
//Output: none
void Teacher::print() {
    cout << "Information on Teacher:" << endl;
    LibraryUser::print_user();
}