#pragma once
#include <string>
#include <iostream>

class User {
protected: // protected, чтобы наследники имели доступ к id и name
    int id;
    std::string name;

public:
    User(int id, std::string name);
    virtual ~User() {} // виртуальный деструктор 

    int getId() const;
    std::string getName() const;

    // виртуальная функция. делает класс абстрактным.
    virtual void printInfo() const = 0; 
};
