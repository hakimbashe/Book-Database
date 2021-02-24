//dataBase.h
//Made by Abdihakim Bashe 
//301390647
//hbashe@sfu.ca

//dataBase header file
#ifndef DATABASE_H
#define DATABASE_H
//#includes, defines, and namespace
#include "book.h"
#include <vector>
#include <fstream>

using namespace std;

//Start of Book Class
class dataBase {
    //Data contains all the Books
    vector<book> data;
    //Lines are used for reading in from a textfile
    vector<string> lines;
public:
    //Constructor
    dataBase();
    //Destructor
    ~dataBase();

    //Getter
    int getSize() const;
    //Create a copy of the vector.
    vector<book> copyVector() const;
    //Set the vector to another vector
    void setVector(const vector<book> &test);
    //Add book to the vector
    void addBook(const book &b);
    //Change the values for a specific book
    void overwriteVal(const book &b, const int & x, const int & choice);
    //Delete a book
    void deleteSpecificBook(const int &x);
    //Send data to a textfile
    void exportData() const;
    //Read data from a textfile
    void inputData(const string &fileName);
    //Print the Database
    void printDataBase() const;
    //These values update each of the private variables from book
    void updateTitle(const string &x, const int &index);

    void updateAuthor(const string &x, const int &index);

    void updateYear(const int &x, const int &index);

    void updateBookType(const string &x, const int &index);

    void updateIsbn(const string &x, const int &index);

    void updatePages(const int &x, const int &index);

}; // End of Database Class

#endif
//End of Program

