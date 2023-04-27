#include <iostream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));  // вызывается один раз в начале программы

    int a = rand() % 10;  // от 0 до 10
    cout << a << endl;

    int b = rand() % 11 + 5;  // от 5 до 16
    cout << b << endl;

    // Заполнение массива псевдослучайными числами
    int const SIZE = 10;
    int arr[SIZE]{};

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 20;
        cout << "arr[" << i << "]="<< arr[i] << "  ";
    }
    cout << endl;

    return 0;
}
