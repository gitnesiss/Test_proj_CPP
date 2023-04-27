#include <iostream>
#include "students.h"
#include "students.cc"

int main() {
    Students *student = new Students;

    std::string name;
    std::string last_name;

    std::cout << "Введите имя учащегося: ";
    getline(std::cin, name);

    std::cout << "Введите фамилию учащегося: ";
    getline(std::cin, last_name);

    student->set_name(name);  // сохранение имени
    student->set_last_name(last_name);  // сохранение фамилии

    int scores[5];  // оценки
    int sum = 0;  // сумма всех оценок

    for (int i = 0; i < 5; i++) {
        std::cout << "Оцека " << i + 1 << ": ";
        std::cin >> scores[i];
        sum += scores[i];
    }
    student->set_scores(scores);

    float GPA = sum / 5.0;
    student->set_GPA(GPA);

    std::cout << "Средний бал учащегося " << student->get_name() << " "
        << student->get_last_name() << " = "
        << student->get_GPA() << std::endl;



    std::cout << std::endl;
    std::cout << "--- --- ---" << std::endl;
    std::cout << std::endl;



    Students *student_2 = new Students(2);
    std::cout << "Оценки учащегося " << student_2->get_name() << " "
        << student_2->get_last_name() << ": " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Оцека " << i + 1 << ": " << student_2->get_scores(i) << std::endl;
    }
    sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student_2->get_scores(i);
    }
    GPA = sum / 5.0;
    student_2->set_GPA(GPA);
    std::cout << "Средний бал учащегося " << student_2->get_name() << " "
        << student_2->get_last_name() << " = "
        << student_2->get_GPA() << std::endl;

    std::cout << std::endl;

    delete student;
    delete student_2;

    return 0;
}
