#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "UserService.h"
#include "BookService.h"

class AdminService {
private:
    UserService& userService;
    BookService& bookService;

public:
    AdminService(UserService& users, BookService& books);

    void addUser(const User& user);
    void readAndAddUser();
    void printLibraryById() const;
    void printLibraryByName() const;
    void printUsers() const;
};

#endif // ADMINSERVICE_H

