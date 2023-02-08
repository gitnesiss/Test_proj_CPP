/*
Наследование.

Начальный класс (от которого наследуются) - родительский или базовый
Унаследованный класс (который наследуется от родительского) - дочерний, производный, потомок, наследник

*/

#include <iostream>
#include <ctime>

using namespace std;

class Human {
public:
    string name = "Иван";

    string getSecondName() {
        return secondName;
    }

    void setName(string name) {
        this->name = name;
    }
private:
    string secondName = "Веселов";
};

class Student : public Human {
public:
    string group;
    void learn() {
        cout << "Я учусь!" << endl;
    }
};

class ExtramuralStudent : Student {  // студент заочник
public:
    void learn() {
        cout << "Я учусь на заочном!" << endl;
    }
};

class Professor : public Human {
public:
    string subject;
};

int main() {
    setlocale(LC_ALL, "ru");

    Human h;
    cout << "Имя " << h.name << endl;

    Student stud;
    stud.learn();
    stud.setName("Никита");
    cout << "Имя " << stud.name << endl;
    cout << "Фамилия " << stud.getSecondName() << endl;

    ExtramuralStudent extraSt;
    extraSt.learn();

    return 0;
}
