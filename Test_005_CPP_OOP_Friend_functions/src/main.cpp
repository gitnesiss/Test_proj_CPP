#include <iostream>
#include <string>
using namespace std;

// Чтобы класс Apple знал о существовании класса Human пока он не объявлен
// определяем класс
class Human;
class Apple;

class Human {
public:
    void TakeApple(Apple &apple);

    void EatApple(Apple &apple) {
            
    }
};

class Apple {
public:
    Apple(int weight, string color) {
        this->color = "Green";
        this->weight = 1;
    }

    friend void Human::TakeApple(Apple &apple);

private:
    int weight;
    string color;

};

void Human::TakeApple(Apple &apple) {
    cout << "TakeApple " << "weight = " << apple.weight << " color = " << apple.color << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    Apple apple(150, "Red");

    Human human;
    human.TakeApple(apple);

    return 0;
}
