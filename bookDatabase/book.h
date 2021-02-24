// Book.h
//Made by Abdihakim Bashe 
//301390647
//hbashe@sfu.ca

//Book Header File
#ifndef BOOK_H
#define BOOK_H

//#includes, namespace, and defines
#include<iostream>
#include<string>

using namespace std;

//Book Class
class book {
    //These 6 elements make up each component of a book
    string title;
    string author;
    int dateOfPub;
    string bookType;
    string isbn;
    int pages;
public:
    //Default constructor / destructor
    book();

    ~book();

    //Group of Getters
    string getTitle() const;

    string getAuthor() const;

    int getDateOfPub() const;

    string getBookType() const;

    string getIsbn() const;

    int getPages() const;

//Setters
    void setTitle(const string &x);

    void setAuthor(const string &x);

    void setDateOfPub(const int &x);

    void setBookType(const string &x);

    void setIsbn(const string &x);

    void setPages(const int &x);

}; // End of Book class

#endif
//End of Program