#include <iostream>
#include <string>
using namespace std;


class Human {
    
public:
    int age;        // поля класса
    string name;    // поля класса
    int weight;     // поля класса

    void print() {
        cout << "Имя: " << name << "\tВозраст: " << age << "\tВес: " << weight << endl;
    }
};

class Point {

public:
    int x;
    void print() {
        cout << "x: " << x << "\ty: " << y << "\tz: " << z << endl;
        printZ();
    }

protected:
    int y;

private:
    int z;
    void printZ() {
        cout << "private функция printZ: z: " << z << endl;
    }
};

int main() {

    setlocale(LC_ALL, "ru");

    Point a;
    a.x = 5;

    a.print();

    Human firstHuman;  // экземпляр класса
    firstHuman.name = "Иванов Иван Иванович";
    firstHuman.age = 30;
    firstHuman.weight = 98;
    
    firstHuman.print();

    Human secondHuman;
    secondHuman.age = 10;
    secondHuman.name = "Валентинов Валентин Валентинович";
    secondHuman.weight = 67;

    secondHuman.print();

    return 0;
}
