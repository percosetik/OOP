#pragma once
#include "User.h"
#include <string>

class SupportEngineer : public User {
private:
    std::string department;

public:
    SupportEngineer(int id, std::string name, std::string email, std::string department);

    std::string getDepartment() const;

    // Переопределяем виртуальный метод родителя
    void printInfo() const override; 
};
