//menu.cpp
//Made by Abdihakim Bashe 
//301390647
//hbashe@sfu.ca
//This cpp file contains the majority of the program

#include "book.h"
#include "dataBase.h"
#include <iomanip>
#include <algorithm>
//#includes, namespace
using namespace std;

//Menu Class
class menu {
// A string that contains the phrases for the books
    string stringInput;
    string numberInput;
    bool endProgram = false;
public:

//Default constructor and destructor
    menu() {}

    ~menu() {}

//Gets the Input for a string
    void setStringInput() {
        string words;
        getline(cin, words);
        stringInput = words;
    }

//Returns the string input collected
    string returnStringInput() {
        return stringInput;
    }

//Gets the input for a number
    void setNumberInput() {
        string words;
        getline(cin, words);
        for (int i = 0; i < words.size(); i++) {
            //Forces user to reenter if invalid
            while (isdigit(words.at(i)) == false) {
                cout << "That's an invalid index, please only include numbers in the dataBase: ";
                getline(cin, words);
            }
        }
        numberInput = words;
    }

//Returns the number input colled
    string returnNumberInput() {
        return numberInput;
    }

//Allows the user to end the program by changing the bool value
    void endTheProgram() {
        endProgram = true;
    }

//Returns the current status of the program
    bool returnProgramStatus() {
        return endProgram;
    }

}; // End of Menu Class


//Checks if an index is currently in the database
int rangeChecker(dataBase data, const string &s, menu &test) {
    string index = s;
    int intIndex = stoi(index);
    //If not a valid index, ask the user to reenter until it is
    while (intIndex > data.getSize() - 1 || intIndex < 0) {
        cout << "That's an invalid index, this index is not currently in the dataBase" << endl;
        cout << "Type in an Index Number: ";
        test.setNumberInput();
        index = test.returnNumberInput();
        intIndex = stoi(index);
    }
    //Return a valid index at the end
    return intIndex;
}

//Prints out the Welcome screen
int welcome(menu &test) {
    cout << "Welcome to your Book DataBase" << endl;
    cout << "Currently your Database is empty, Would you like to" << endl;
    cout << "1) Add a Book to the Database?" << endl;
    cout << "2) Load a Database from a Text File?" << endl;
    cout << "Select your choice by typing either 1 or 2" << endl;
    test.setStringInput();
    string choice = test.returnStringInput();
    //Gets the User to input a number
    while ((choice != "1") && (choice != "2")) {
        cout << "I'm having trouble understanding that, can you type in 1 or 2 please?" << endl;
        getline(cin, choice);
    }
    //Convert their choice to an int
    int num = stoi(choice);
    //Return their choice
    return num;
}

//Lets the user add a title to the book object
void addTitle(book &object, menu &test) {
    cout << "Add the Book Title: ";
    //Get input from the user
    test.setStringInput();
    string bookTitle = test.returnStringInput();;
    object.setTitle(bookTitle);
}

//Lets the user add an author to the book object
void addAuthor(book &object, menu &test) {
    cout << "Add the Book Author: ";
    //Get input from the user
    test.setStringInput();
    string bookAuthor = test.returnStringInput();
    object.setAuthor(bookAuthor);
}

//Lets the user add a date of Publication to the book object
void addYear(book &object, menu &test) {
    cout << "Add the Year of Publication (Eg: 2017): ";
    //Get a valid number from the user
    test.setNumberInput();
    string dateOfPublication = test.returnNumberInput();
    //Convert it to an int
    int date = stoi(dateOfPublication);
    //Check if it is a valid year, otherwise reenter the num
    while (date > 2020 || date < 0) {
        cout << "That's an invalid year, please type in a year" << endl;
        cout << "Type in an Index Number: ";
        test.setNumberInput();
        dateOfPublication = test.returnNumberInput();
        date = stoi(dateOfPublication);
    }
    object.setDateOfPub(date);
}

//Lets the user set the book type , eg hardcover, paperback, or digital
void addType(book &object, menu &test) {
    cout << "Add the Type of Book (Hardcover, Paperback, or Digital): ";
    //Get input from the user
    test.setStringInput();
    string bookMaterial = test.returnStringInput();
    //Ask to reenter if the words are not one of the three categories
    while ((bookMaterial != "Hardcover") && (bookMaterial != "Paperback") && (bookMaterial != "Digital")) {
        cout << "I didn't understand that, can you repeat it" << endl;
        cout << "Add the Type of Book (Hardcover, Paperback, or Digital): ";
        test.setStringInput();
        bookMaterial = test.returnStringInput();
    }
    object.setBookType(bookMaterial);
}

