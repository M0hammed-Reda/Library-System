#include "LibrarySystem.h"

void LibraryManager::run()
{
    while (running)
    {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            bookService.readAndAddBook();
            break;
        case 2:
            bookService.readAndSearchBooksByPrefix();
            break;
        case 3:
            loanService.readAndPrintBorrowersByBookName();
            break;
        case 4:
            adminService.printLibraryById();
            break;
        case 5:
            adminService.printLibraryByName();
            break;
        case 6:
            adminService.readAndAddUser();
            break;
        case 7:
            loanService.readAndBorrowBook();
            break;
        case 8:
            loanService.readAndReturnBook();
            break;
        case 9:
            adminService.printUsers();
            break;
        case 10:
            std::cout << "Exiting the library system. Goodbye ^ _ ^\n";
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
