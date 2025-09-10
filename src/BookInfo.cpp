#include "BookInfo.h"
#include <iostream>

BookInfo::BookInfo(const Book& book, int total_quantity) :
    book(book), total_quantity(total_quantity), total_borrowed(0) {}

const Book& BookInfo::getBook() const {
    return book;
}

int BookInfo::getTotalQuantity() const {
    return total_quantity;
}

int BookInfo::getTotalBorrowed() const {
    return total_borrowed;
}

void BookInfo::setBook(const Book& newBook) {
    book = newBook;
}

void BookInfo::adjustQuantity(int delta) {
    total_quantity += delta;
}

void BookInfo::adjustBorrowed(int delta) {
    total_borrowed += delta;
}

