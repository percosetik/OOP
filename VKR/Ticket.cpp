#include "Ticket.h"

Ticket::Ticket(int id, std::string title, std::string description)
    : id(id), title(title), description(description), status("Новая") {}

int Ticket::getId() const { return id; }
std::string Ticket::getTitle() const { return title; }
std::string Ticket::getDescription() const { return description; }
std::string Ticket::getStatus() const { return status; }

void Ticket::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Ticket::printInfo() const {
    std::cout << "[Заявка #" << id << "]\n"
              << "  Тема:     " << title << "\n"
              << "  Описание: " << description << "\n"
              << "  Статус:   " << status << "\n";
}
