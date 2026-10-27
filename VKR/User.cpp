#include "User.h"

User::User(int id, std::string name, std::string email)
    : id(id), name(name), email(email) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }

void User::printInfo() const {
    std::cout << "[Пользователь] ID: " << id 
              << " | Имя: " << name 
              << " | Email: " << email << "\n";
}
