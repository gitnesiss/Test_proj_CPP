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

class MyClass {
    int data;  // все поля в классе по умолчанию private
    int* arr;
public:
    // конструктор
    MyClass(int value) {
        data = value;
        
        arr = new int[value];
        for (int i = 0; i < value; i++) {
            arr[i] = i;
        }

        cout << "Объект " << data << " Вызвался конструктор." << endl;
    }
    // деструктор вызывается в момент выхода из области видимости вызываемого
    // метода
    ~MyClass() {
        delete[] arr;  // освобождение памяти выделенной под массив
        cout << "Объект " << data << " Вызвался деструктор." << endl;
    }
};

void foo() {
    cout << "Foo начало выполнения." << endl;
    MyClass a(1);
    cout << "Foo конец выполнения." << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    MyClass a(1);
    MyClass b(2);
    MyClass c(5);

    foo();

    return 0;
}
