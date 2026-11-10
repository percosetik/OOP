#pragma once
#include <string>
#include <iostream>

class User;
class SupportEngineer;

class Ticket {
private:
    int id;
    std::string title;
    std::string status;
    
    User* author;             // кто создал (может быть только Customer)
    SupportEngineer* assignee; // кто решает (может быть nullptr, если не назначен)

public:
    Ticket(int id, std::string title, User* author);
    
    int getId() const;
    std::string getTitle() const;
    std::string getStatus() const;
    
    void setAssignee(SupportEngineer* eng);
    void setStatus(const std::string& newStatus);
    
    void printInfo() const;
};
