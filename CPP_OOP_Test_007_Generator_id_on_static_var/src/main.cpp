#include <iostream>
#include <string>
using namespace std;

class Apple {

public:

    static int countApple;  // static - общая переменная для всех объектов класса
                // Apple. Инициализация вне класса ниже.

    Apple(int weight, string color) {
        id = countApple++;
        this->color = color;
        this->weight = 1;
    }

    int getId() {
        return id;
    }

    string getColor() {
        return color;
    }

private:

    int weight;
    string color;
    int id;

};

int Apple::countApple = 0;

int main() {

    setlocale(LC_ALL, "ru");

    Apple apple(150, "Red");
    Apple apple2(120, "Yellow");
    Apple apple3(250, "Green");
    cout << "id яблока: " << apple.getId() << " Цвет яблока: " << apple.getColor() << endl;
    cout << "id яблока: " << apple2.getId() << " Цвет яблока: " << apple2.getColor() << endl;
    cout << "id яблока: " << apple3.getId() << " Цвет яблока: " << apple3.getColor() << endl << endl;

    cout << "id яблока: " << apple.getId() << " Цвет яблока: " << apple.getColor() << endl;

    return 0;
}
