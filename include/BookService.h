#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include <vector>
#include <string>
#include "Book.h"
#include "BookInventory.h"
#include "SortOption.h"

class BookService {
private:
    BookInventory& bookInventory;

public:
    BookService(BookInventory& bookInventory);

    BookInventory& getBookInventory();
    void addBook(const Book& book, int total_quantity);
    void readAndAddBook();
    void listBooks(SortOption sortBy);
    std::vector<Book> searchBooksByPrefix(const std::string& prefix) const;
    void readAndSearchBooksByPrefix();
};

#endif // BOOKSERVICE_H