//Lets the user add an ISBN to the book object
void addISBN(book &object, menu &test) {
    cout << "Add the ISBN 10 or 13 Number (Eg: 9781285741550 or 9781285121): ";
    //Get a valid number from the user
    test.setNumberInput();
    string bookISBN = test.returnNumberInput();
    //Check if the number is 13 or 10 digits, reenter if not
    while (bookISBN.size() != 13 && bookISBN.size() != 10) {
        cout << "Not a valid ISBN Size, Please enter and ISBN 10 or 13 number" << endl;
        cout << "Add the ISBN 10 or 13 Number (Eg: 9781285741550 or 9781285121): ";
        test.setNumberInput();
        bookISBN = test.returnNumberInput();
    }
    object.setIsbn(bookISBN);
}

//Lets the user add the number of pages to the book object
void addPages(book &object, menu &test) {
    cout << "Add the Number of Pages: ";
    //Get a valid number from the user
    test.setNumberInput();
    string pageNum = test.returnNumberInput();
    int page = stoi(pageNum);
    //Check if the number is greater then 0, reenter if not
    while (page < 0) {
        cout << "That's an invalid number of Pages, please enter a positive number: ";
        test.setNumberInput();
        string pageNum;
        page = stoi(pageNum);
    }
    object.setPages(page);
}

//Functions to add a book to the database
dataBase addToDatabaseFirstTime(menu &test) {
    //Prompt the user to enter data
    cout << "To add Books to the Database, follow these instructions" << endl;
    cout << "The system will prompt you to add 6 pieces of information about each Book" << endl;
    book NewBook;
    //Create a book object, and add all the 6 fields to it
    addTitle(NewBook, test);
    addAuthor(NewBook, test);
    addYear(NewBook, test);
    addType(NewBook, test);
    addISBN(NewBook, test);
    addPages(NewBook, test);
    //Create a database, add the new book to it, then return the database
    dataBase newDataBase;
    newDataBase.addBook(NewBook);
    return newDataBase;
}

//Load the database from the file output.txt
dataBase loadDatabase() {
    //Create a database, load the data into it, then return it
    dataBase newDataBase;
    newDataBase.inputData("output.txt");
    cout << "Database has been loaded from output.txt" << endl;
    return newDataBase;
}

//Prints out the 7 options the user can choose from
int options(menu &test) {
    cout << "What would you like do now?" << endl;
    cout << "Type the corresponding number to choose" << endl;
    cout << "1) Add a Book" << endl;
    cout << "2) Delete a Book" << endl;
    cout << "3) Update a Book entry" << endl;
    cout << "4) Sort the Database" << endl;
    cout << "5) Search for a specific Book" << endl;
    cout << "6) Print the Database" << endl;
    cout << "7) Close the Database and save the current data" << endl;
    test.setNumberInput();
    string option = test.returnNumberInput();
    //If the users choice is not valid, make them reenter it
    while ((option != "1") && (option != "2") && (option != "3") && (option != "4") && (option != "5") &&
           (option != "6") && (option != "7")) {
        cout << "I'm having trouble understanding that, can you type in one of the previous numbers please?" << endl;
        cout << "Type in a Number: ";
        test.setNumberInput();
        option = test.returnNumberInput();
    }
    //Return their choice
    int num = stoi(option);
    return num;
}

//Lets the user add a book to an existing dataBase
dataBase addToDatabase(dataBase &d, menu &test) {
    //Create a book, and fill it up with the 6 fields
    book NewBook;
    addTitle(NewBook, test);
    addAuthor(NewBook, test);
    addYear(NewBook, test);
    addType(NewBook, test);
    addISBN(NewBook, test);
    addPages(NewBook, test);
    //Add the book to the database and return it
    d.addBook(NewBook);
    return d;
}

//Allows the user to delete a book
dataBase deleteABook(dataBase currentData, menu &test) {
    cout << "To Delete a Book, specify the index the book is at(Eg: 0 - " << currentData.getSize() - 1 << ")" << endl;
    cout << "Type in an Index Number: ";
    test.setNumberInput();
    string index = test.returnNumberInput();
    //Ask for a number, then check if it valid
    int intIndex = rangeChecker(currentData, index, test);
    //Delete the index 
    currentData.deleteSpecificBook(intIndex);
    cout << "Book Deleted" << endl;
    return currentData;
}

