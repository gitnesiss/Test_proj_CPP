#include <iostream>
#include <string>
using namespace std;

// класс человек
class Human {
    
public:
    int age;        // поля класса
    string name;    // поля класса
    int weight;     // поля класса

    void print() {
        cout << "Имя: " << name << "\tВозраст: " << age << "\tВес: " << weight << endl;
    }
};

// класс кофемашины
class CoffeeGrinder {

private:
    bool checkVoltage() {
        return true;  // захардкодил всегда верно
    }

public:
    // // начать перемалывание кофэ
    // void start() {
    //     bool voltageIsNormal = checkVoltage();
    //     if (voltageIsNormal) {  // эквивалентно (voltageIsNormal == true)
    //         cout << "Вжжжжжух!!!" << endl;
    //     } else {
    //         cout << "BEEP BEEP!!!" << endl;
    //     }
    // }

    // верхняя функция написанная короче
    void start() {
        if (checkVoltage()) {  // эквивалентно (voltageIsNormal == true)
            cout << "Вжжжжжух!!!" << endl;
        } else {
            cout << "BEEP BEEP!!!" << endl;
        }
    }
};

// класс точки
class Point {

private:
    int x;
    int y;
    
public:
    // Реализация конструктора по умолчанию
    Point() {
        x = 0;
        y = 0;
    }
    // Конструктор класса - перегруженный класс
    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
    }
    // Конструктор класса - перегруженный класс
    Point(int valueX, bool boolean) {
        x = valueX;
        if (boolean) {
            y = 1;
        } else {
            y = -1;
        }
    }

    // геттер
    int getX() {
        return x;
    }
    // сеттер
    void setX(int value) {
        x = value;
    }

    int getY() {
        return y;
    }

    void setY(int value) {
        y = value;
    }

    void print() {
        cout << "x = " << x << "\ty = " << y << endl;
    }
};

int main() {

    setlocale(LC_ALL, "ru");
    CoffeeGrinder sanremo_cafe_racer;
    sanremo_cafe_racer.start();

    cout << endl;

    Point a5;
    a5.print();
    a5.setY(11);
    a5.getX();
    a5.print();
    a5.setX(6);
    a5.print();
    a5.setX(12);
    int result = a5.getX();
    cout << "result = " << result << endl;

    cout << endl;

    Point a(5, 44);
    a.print();
    Point b(77, 9);
    b.print();

    cout << endl;

    bool varBool = true;
    Point c(52, varBool);
    c.print();
    varBool = false;
    Point d(31, varBool);
    d.print();

    return 0;
}
