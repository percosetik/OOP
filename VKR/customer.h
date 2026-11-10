#pragma once
#include "User.h"

class Customer : public User {
public:
    Customer(int id, std::string name);
    
    // Переопределяем метод родителя
    void printInfo() const override; 
};
