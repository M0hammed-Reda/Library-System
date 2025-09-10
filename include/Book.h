#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id {};
    std::string name {};

public:
    Book();
    Book(int id, std::string name);
    Book(const Book& other);
    Book& operator=(const Book& other);

    int getId() const;
    std::string getName() const;
};

#endif // BOOK_H
