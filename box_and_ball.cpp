#include <iostream>
#include <vector>
#include <string>

// шарик с цветом
class Ball
{
private:
    std::string color;

public:
    explicit Ball(const std::string &col) : color(col) {}

    const std::string &getColor() const
    {
        return color;
    }
};

// контейнер, который владеет шариками в куче
class Box
{
private:
    std::string title;
    std::vector<Ball *> items;

public:
    explicit Box(const std::string &boxTitle) : title(boxTitle) {}

    // закрываем копирование, чтобы два объекта не делили одни указатели
    Box(const Box &) = delete;
    Box &operator=(const Box &) = delete;

    // деструктор: подчищаем все шарики из кучи при уничтожении коробки
    ~Box()
    {
        for (auto *item : items)
        {
            delete item;
        }
        items.clear();
    }

    // добавление шарика в текущую коробку
    void putBall(Ball *ball)
    {
        if (ball)
        {
            items.push_back(ball);
        }
    }

    // печать отчета о содержимом
    void showContent() const
    {
        std::cout << "--- " << title << " ---\n";
        std::cout << "Всего шаров: " << items.size() << "\n";

        if (items.empty())
        {
            std::cout << "Тут пока пусто.\n\n";
            return;
        }

        std::cout << "Список цветов: ";
        for (size_t i = 0; i < items.size(); ++i)
        {
            std::cout << items[i]->getColor() << (i + 1 < items.size() ? ", " : "");
        }
        std::cout << "\n\n";
    }
};

int main()
{
    // ставим русскую локаль для терминала
    setlocale(LC_ALL, "");

    // инициализируем две коробки
    Box redBox("Первая коробка");
    Box blueBox("Вторая коробка");

    // выделяем шарики в динамической памяти через new
    redBox.putBall(new Ball("Красный"));
    redBox.putBall(new Ball("Синий"));
    redBox.putBall(new Ball("Зеленый"));
    redBox.putBall(new Ball("Красный"));
    redBox.putBall(new Ball("Желтый"));
    redBox.putBall(new Ball("Белый"));

    blueBox.putBall(new Ball("Черный"));
    blueBox.putBall(new Ball("Синий"));
    blueBox.putBall(new Ball("Оранжевый"));
    blueBox.putBall(new Ball("Фиолетовый"));

    // смотрим что лежит внутри
    redBox.showContent();
    blueBox.showContent();

    // память освободится сама в деструкторах коробок при выходе
    return 0;
}