//Allows the user to update one of the 6 fields in book
dataBase updateValues(dataBase currentData, menu &test) {
    cout << "To update a Book, specify the index the book is at(Eg: 0 - " << currentData.getSize() - 1 << ")" << endl;
    cout << "Type in an Index Number: ";
    test.setNumberInput();
    string index = test.returnNumberInput();
    //Ask for a number and check if it is valid
    int intIndex = rangeChecker(currentData, index, test);

    cout << "Index: " << intIndex << " Selected" << endl;
    cout
            << "Would you like to Update the 1) Title, 2) Author, 3) Year of Publication, 4) Type of Book, 5) ISBN, or 6) Number of Pages"
            << endl;
    cout << "Type in one of the previous numbers: ";
    test.setNumberInput();
    string subIndex = test.returnNumberInput();
    //Ask for a number and check if it is between 1 and 6, reenter if false
    while (subIndex != "1" && subIndex != "2" && subIndex != "3" && subIndex != "4" && subIndex != "5" &&
           subIndex != "6") {
        cout << "Please enter one of the previously mentioned numbers: ";
        test.setNumberInput();
        subIndex = test.returnNumberInput();
    }
    //Create a book object
    //Update the book based on the subindex entered by the user
    book NewBook;
    if (subIndex == "1") {
        addTitle(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 1);
    }
    if (subIndex == "2") {
        addAuthor(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 2);
    }
    if (subIndex == "3") {
        addYear(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 3);
    }
    if (subIndex == "4") {
        addType(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 4);
    }
    if (subIndex == "5") {
        addISBN(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 5);
    }
    if (subIndex == "6") {
        addPages(NewBook, test);
        currentData.overwriteVal(NewBook, intIndex, 6);
    }
    //Return the updated database
    return currentData;
}
/*************************************************** Sorting Functions ***********************************/
//These functions allow the user to sort in ascending order, this is necessary to use binary search
bool sortTitle(const book &a, const book &b) {
    return a.getTitle() < b.getTitle();
}

bool sortAuthor(const book &a, const book &b) {
    return a.getAuthor() < b.getAuthor();
}

bool sortYear(const book &a, const book &b) {
    return a.getDateOfPub() < b.getDateOfPub();
}

bool sortBookType(const book &a, const book &b) {
    return a.getBookType() < b.getBookType();
}

bool sortIsbn(const book &a, const book &b) {
    return a.getIsbn() < b.getIsbn();
}

bool sortPages(const book &a, const book &b) {
    return a.getPages() < b.getPages();
}

//Lets the user sort each aspect of the vector in ascending order
dataBase sortData(dataBase &currentData, menu &test, vector<book> sortInfo) {
    cout << "Please choose one of the Following Categories to sort by" << endl;
    cout << "1) Title, 2) Author, 3) Year of Publication, 4) Type of Book, 5) ISBN, or 6) Number of Pages" << endl;
    cout << "Type in one of the previous numbers: ";
    //Ask for a  number
    test.setNumberInput();
    string subIndex = test.returnNumberInput();
    //If the number isnt 1-6 ask to reenter
    while (subIndex != "1" && subIndex != "2" && subIndex != "3" && subIndex != "4" && subIndex != "5" &&
           subIndex != "6") {
        cout << "Please enter one of the previously mentioned numbers: ";
        test.setNumberInput();
        subIndex = test.returnNumberInput();
    }
    //Sort the data based on which number the user entered
    //Using std sort function
    if (subIndex == "1") {
        sort(sortInfo.begin(), sortInfo.end(), sortTitle);
    }
    if (subIndex == "2") {
        sort(sortInfo.begin(), sortInfo.end(), sortAuthor);
    }
    if (subIndex == "3") {
        sort(sortInfo.begin(), sortInfo.end(), sortYear);
    }
    if (subIndex == "4") {
        sort(sortInfo.begin(), sortInfo.end(), sortBookType);
    }
    if (subIndex == "5") {
        sort(sortInfo.begin(), sortInfo.end(), sortIsbn);
    }
    if (subIndex == "6") {
        sort(sortInfo.begin(), sortInfo.end(), sortPages);
    }
    //Update the current database to contain the sorted data
    currentData.setVector(sortInfo);
    return currentData;
}

//Lets the user search through data
//Pass in a vector and a choice
void resultingData(vector<book> searchingData, menu &test, const int &x) {
    //Vector objects to store matches
    //Vector to store the real indexes
    vector<book> results;
    vector<int> trackers;
    //If x = 1, check if the title matches anything in the vector, push back any matches
    if (x == 1) {
        test.setStringInput();
        string sTopic = test.returnStringInput();
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getTitle() == sTopic) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //If x = 2, check if the author matches anything in the vector, push back any matches
    if (x == 2) {
        test.setStringInput();
        string sAuthor = test.returnStringInput();
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getAuthor() == sAuthor) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //If x = 3, check if the year matches anything in the vector, push back any matches
    if (x == 3) {
        test.setNumberInput();
        int sYear = 0;
        sYear = stoi(test.returnNumberInput());
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getDateOfPub() == sYear) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //If x = 4, check if the book type matches anything in the vector, push back any matches
    if (x == 4) {
        test.setStringInput();
        string sType = test.returnStringInput();
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getBookType() == sType) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //If x = 5, check if the isbn matches anything in the vector, push back any matches
    if (x == 5) {
        test.setStringInput();
        string sISBN = test.returnStringInput();
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getIsbn() == sISBN) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //If x = 6, check if the page number matches anything in the vector, push back any matches
    if (x == 6) {
        test.setNumberInput();
        int sPage = 0;
        sPage = stoi(test.returnNumberInput());
        for (int i = 0; i < searchingData.size(); i++) {
            if (searchingData.at(i).getPages() == sPage) {
                results.push_back(searchingData.at(i));
                trackers.push_back(i);
            }
        }
    }
    //Print out any matches found
    cout << "There are " << results.size() << " matches in the database:" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << trackers.at(i) << ": " << results.at(i).getTitle() << endl;
    }
}

