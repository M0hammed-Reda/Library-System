#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <vector>
#include <string>
#include "User.h"
#include "SortOption.h"

class UserService {
private:
    std::vector<User> users;

public:
    void listUsers(SortOption sortOption) const;
    void updateUserDetails(int userId, const User& updatedInfo);
    void registerUser(const User& user);
    void readAndRegisterUser();
    bool userExist(int user_id) const;
    const User* getUserById(int user_id) const;
};

#endif // USERSERVICE_H

