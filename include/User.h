#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;

public:
    User();
    User(int id, const std::string& name);
    User(const User& other);
    User& operator=(const User& other) = default;

    int getId() const;
    const std::string& getName() const;
    bool operator==(const User& other) const;
};

#endif // USER_H