//Allows the user to search for books that fit specific catergories
void searchData(menu &test, vector<book> &searchingData) {
    vector<book> results;
    cout << "Please choose one of the Following Categories to search for in the DataBase" << endl;
    cout << " 1) Title, 2) Author, 3) Year of Publication, 4) Type of Book, 5) ISBN, or 6) Number of Pages" << endl;
    cout << "Type in one of the previous numbers: ";
    test.setNumberInput();
    string subIndex = test.returnNumberInput();
    //Ask for input, if not valid ask to reenter
    while (subIndex != "1" && subIndex != "2" && subIndex != "3" && subIndex != "4" && subIndex != "5" &&
           subIndex != "6") {
        cout << "Please enter one of the previously mentioned numbers: ";
        test.setNumberInput();
        subIndex = test.returnNumberInput();
    }
    if (subIndex == "1") {
        cout
                << "Please type in a Book Title you would like to Search for \n(Will Print all Books that match the Title): ";
        sort(searchingData.begin(), searchingData.end(), sortTitle);
        resultingData(searchingData, test, 1);
    }
    if (subIndex == "2") {
        cout
                << "Please type in an Author you would like to Search for \n(Will Print all Books with matching authors): ";
        sort(searchingData.begin(), searchingData.end(), sortAuthor);
        resultingData(searchingData, test, 2);
    }
    if (subIndex == "3") {
        cout
                << "Please type in a Year you would like to Search for\n(Will Print all Books with matching Dates of Publication): ";
        sort(searchingData.begin(), searchingData.end(), sortYear);
        resultingData(searchingData, test, 3);
    }
    if (subIndex == "4") {
        cout
                << "Please type in a the Book Type you would like to Search for \n(Will Print all Books with the same material): ";
        sort(searchingData.begin(), searchingData.end(), sortBookType);
        resultingData(searchingData, test, 4);
    }
    if (subIndex == "5") {
        cout
                << "Please type in an ISBN Number you would like to Search for\n(Will Print all Books with a mactching ISBN): ";
        sort(searchingData.begin(), searchingData.end(), sortIsbn);
        resultingData(searchingData, test, 5);
    }
    if (subIndex == "6") {
        cout
                << "Please type in a Page Number you would like to Search for\n(Will Print all Books with the same amount of page numbers): ";
        sort(searchingData.begin(), searchingData.end(), sortPages);
        resultingData(searchingData, test, 6);
    }

}

/*************************************************** Main Function **********************************************/
int main() {
    //Create a Menu Class and call the welcome function
    menu information;
    int tracker = 0;
    tracker = welcome(information);
    int choices = 0;
    //Create a database and a vector of books
    dataBase c;
    vector<book> copy;
    //Do two actions depending on the choice made initally
    if (tracker == 1) {
        //Add to the Database and call the option func
        c = addToDatabaseFirstTime(information);
        choices = options(information);
    }
    if (tracker == 2) {
        //Load a Database and call the option func
        c = loadDatabase();
        choices = options(information);
    }

    //While option 7 isn't chosen continue running
    while (information.returnProgramStatus() != true) {
        if (choices == 1) {
            //Add to the Database and call the option func
            c = addToDatabase(c, information);
            choices = options(information);
        }
        if (choices == 2) {
            //Delete a book in the Database and call the option func
            c = deleteABook(c, information);
            choices = options(information);
        }
        if (choices == 3) {
            //Update a book in the Database and call the option func
            c = updateValues(c, information);
            choices = options(information);
        }
        if (choices == 4) {
            //Sort the data in the Database and call the option func
            copy = c.copyVector();
            c = sortData(c, information, copy);
            choices = options(information);
        }
        if (choices == 5) {
            //Search for something in the Database and call the option func
            copy = c.copyVector();
            searchData(information, copy);
            choices = options(information);
        }
        if (choices == 6) {
            ////Print out the Database and call the option func
            c.printDataBase();
            choices = options(information);
        }
        if (choices == 7) {
            //Store the current database under a text file, then end the program
            c.exportData();
            cout << "The Current DataBase has been saved. You can access it under \"data.txt\" " << endl;
            information.endTheProgram();
        }
    }

    cout << "Thanks you for using the DataBase" << endl;
    cout << "Program will now end" << endl;
}
//End of Program