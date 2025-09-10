#ifndef BOOKINVENTORY_H
#define BOOKINVENTORY_H

#include <unordered_map>
#include <iostream>
#include "Book.h"
#include "BookInfo.h"

class BookInventory {
private:
    std::unordered_map<int, BookInfo> inventory;

public:
    void addBook(const Book& book, int total_quantity);
    BookInfo& getBookInfo(int bookId);
    const BookInfo& getBookInfo(int bookId) const;
    const std::unordered_map<int, BookInfo>& getInventory() const;
    void updateBookInfo(int bookId, const Book& updatedInfo);
    bool checkAvailability(int bookId) const;
    void adjustQuantity(int bookId, int delta);
    bool bookExists(int bookId) const;
};

#endif // BOOKINVENTORY_H

