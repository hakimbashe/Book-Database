// Book.cpp
//Made by Abdihakim Bashe 
//301390647
//hbashe@sfu.ca

//Book Content file
#include "book.h"

//Proves methods for book.h
//Constructor / Destructor
book::book() {}

book::~book() {
}

//These getters return the various private elements
string book::getTitle() const {
    return title;
}

string book::getAuthor() const {
    return author;
}

int book::getDateOfPub() const {
    return dateOfPub;
}

string book::getBookType() const {
    return bookType;
}

string book::getIsbn() const {
    return isbn;
}

int book::getPages() const {
    return pages;
}

//These setters allow the user to access the private elements in book
void book::setTitle(const string &x) {
    title = x;
}

void book::book::setAuthor(const string &x) {
    author = x;
}

void book::setDateOfPub(const int &x) {
    dateOfPub = x;
}

void book::setBookType(const string &x) {
    bookType = x;
}

void book::setIsbn(const string &x) {
    isbn = x;
}

void book::setPages(const int &x) {
    pages = x;
}

//End of Program