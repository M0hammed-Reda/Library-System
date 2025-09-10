#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <iostream>
#include <iomanip>
#include "BookInventory.h"
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
    LibraryManager();

    void displayMenu() const;
    void run();
};

#endif // LIBRARYMANAGER_H

