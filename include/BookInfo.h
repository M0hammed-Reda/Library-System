#ifndef BOOKINFO_H
#define BOOKINFO_H

#include "Book.h"

class BookInfo {
private:
    Book book;
    int total_quantity;
    int total_borrowed;

public:
    BookInfo(const Book& book, int total_quantity);

    const Book& getBook() const;
    int getTotalQuantity() const;
    int getTotalBorrowed() const;

    void setBook(const Book& newBook);
    void adjustQuantity(int delta);
    void adjustBorrowed(int delta);
};

#endif // BOOKINFO_H

