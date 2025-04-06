#include <iostream>
#include <vector>
#include <string>
#include "lib.hpp"
#include "lib_user.hpp"
#include "book.hpp"
using namespace std;

//By Michelle Wang and Morgan Liew

int main() {
    //Initialize books
    Book book1;
    Book book2("Pride and Prejudice", "Jane Austen", 1813, "Classic");
    Book book3("Little Women", "Louisa May Alcott", 1868);
    Book book4("Jane Eyre", "Charlotte Bronte");
    Book book5("The Bell Jar");

    Book* book1_ptr = &book1;
    Book* book2_ptr = &book2;
    Book* book3_ptr = &book3;
    Book* book4_ptr = &book4;
    Book* book5_ptr = &book5;

    //Initialize library using default constructor
    Library library1;

    //Insert book
    library1.insertion(book1_ptr);
    library1.insertion(book2_ptr);
    library1.insertion(book3_ptr);
    library1.insertion(book4_ptr);
    library1.insertion(book5_ptr);
    

    library1.print();

    //default constructors
    vector <string> valid_genres;
    valid_genres.push_back("Classic");
    Student student1("Jane", 12345, 0, false, 1, valid_genres);
    Teacher teacher1;

    //successful borrow
    library1.borrow_book(student1, "Pride and Prejudice");
    
    //print user 
    student1.Student::print();

    //teacher should not be able to borrow (book already borrowed)
    library1.borrow_book(teacher1, "Pride and Prejudice");

    //borrowing over limit (should not be able to borrow)
    library1.borrow_book(student1, "Little Women");

    //student returns Pride and Prejudice 
    library1.return_book(student1, "Pride and Prejudice");

    //student returns book they do not have (return unsuccessful)
    library1.return_book(student1, "Litte Women");

    //invalid genre for student (OPTIONAL)
    library1.borrow_book(student1, "1984");

    //advanced search that exists
    library1.advanced_search("", "Louisa", "");

    //advanced search that does not exist (unsuccessful)
    library1.advanced_search("Great", "", "");

    //teacher add book to library
    Book* book_to_add = new Book("The Handmaid's Tale", "Margaret Atwood");
    teacher1.add_book_to_library(library1, book_to_add);



    return 0;
}