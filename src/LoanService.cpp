#include "LoanService.h"
#include <iostream>
#include <algorithm>

LoanService::LoanService(BookInventory& inventory, UserService& users)
    : bookInventory(inventory), userService(users) {}

bool LoanService::borrowBook(int bookId, int userId) {
    if (!bookInventory.bookExists(bookId)) {
        std::cout << "This book doesn't exist in the inventory.\n";
        return false;
    }
    
    if (!bookInventory.checkAvailability(bookId)) {
        std::cout << "This book is not available for borrowing.\n";
        return false;
    }

    if (!userService.userExist(userId)) {
        std::cout << "User doesn't exist! Try registering first.\n";
        return false;
    }

    borrowRecords.emplace_back(userId, bookId);
    bookInventory.getBookInfo(bookId).adjustBorrowed(1);
    std::cout << "Book borrowed successfully!\n";
    return true;
}

void LoanService::readAndBorrowBook() {
    std::cout << "Enter User ID: ";
    int userId;
    std::cin >> userId;
    
    std::cout << "Enter Book ID: ";
    int bookId;
    std::cin >> bookId;
    
    borrowBook(bookId, userId);
}

bool LoanService::returnBook(int bookId, int userId) {
    auto it = std::find_if(borrowRecords.begin(), borrowRecords.end(),
        [bookId, userId](const BorrowRecord& record) {
            return record.bookId == bookId && record.userId == userId;
        });
    
    if (it == borrowRecords.end()) {
        std::cout << "No record found of this user borrowing this book.\n";
        return false;
    }
    
    borrowRecords.erase(it);
    bookInventory.getBookInfo(bookId).adjustBorrowed(-1);
    std::cout << "Book returned successfully!\n";
    return true;
}

void LoanService::readAndReturnBook() {
    std::cout << "Enter User ID: ";
    int userId;
    std::cin >> userId;
    
    std::cout << "Enter Book ID: ";
    int bookId;
    std::cin >> bookId;
    
    returnBook(bookId, userId);
}

std::vector<Book> LoanService::listLoansForUser(int userId) const {
    std::vector<Book> books;
    for (const auto& record : borrowRecords) {
        if (record.userId == userId && bookInventory.bookExists(record.bookId)) {
            books.push_back(bookInventory.getBookInfo(record.bookId).getBook());
        }
    }
    return books;
}

std::vector<User> LoanService::listBorrowers(int bookId) const {
    std::vector<User> res;
    for (const auto& borrowRecord : borrowRecords) {
        if (borrowRecord.bookId == bookId) {
            const User* user = userService.getUserById(borrowRecord.userId);
            if (user) {
                res.push_back(*user);
            }
        }
    }
    return res;
}

void LoanService::printBorrowersByBookId(int bookId) const {
    if (!bookInventory.bookExists(bookId)) {
        std::cout << "Book doesn't exist in the inventory.\n";
        return;
    }
    
    const Book& book = bookInventory.getBookInfo(bookId).getBook();
    std::cout << "Users who borrowed book \"" << book.getName() << "\" (ID: " << book.getId() << "):\n";
    
    std::vector<User> borrowers = listBorrowers(bookId);
    if (borrowers.empty()) {
        std::cout << "No users have borrowed this book.\n";
        return;
    }
    
    for (size_t i = 0; i < borrowers.size(); ++i) {
        std::cout << i + 1 << ") " << borrowers[i].getName() 
            << " (ID: " << borrowers[i].getId() << ")\n";
    }
}

void LoanService::printBorrowersByBookName(const std::string& bookName) const {
    bool found = false;
    for (const auto& item : bookInventory.getInventory()) {
        const Book& book = item.second.getBook();
        if (book.getName() == bookName) {
            printBorrowersByBookId(book.getId());
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No book with name \"" << bookName << "\" found in the inventory.\n";
    }
}

void LoanService::readAndPrintBorrowersByBookName() {
    std::cout << "Enter book name: ";
    std::string name;
    std::getline(std::cin, name);
    
    printBorrowersByBookName(name);
}

