#include "SupportEngineer.h"

SupportEngineer::SupportEngineer(int id, std::string name, std::string department)
    : User(id, name), department(department) {}

std::string SupportEngineer::getDepartment() const { return department; }

void SupportEngineer::printInfo() const {
    std::cout << "[Инженер] ID: " << id << " | Имя: " << name << " | Отдел: " << department << "\n";
}
