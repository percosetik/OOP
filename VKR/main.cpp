#include <iostream>
#include <windows.h>
#include "User.h"
#include "SupportEngineer.h"
#include "Ticket.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. обычный пользователь
    User user(1, "Иван Иванов", "ivanov@company.local");
    user.printInfo();

    std::cout << "\n----------------------------------------\n\n";

    // 2. инженер техподдержки (наследник)
    SupportEngineer engineer(2, "Петр Петров", "petrov@company.local", "Сетевое оборудование");
    engineer.printInfo();

    std::cout << "\n----------------------------------------\n\n";

    // 3. заявка
    Ticket ticket(101, "Не работает доступ к сетевому диску", 
                  "При попытке подключения к диску Z возникает ошибка авторизации.");
    ticket.printInfo();

    return 0;
}
