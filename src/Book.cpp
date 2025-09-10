#include "Book.h"

Book::Book() {}

Book::Book(int id, std::string name)
    : id(id), name(std::move(name)) {}

Book::Book(const Book& other)
    : id(other.id), name(other.name) {}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
    }
    return *this;
}

int Book::getId() const {
    return id;
}

std::string Book::getName() const {
    return name;
}
