#include "../include/User.h"

User::User() 
    : id(0), name() {}

User::User(int id, const std::string& name)
    : id(id), name(name) {}

User::User(const User& other)
    : id(other.id), name(other.name) {}

int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

bool User::operator==(const User& other) const {
    return id == other.id;
}