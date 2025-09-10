#include "UserService.h"
#include <iostream>
#include <algorithm>

void UserService::listUsers(SortOption sortOption) const {
    std::cout << "All Users in the system: \n";
    std::vector<User> sortedUsers = users;

    if (sortOption == SortOption::ID) {
        std::sort(sortedUsers.begin(), sortedUsers.end(),
            [](const User& a, const User& b) {
                return a.getId() < b.getId();
            });
    } else if (sortOption == SortOption::NAME) {
        std::sort(sortedUsers.begin(), sortedUsers.end(),
            [](const User& a, const User& b) {
                return a.getName() < b.getName();
            });
    } else {
        std::cout << "Invalid sort option!\n";
        return;
    }

    for (size_t i = 0; i < sortedUsers.size(); ++i)
        std::cout << i + 1 << ") " << sortedUsers[i].getName() << std::endl;
}

void UserService::updateUserDetails(int userId, const User& updatedInfo) {
    auto it = std::find_if(users.begin(), users.end(),
        [userId](const User& user) {
            return user.getId() == userId;
        });

    if (it != users.end()) {
        *it = updatedInfo;
        std::cout << "User details updated successfully!\n";
    } else {
        std::cout << "User not found!\n";
    }
}

void UserService::registerUser(const User& user) {
    users.push_back(user);
    std::cout << "User registered successfully!\n";
}

void UserService::readAndRegisterUser() {
    std::cout << "Enter User info: \n";
    
    std::cout << "User ID: ";
    int id;
    std::cin >> id;
    
    std::cin.ignore();
    std::cout << "User Name: ";
    std::string name;
    std::getline(std::cin, name);
    
    User user(id, name);
    registerUser(user);
}

bool UserService::userExist(int user_id) const {
    for (const auto& user : users) {
        if (user.getId() == user_id)
            return true;
    }
    return false;
}

const User* UserService::getUserById(int user_id) const {
    for (const auto& user : users) {
        if (user.getId() == user_id)
            return &user;
    }
    return nullptr;
}

