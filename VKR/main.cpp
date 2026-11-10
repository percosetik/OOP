#include <iostream>
#include <windows.h>
#include "User.h"
#include "SupportEngineer.h"
#include "Ticket.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. создаем обычного пользователя (автора заявки)
    User user(1, "Иван Иванов", "ivanov@company.local");
    
    std::cout << "--- Создан пользователь ---\n";
    user.printInfo();
    std::cout << "\n----------------------------------------\n\n";

    // 2. создаем инженера техподдержки (наследник)
    SupportEngineer engineer(2, "Петр Петров", "petrov@company.local", "Сетевое оборудование");
    
    std::cout << "--- Создан инженер ---\n";
    engineer.printInfo();
    std::cout << "\n----------------------------------------\n\n";

    // 3. создаем заявку от имени пользователя
    // Передаем user.getName() в качестве автора
    Ticket ticket(101, "Не работает доступ к сетевому диску", 
                  "При попытке подключения к диску Z возникает ошибка авторизации.",
                  user.getName());
    
    std::cout << "--- Создана новая заявка ---\n";
    ticket.printInfo();
    std::cout << "\n----------------------------------------\n\n";

    // 4. назначаем инженера на заявку
    // Связываем объект Ticket с объектом SupportEngineer по имени
    ticket.setAssignee(engineer.getName());
    
    std::cout << "--- Заявка назначена инженеру и взята в работу ---\n";
    ticket.printInfo();
    std::cout << "\n----------------------------------------\n\n";

    // 5. демонстрация жизненного цикла (закрываем заявку)
    ticket.setStatus("Решена");
    std::cout << "--- Статус заявки обновлен ---\n";
    ticket.printInfo();

    return 0;
}
