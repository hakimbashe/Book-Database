//database.cpp
//Made by Abdihakim Bashe 
//301390647
//hbashe@sfu.ca

//database content file
#include "dataBase.h"
#include <vector>

//Constructor/ Destructor
dataBase::dataBase() {}

dataBase::~dataBase() {

}

//Return the size of the vector of books
int dataBase::getSize() const {
    return data.size();
}

vector<book> dataBase::copyVector() const {
    return data;
}

void dataBase::setVector(const vector<book> &test) {
    data = test;
}


//Add a book onto the end of the vector
void dataBase::addBook(const book &b) {
    data.push_back(b);
}

//Change a specific element of a book at the certain index
// x is the index, choice correspondes to each of the 6 private variables in book
void dataBase::overwriteVal(const book &b, const int &x, const int &choice) {
    if (choice == 1) {
        data.at(x).setTitle(b.getTitle());
    }
    if (choice == 2) {
        data.at(x).setAuthor(b.getAuthor());
    }
    if (choice == 3) {
        data.at(x).setDateOfPub(b.getDateOfPub());
    }
    if (choice == 4) {
        data.at(x).setBookType(b.getBookType());
    }
    if (choice == 5) {
        data.at(x).setIsbn(b.getIsbn());
    }
    if (choice == 6) {
        data.at(x).setPages(b.getPages());
    }
}

//Deletes a specific book from the vector
void dataBase::deleteSpecificBook(const int &x) {
    data.erase(data.begin() + x);
}

//Sends data to a textfile
void dataBase::exportData() const {
    //Create the file
    ofstream file;
    file.open("data.txt");
    //Add content line by line, with | seperating each of the 6 elements
    for (int i = 0; i < data.size(); i++) {
        string temp = data.at(i).getTitle();
        file << temp;
        file << "|";
        temp = data.at(i).getAuthor();
        file << temp;
        file << "|";
        int temp2 = data.at(i).getDateOfPub();
        file << temp2;
        file << "|";
        temp = data.at(i).getBookType();
        file << temp;
        file << "|";
        temp = data.at(i).getIsbn();
        file << temp;
        file << "|";
        temp2 = data.at(i).getPages();
        file << temp2 << endl;
    }
    //Close the file once the entire vector has been read out
    file.close();
}

//Read in data from a textfile
void dataBase::inputData(const string &fileName) {
    //Open the file
    ifstream file;
    file.open(fileName);
    //Two strings to read in
    string current;
    string temp;
    //Read in temp
    while (getline(file, temp)) {
        //loop thru each word
        for (int i = 0; i < temp.size(); i++) {
            //If the current char is | , push back all the characters b4 into the vector of strings
            if (temp.at(i) == '|') {
                lines.push_back(current);
                current.clear();
                i++;
            }
            //Add all the chars to current string
            current += temp.at(i);
            if (i == temp.size() - 1) {
                //Push back the last string at the end
                lines.push_back(current);
                current.clear();
            }
        }
        //Add every 6 elements to a book element
        //Push back the book into the vector
        if (lines.size() % 6 == 0) {
            book newBook;
            newBook.setTitle(lines.at(0));
            newBook.setAuthor(lines.at(1));
            int year = stoi(lines.at(2));
            newBook.setDateOfPub(year);
            newBook.setBookType(lines.at(3));
            newBook.setIsbn(lines.at(4));
            int bookPages = stoi(lines.at(5));
            newBook.setPages(bookPages);
            data.push_back(newBook);
            lines.clear();
        }

    }
    //Close the file
    file.close();
}

//Print out the DataBase with | searching every element
void dataBase::printDataBase() const {
    for (int i = 0; i < data.size(); i++) {
        cout << i << ": " << data.at(i).getTitle() << " | " << data.at(i).getAuthor() << " | "
             << data.at(i).getDateOfPub() << " | " << data.at(i).getBookType() << " | " << data.at(i).getIsbn() << " | "
             << data.at(i).getPages() << endl;
    }

}

//Update all the values in book
void dataBase::updateTitle(const string &x, const int &index) {
    data.at(index).setTitle(x);
}

void dataBase::updateAuthor(const string &x, const int &index) {
    data.at(index).setAuthor(x);
}

void dataBase::updateYear(const int &x, const int &index) {
    data.at(index).setDateOfPub(x);
}

void dataBase::updateBookType(const string &x, const int &index) {
    data.at(index).setBookType(x);
}

void dataBase::updateIsbn(const string &x, const int &index) {
    data.at(index).setIsbn(x);
}

void dataBase::updatePages(const int &x, const int &index) {
    data.at(index).setPages(x);
}

//End of Program