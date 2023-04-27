#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>

class Students {
    public:
        Students() {

        }

        Students(int default_points) {
            name = "Неизвестно";
            last_name = "Неизвестно";
            for (int i = 0; i < 5; i++) {
                scores[i] = default_points;
            }
        }

        ~Students() {
            std::cout << "Память была очищена. Всего хорошего." << std::endl;
        }

        void set_name(std::string student_name);
        std::string get_name();
        void set_last_name(std::string student_last_name);
        std::string get_last_name();
        void set_scores(int students_points[]);
        void set_GPA(float point);
        float get_GPA();
        int get_scores(int index);

    private:
        int scores[5];
        float GPA;  // grade_point_average
        std::string name;
        std::string last_name;
};
