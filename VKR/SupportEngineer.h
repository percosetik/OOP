#pragma once
#include "User.h"

class SupportEngineer : public User {
private:
    std::string department;

public:
    SupportEngineer(int id, std::string name, std::string department);
    std::string getDepartment() const;

    void printInfo() const override;
};
