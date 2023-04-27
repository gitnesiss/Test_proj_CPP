#include <iostream>
 
int main() {

    int *a = new int;
    int *b = new int(4);

    *a = 10;
    *b = *a + *b;

    std::cout << "b = " << *b << std::endl;
    std::cout << "b = " << &b << std::endl;

    delete b;
    delete a;

    int num;  // размер массива
    std::cout << "Ведите целое значение: ";
    std::cin >> num;  // получение от пользователя размера массива

    int *p_arr = new int[num];  // выделение памяти для массива
    for (int i = 0; i < num; i++) {
        p_arr[i] = i;
        std::cout << "Значение " << i << " у элемента p_arr[" << p_arr[i] << "]" << std::endl;
    }
    delete [] p_arr;

    return 0;
}