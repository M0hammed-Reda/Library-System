#include "BookService.h"
#include <iostream>
#include <algorithm>

BookService::BookService(BookInventory& bookInventory) : bookInventory(bookInventory) {}

BookInventory& BookService::getBookInventory() {
    return bookInventory;
}

void BookService::addBook(const Book& book, int total_quantity) {
    bookInventory.addBook(book, total_quantity);
    std::cout << "Book added successfully!\n";
}

void BookService::readAndAddBook() {
    std::cout << "Enter Book info: \n";
    
    std::cout << "Book ID: ";
    int id;
    std::cin >> id;
    
    std::cin.ignore(); 
    std::cout << "Book Name: ";
    std::string name;
    std::getline(std::cin, name);
    
    std::cout << "Total quantity of this Book: ";
    int total_quantity;
    std::cin >> total_quantity;
    
    Book book(id, name);
    addBook(book, total_quantity);
}

void BookService::listBooks(SortOption sortBy) {
    auto inventory = bookInventory.getInventory();
    std::vector<std::pair<int, const BookInfo*>> books;
    
    for (const auto& item : inventory) {
        books.push_back({item.first, &item.second});
    }
    
    if (sortBy == SortOption::ID) {
        std::sort(books.begin(), books.end(),
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            });
    } else if (sortBy == SortOption::NAME) {
        std::sort(books.begin(), books.end(),
            [](const auto& a, const auto& b) {
                return a.second->getBook().getName() < b.second->getBook().getName();
            });
    } else {
        std::cout << "Invalid sort option!\n";
        return;
    }
    
    for (const auto& book : books) {
        std::cout << "ID: " << book.second->getBook().getId()
            << "\tName: " << book.second->getBook().getName()
            << "\tTotal Quantity: " << book.second->getTotalQuantity()
            << "\tTotal Borrowed: " << book.second->getTotalBorrowed() << '\n';
    }
}

std::vector<Book> BookService::searchBooksByPrefix(const std::string& prefix) const {
    std::vector<Book> res;
    for (const auto& book : bookInventory.getInventory()) { 
        const std::string& bookName = book.second.getBook().getName();
        if (bookName.size() >= prefix.size() && bookName.substr(0, prefix.size()) == prefix) {
            res.push_back(book.second.getBook());
        }
    }
    return res;
}

void BookService::readAndSearchBooksByPrefix() {
    std::cout << "Enter book name prefix: ";
    std::string prefix;
    std::cin >> prefix;
    
    std::vector<Book> books = searchBooksByPrefix(prefix);
    
    if (books.empty()) {
        std::cout << "No books found with the prefix \"" << prefix << "\".\n";
        return;
    }
    
    std::cout << "Books matching prefix \"" << prefix << "\":\n";
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << i + 1 << ") ID: " << books[i].getId() << " - Name: " << books[i].getName() << '\n';
    }
}

