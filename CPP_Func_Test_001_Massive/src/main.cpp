#include <iostream>
using namespace std;

int main() {
    int arr_1[4];
    arr_1[0] = 5;
    cout << arr_1[0] << endl;

    int arr_2[8]{};
    for (int i = 0; i < 8; i++) {
        cout << "arr_2[" << i << "]="<< arr_2[i] << "  ";
    }
    cout << endl << endl;

    for (int i = 0; i < (int)sizeof(arr_2)/(int)sizeof(arr_2[0]); i++) {
        arr_2[i] = i;
        cout << "arr_2[" << i << "]="<< arr_2[i] << "  ";
    }
    cout << endl << endl;

    cout << "int =    " << sizeof(int) << " байта" << endl;
    cout << "float =  " << sizeof(float) << " байта" << endl;
    cout << "double = " << sizeof(double) << " байт" << endl;
    cout << "char   = " << sizeof(char) << " байт" << endl;
    cout << "bool   = " << sizeof(bool) << " байт" << endl;
    return 0;
}
