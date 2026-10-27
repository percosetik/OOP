#pragma once
#include <string>
#include <iostream>

class Ticket {
private:
    int id;
    std::string title;
    std::string description;
    std::string status;

public:
    Ticket(int id, std::string title, std::string description);

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getStatus() const;

    void setStatus(const std::string& newStatus);
    void printInfo() const;
};
