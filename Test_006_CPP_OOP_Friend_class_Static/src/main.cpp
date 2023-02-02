#include <iostream>
#include <string>
using namespace std;

/*
 * Класс Human получает доступ ко всем методам класса Apple
 * Static переменная как счётчик.
 */

// Чтобы класс Apple знал о существовании класса Human пока он не объявлен
// определяем класс
class Human;
class Apple;

class Human {
public:
    void TakeApple(Apple &apple);

    void EatApple(Apple &apple) {
        // apple.
    }
};

class Apple {

    friend Human;  // сделали дружественным класс Human

public:

    static int countApple;  // static - общая переменная для всех объектов класса
                // Apple. Инициализация вне класса ниже.

    Apple(int weight, string color) {
        countApple++;
        this->color = "Green";
        this->weight = 1;
    }

private:

    int weight;
    string color;

};

int Apple::countApple = 0;

void Human::TakeApple(Apple &apple) {
    cout << "TakeApple " << "weight = " << apple.weight << " color = " << apple.color << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    Apple apple(150, "Red");
    cout << "Счётчик яблок: " << apple.countApple << endl;
    Apple apple2(120, "Yellow");
    Apple apple3(250, "Green");
    cout << "Счётчик яблок: " << apple.countApple << endl;
    cout << "Счётчик яблок: " << apple2.countApple << endl;
    cout << "Счётчик яблок: " << apple3.countApple << endl << endl;

    cout << "Для static переменной не обязательно вызывать объект класса. " <<
    "Счётчик яблок: " << Apple::countApple << endl;

    Human human;
    human.TakeApple(apple);

    return 0;
}
