#pragma once
#include <string>
#include <iostream>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, std::string name, std::string email);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    // Сделаем метод виртуальным, чтобы наследник мог его переопределить
    virtual void printInfo() const;
};
