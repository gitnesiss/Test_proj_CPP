#include <iostream>
#include <string>
 
int main(int argc, char *argv[]) {
    // Вывод аргументов содержащихся в командной строке
    for (int i = 0; i < argc; i++) {
        std::cout << "Аргумент " << i << ":" << argv[i] << std::endl;
    }

    // Создание строковой переменной и задание ей занчения из 1-ого аргумента командной строки
    std::string str = argv[1];

    // Вывод содержания из строковой переменной
    std::cout << "Полученное значение записано в переменную \"num\" и выведено на экран." << std::endl;
    std::cout << "num = " << str << std::endl;  

    return 0;
}