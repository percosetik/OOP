#include <iostream>
#include <string>

// класс 1: Пользователь (User)
class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, std::string name, std::string email)
        : id(id), name(name), email(email) {}

    int getId() const { 
        return id; 
    }

    std::string getName() const { 
        return name; 
    }

    std::string getEmail() const { 
        return email; 
    }

    void printInfo() const {
        std::cout << "[Пользователь] ID: " << id 
                  << " | Имя: " << name 
                  << " | Email: " << email << "\n";
    }
};

// класс 2: Заявка (Ticket)
class Ticket {
private:
    int id;
    std::string title;
    std::string description;
    std::string status;

public:
    Ticket(int id, std::string title, std::string description)
        : id(id), title(title), description(description), status("Новая") {}

    int getId() const { 
        return id; 
    }

    std::string getTitle() const { 
        return title; 
    }

    std::string getDescription() const { 
        return description; 
    }

    std::string getStatus() const { 
        return status; 
    }

    void setStatus(const std::string& newStatus) {
        status = newStatus;
    }

    void printInfo() const {
        std::cout << "[Заявка #" << id << "]\n"
                  << "  Тема:     " << title << "\n"
                  << "  Описание: " << description << "\n"
                  << "  Статус:   " << status << "\n";
    }
};

// точка входа: демонстрация работы
int main() {
    // 1. Создание пользователя
    User user(1, "Иван Иванов", "ivanov@company.local");
    user.printInfo();

    std::cout << "\n----------------------------------------\n\n";

    // 2. Создание заявки в начальном статусе "Новая"
    Ticket ticket(101, "Не работает доступ к сетевому диску", 
                  "При попытке подключения к диску Z возникает ошибка авторизации.");
    ticket.printInfo();

    std::cout << "\n--- Смена статусов (жизненный цикл) ---\n";

    // 3. Перевод в статус "В работе"
    ticket.setStatus("В работе");
    std::cout << "Статус обновлен -> " << ticket.getStatus() << "\n";

    // 4. Перевод в статус "Решена"
    ticket.setStatus("Решена");
    std::cout << "Статус обновлен -> " << ticket.getStatus() << "\n";

    // 5. Перевод в статус "Закрыта"
    ticket.setStatus("Закрыта");
    std::cout << "Статус обновлен -> " << ticket.getStatus() << "\n\n";

    // Итоговое состояние карточки
    ticket.printInfo();

    return 0;
}
