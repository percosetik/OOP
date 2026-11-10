#include <iostream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "Customer.h"
#include "SupportEngineer.h"
#include "Ticket.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. создаем участников
    Customer client(1, "Иван Иванов");
    SupportEngineer engineer(2, "Петр Петров", "Сетевое оборудование");

    // 2. демонстрация полиморфизма
    // создаем вектор указателей на базовый класс User
    std::vector<User*> users;
    users.push_back(&client);   // кладем наследника Customer
    users.push_back(&engineer); // кладем наследника SupportEngineer

    std::cout << "--- Список участников (Полиморфизм) ---\n";
    for (User* u : users) {
        u->printInfo(); // программа сама вызовет нужный метод (Customer или Engineer)
    }
    std::cout << "\n----------------------------------------\n\n";

    // 3. ассоциативные связи
    // создаем заявку, передавая указатель на автора (&client)
    Ticket ticket(101, "Не работает доступ к сетевому диску", &client);
    std::cout << "--- Создана заявка ---\n";
    ticket.printInfo();

    std::cout << "\n--- Назначаем инженера ---\n";
    // связываем заявку с инженером (передаем указатель &engineer)
    ticket.setAssignee(&engineer);
    ticket.printInfo();

    // меняем статус
    ticket.setStatus("Решена");
    std::cout << "\n--- Заявка закрыта ---\n";
    ticket.printInfo();

    return 0;
}
