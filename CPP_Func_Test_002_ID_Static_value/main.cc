#include <iostream>

int createPerson();

int main() {
    // Вывод 0
    std::cout << createPerson() << std::endl;

    // Внутри записывает в переменную 1
    createPerson();

    // Вывод 2
    std::cout << createPerson() << std::endl;
    return 0;
}

int createPerson() {
    static int s_personID = 0;
    return s_personID++;
}