#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include <vector>
#include <string>
#include "Book.h"
#include "BookInventory.h"
#include "User.h"
#include "UserService.h"

class LoanService {
private:
    struct BorrowRecord {
        int userId;
        int bookId;
        BorrowRecord(int userId, int bookId) : userId(userId), bookId(bookId) {}
    };

    BookInventory& bookInventory;
    UserService& userService;
    std::vector<BorrowRecord> borrowRecords;

public:
    LoanService(BookInventory& inventory, UserService& users);

    bool borrowBook(int bookId, int userId);
    void readAndBorrowBook();
    bool returnBook(int bookId, int userId);
    void readAndReturnBook();
    std::vector<Book> listLoansForUser(int userId) const;
    std::vector<User> listBorrowers(int bookId) const;
    void printBorrowersByBookId(int bookId) const;
    void printBorrowersByBookName(const std::string& bookName) const;
    void readAndPrintBorrowersByBookName();
};

#endif // LOANSERVICE_H

