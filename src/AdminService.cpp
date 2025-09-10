#include "AdminService.h"
#include <iostream>

AdminService::AdminService(UserService& users, BookService& books)
    : userService(users), bookService(books) {}

void AdminService::addUser(const User& user) {
    userService.registerUser(user);
}

void AdminService::readAndAddUser() {
    userService.readAndRegisterUser();
}

void AdminService::printLibraryById() const {
    std::cout << "Library Books (sorted by ID):\n";
    bookService.listBooks(SortOption::ID);
}

void AdminService::printLibraryByName() const {
    std::cout << "Library Books (sorted by Name):\n";
    bookService.listBooks(SortOption::NAME);
}

void AdminService::printUsers() const {
    userService.listUsers(SortOption::NAME);
}

