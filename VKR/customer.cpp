#include "Customer.h"

Customer::Customer(int id, std::string name) : User(id, name) {}

void Customer::printInfo() const {
    std::cout << "[Заявитель] ID: " << id << " | Имя: " << name << "\n";
}
