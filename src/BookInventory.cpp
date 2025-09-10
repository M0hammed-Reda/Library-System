#include "BookInventory.h"

void BookInventory::addBook(const Book& book, int total_quantity) {
    inventory.emplace(book.getId(), BookInfo(book, total_quantity));
}

BookInfo& BookInventory::getBookInfo(int bookId) {
    return inventory.at(bookId);
}

const BookInfo& BookInventory::getBookInfo(int bookId) const {
    return inventory.at(bookId);
}

const std::unordered_map<int, BookInfo>& BookInventory::getInventory() const {
    return inventory;
}

void BookInventory::updateBookInfo(int bookId, const Book& updatedInfo) {
    auto it = inventory.find(bookId);
    if (it != inventory.end()) {
        it->second.setBook(updatedInfo);
        std::cout << "Book information has been updated successfully!\n";
    } else {
        std::cout << "There is no book with this ID. Please try again!\n";
    }
}

bool BookInventory::checkAvailability(int bookId) const {
    auto it = inventory.find(bookId);
    return it != inventory.end() && it->second.getTotalQuantity() > it->second.getTotalBorrowed();
}

void BookInventory::adjustQuantity(int bookId, int delta) {
    auto it = inventory.find(bookId);
    if (it != inventory.end()) {
        it->second.adjustQuantity(delta);
    } else {
        std::cout << "Book not found in inventory!\n";
    }
}

bool BookInventory::bookExists(int bookId) const {
    return inventory.find(bookId) != inventory.end();
}

