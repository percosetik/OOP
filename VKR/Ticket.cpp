#include "Ticket.h"
#include "User.h"
#include "SupportEngineer.h"

Ticket::Ticket(int id, std::string title, User* author)
    : id(id), title(title), status("Новая"), author(author), assignee(nullptr) {}

int Ticket::getId() const { return id; }
std::string Ticket::getTitle() const { return title; }
std::string Ticket::getStatus() const { return status; }

void Ticket::setAssignee(SupportEngineer* eng) {
    assignee = eng;
    status = "В работе";
}

void Ticket::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Ticket::printInfo() const {
    std::cout << "[Заявка #" << id << "] Тема: " << title << " | Статус: " << status << "\n";
    std::cout << "  Автор: " << author->getName() << "\n";
    
    // проверяем, назначен ли исполнитель (указатель не пустой)
    if (assignee != nullptr) {
        std::cout << "  Исполнитель: " << assignee->getName() << " (Отдел: " << assignee->getDepartment() << ")\n";
    } else {
        std::cout << "  Исполнитель: Не назначен\n";
    }
}
