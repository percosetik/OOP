#include "Ticket.h"

Ticket::Ticket(int id, std::string title, std::string description, std::string authorName)
    : id(id), title(title), description(description), status("Новая"), authorName(authorName), assigneeName("Не назначен") {}

void Ticket::setAssignee(const std::string& name) {
    assigneeName = name;
    status = "В работе";
}

void Ticket::printInfo() const {
    std::cout << "[Заявка #" << id << "]\n"
              << "  Автор:    " << authorName << "\n"
              << "  Тема:     " << title << "\n"
              << "  Статус:   " << status << "\n"
              << "  Исполнитель: " << assigneeName << "\n";
}
