# 📚 Library Management System

A **C++ console-based Library Management System**.  
It allows managing books, users, and loan records with an easy-to-use menu-driven interface.  

---

## ✨ Features

- 📖 **Books**
  - Add and manage books with quantity tracking
  - Search for books by prefix
  - View library sorted by ID or Name
- 👤 **Users**
  - Register and manage users
  - View all registered users
- 🔄 **Borrowing**
  - Borrow and return books
  - Track borrowed books per user
  - Print who borrowed a specific book
- 🛠 **Admin Tools**
  - Manage books and users
  - Inspect library state

---

## 🛠 Installation & Running

### Prerequisites
- C++17 or later
- g++ compiler (Linux/macOS/WSL) or MinGW/MSVC (Windows)

### Build & Run
In the project root, run:

```bash
g++ -std=c++17 -c Book.cpp BookInfo.cpp BookInventory.cpp BookService.cpp User.cpp UserService.cpp LoanService.cpp AdminService.cpp LibraryManager.cpp main.cpp
g++ -std=c++17 Book.o BookInfo.o BookInventory.o BookService.o User.o UserService.o LoanService.o AdminService.o LibraryManager.o main.o -o library-system
./library-system
````

Or build in one step:

```bash
g++ -std=c++17 *.cpp -o library-system
./library-system
```

---

## 📂 Project Structure

```
├── SortOption.h                   # Enum for sorting options
├── Book.h / Book.cpp              # Book entity
├── BookInfo.h / BookInfo.cpp      # Book metadata (quantity, borrowed)
├── BookInventory.h / .cpp         # Library book collection
├── BookService.h / .cpp           # Book operations (add, search, list)
├── User.h / User.cpp              # User entity
├── UserService.h / .cpp           # User registration & management
├── LoanService.h / .cpp           # Borrow/return operations
├── AdminService.h / .cpp          # Admin functionality
├── LibraryManager.h / .cpp        # System controller + menu
└── main.cpp                       # Entry point
```

---