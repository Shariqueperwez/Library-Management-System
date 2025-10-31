# Library-Management-System
Simple Library Management System in C++ with CSV data save/load


# 📚 Library Management System (C++)

A **simple console-based Library Management System** built using **C++** 💻.  
It helps manage books in a library by allowing the user to **add, issue, return, and delete books** — with all data automatically stored in a **CSV file**, so your records stay safe even after the program is closed. 🗂️

---

## 🧩 **Project Overview**

🎯 **Main Objective:**  
To implement and understand the fundamental concepts of C++ like:
- 🧱 **Classes and Objects**
- 📄 **File Handling**
- 📚 **Vectors and Strings**
- 🧭 **Menu-driven Programming**

This project provides an easy and efficient way to keep track of books 📖 and their issue status.

---

## ⚙️ **Features**

✨ Add new books to the library  
📋 List all books with their current status  
🎟️ Issue a book to a student  
🔁 Return a book  
❌ Delete a book from records  
💾 Automatically save and load data from **library.csv**

---

## 🧠 **How the Program Works**

When the program starts:
- It **automatically loads** all existing records from the file **`library.csv`**.  
- Every time you **add**, **issue**, **return**, or **delete** a book, the file updates automatically.  

Each record in the CSV file contains the following details:

| ID | Title | Author | Issue Status | Issued To |
|----|--------|---------|---------------|------------|

### 📄 Example (`library.csv`)
id,title,author,isIssued,issuedTo
101,C++ Programming,Bjarne Stroustrup,0,
102,Data Structures,Mark Weiss,1,Ayesha

yaml
Copy code

📝 Here:
- `0` → Book is **available**  
- `1` → Book is **issued** to a student  

---

## 💻 **How to Compile and Run**

### 🪟 For Windows:
```bash
g++ library_save.cpp -o library
library
🐧 For Linux / 🍎 macOS:
bash
Copy code
g++ library_save.cpp -o library
./library
🖥️ Example Output
--- Library Management System ---

1. Add Book
2. List Books
3. Issue Book
4. Return Book
5. Delete Book
6. Exit

Enter choice: 1
Enter Book ID: 101
Enter Title: C++ Basics
Enter Author: Bjarne Stroustrup
Book added successfully!
✅ Even after closing and reopening the program, your data remains saved in library.csv!



⭐ If you found this project helpful, don't forget to give it a star!

⭐ Feel free to fork, modify, and contribute to improve this project!
🚀 Happy Coding!
