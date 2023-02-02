#include <iostream>
#include <ctime>

using namespace std;

template <typename T, typename T2> void summ(T a, T2 b) {
    cout << a << endl;
    cout << b << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    summ(6, 2);

    summ(2.4, 1.9);

    summ(3, 1.2);

    return 0;
}
