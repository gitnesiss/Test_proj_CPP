#include <string>
#include "students.h"

void Students::set_name(std::string student_name) {
    Students::name = student_name;
}

std::string Students::get_name() {
    return Students::name;
}

void Students::set_last_name(std::string student_last_name) {
    Students::last_name = student_last_name;
}

std::string Students::get_last_name() {
    return Students::last_name;
}

void Students::set_scores(int students_scores[]) {
    for (int i = 0; i < 5; i++) {
        Students::scores[i] = students_scores[i];
    }
}

void Students::set_GPA(float point) {  // set_grade_point_average
    Students::GPA = point;
}

float Students::get_GPA() {
    return Students::GPA;
}

int Students::get_scores(int index) {
    return Students::scores[index];
}
