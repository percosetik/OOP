#pragma once
#include <string>
#include <iostream>

class Ticket {
private:
    int id;
    std::string title;
    std::string description;
    std::string status;
    std::string authorName;
    std::string assigneeName;

public:
    Ticket(int id, std::string title, std::string description, std::string authorName);
    
    void setAssignee(const std::string& name); // Метод, чтобы назначить инженера
    void printInfo() const;
};
