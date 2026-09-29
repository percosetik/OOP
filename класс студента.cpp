
#include <iostream>
#include <vector>
#include <string>

// создать класс Student с хранением информации об оценках в объекте
// предусмотреть методы для добавления оценок и их просмотра

class Student {
    std::string name;
    std::vector<int> grades;

public:
    Student(const std::string& n) : name(n) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    void showGrades() const {
        std::cout << "Студент: " << name << "\nОценки: ";
        if (grades.empty()) {
            std::cout << "(пока нет оценок)";
        }
        else {
            for (int g : grades) {
                std::cout << g << " ";
            }
        }
        std::cout << "\n";
    }
};

// создаем структуру Box и превращаем ее в класс
class Box {
    double length = 0;
    double width = 0;
    double height = 0;
public:
    Box(double l, double w, double h) :  // конструктор с параметрами
        length(l), width(w), height(h) {}

    double get_volume() {
        return length* height* width;
    }
};

int main() {
    Box gift_box = { 2, 2, 2 };
    std::cout << gift_box.get_volume();
    Student s("Иван");

    s.addGrade(5);
    s.addGrade(4);
    s.addGrade(3);

    s.showGrades();
}


