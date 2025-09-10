#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <iostream>
#include "BookService.h"
#include "UserService.h"
#include "LoanService.h"
#include "AdminService.h"

class LibraryManager {
private:
    BookInventory inventory;
    BookService bookService;
    UserService userService;
    LoanService loanService;
    AdminService adminService;
    bool running;

public:
    LibraryManager()
        : bookService(inventory),
        loanService(inventory, userService),
        adminService(userService, bookService),
        running(true) {}

    void displayMenu() const {
        std::cout << "\n========================================\n";
        std::cout << "              Library Menu              \n";
        std::cout << "========================================\n";
        std::cout << " 1) Add Book\n";
        std::cout << " 2) Search Books by Prefix\n";
        std::cout << " 3) Print Who Borrowed Book by Name\n";
        std::cout << " 4) Print Library by ID\n";
        std::cout << " 5) Print Library by Name\n";
        std::cout << " 6) Add User\n";
        std::cout << " 7) User Borrow Book\n";
        std::cout << " 8) User Return Book\n";
        std::cout << " 9) Print Users\n";
        std::cout << "10) Exit\n";
        std::cout << "========================================\n";
        std::cout << "Enter your menu choice [1 - 10]: ";
    }

    void run();
};

#endif // LIBRARY_SYSTEM_H
