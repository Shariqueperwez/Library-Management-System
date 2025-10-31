#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Structure for Book
struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;

    Book(int id = 0, string title = "", string author = "", bool isIssued = false, string issuedTo = "")
        : id(id), title(title), author(author), isIssued(isIssued), issuedTo(issuedTo) {}
};

class Library {
private:
    vector<Book> books;
    string filename = "library.csv"; // File to save data

public:
    Library() {
        loadFromFile(); // Load all data at startup
    }

    void addBook(int id, string title, string author);
    void issueBook(int id, string student);
    void returnBook(int id);
    void listBooks();
    void deleteBook(int id);
    void saveToFile();
    void loadFromFile();
};

// Add Book
void Library::addBook(int id, string title, string author) {
    for (auto &b : books) {
        if (b.id == id) {
            cout << "Book with this ID already exists.\n";
            return;
        }
    }
    books.push_back(Book(id, title, author, false, ""));
    saveToFile(); // Save after adding
    cout << "Book added successfully!\n";
}

// Issue Book
void Library::issueBook(int id, string student) {
    for (auto &b : books) {
        if (b.id == id) {
            if (b.isIssued) {
                cout << "Book already issued to " << b.issuedTo << ".\n";
            } else {
                b.isIssued = true;
                b.issuedTo = student;
                saveToFile();
                cout << "Book issued to " << student << " successfully.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return Book
void Library::returnBook(int id) {
    for (auto &b : books) {
        if (b.id == id) {
            if (!b.isIssued) {
                cout << "This book was not issued.\n";
            } else {
                b.isIssued = false;
                b.issuedTo = "";
                saveToFile();
                cout << "Book returned successfully.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// List Books
void Library::listBooks() {
    if (books.empty()) {
        cout << "No books in library.\n";
        return;
    }
    cout << "\n--- Library Books ---\n";
    for (auto &b : books) {
        cout << "ID: " << b.id << "\nTitle: " << b.title
             << "\nAuthor: " << b.author
             << "\nStatus: " << (b.isIssued ? "Issued to " + b.issuedTo : "Available")
             << "\n---------------------\n";
    }
}

// Delete Book
void Library::deleteBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            saveToFile();
            cout << "Book deleted successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Save all data to CSV
void Library::saveToFile() {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error saving file.\n";
        return;
    }
    fout << "id,title,author,isIssued,issuedTo\n";
    for (auto &b : books) {
        fout << b.id << "," << b.title << "," << b.author << ","
             << (b.isIssued ? "1" : "0") << "," << b.issuedTo << "\n";
    }
    fout.close();
}

// Load all data from CSV
void Library::loadFromFile() {
    ifstream fin(filename);
    if (!fin) return; // File might not exist first time

    books.clear();
    string line;
    getline(fin, line); // skip header

    while (getline(fin, line)) {
        stringstream ss(line);
        string idStr, title, author, issuedStr, issuedTo;
        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, issuedStr, ',');
        getline(ss, issuedTo, ',');

        if (idStr.empty()) continue;
        int id = stoi(idStr);
        bool issued = (issuedStr == "1");
        books.push_back(Book(id, title, author, issued, issuedTo));
    }
    fin.close();
}

// Main Menu
int main() {
    Library lib;
    int choice, id;
    string title, author, student;

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. List Books\n3. Issue Book\n4. Return Book\n5. Delete Book\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;
        case 2:
            lib.listBooks();
            break;
        case 3:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, student);
            lib.issueBook(id, student);
            break;
        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            lib.returnBook(id);
            break;
        case 5:
            cout << "Enter Book ID to Delete: ";
            cin >> id;
            lib.deleteBook(id);
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
