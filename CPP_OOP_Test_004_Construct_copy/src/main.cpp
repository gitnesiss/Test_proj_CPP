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

public:
    int* data;  // все поля в классе по умолчанию private

    // конструктор
    MyClass(int size) {
        this->size_inner = size;
        this->data = new int[size];
        
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "Вызвался конструктор " << this << endl;
    }

    // Конструктор копирования. Принимаем объект по ссылке
    MyClass(const MyClass &other) {
        this->size_inner = other.size_inner;

        this->data = new int[other.size_inner];

        for (int i = 0; i < other.size_inner; i++) {
            this->data[i] = other.data[i];
        }
        cout << "Вызвался конструктор копирования." << this << endl;
    }

    // деструктор вызывается в момент выхода из области видимости вызываемого
    // метода
    ~MyClass() {
        delete[] data;  // освобождение памяти выделенной под массив
        cout << "Объект " << data << " - ";
        cout << "Адрес массива " << data << ". Вызвался деструктор." << endl;
    }

private:
    int size_inner;
};

void foo() {
    cout << "Foo начало выполнения." << endl;
    MyClass a(1);
    cout << "Foo конец выполнения." << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    MyClass a(10);
    MyClass b(a);
    // MyClass c(20);
    // MyClass d(c);

    // foo();

    return 0;
}
