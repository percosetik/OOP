#include "SupportEngineer.h"

// передача id, name, email в конструктор базового класса User(...)
SupportEngineer::SupportEngineer(int id, std::string name, std::string email, std::string department)
    : User(id, name, email), department(department) {}

std::string SupportEngineer::getDepartment() const {
    return department;
}

void SupportEngineer::printInfo() const {
    User::printInfo(); // вызов метод родителя
    std::cout << "  Отдел: " << department << "\n"; // добавление своего
}
