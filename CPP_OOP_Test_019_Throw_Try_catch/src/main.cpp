/*
Throw - проброс исключений
*/

#include <iostream>
#include <string>
using namespace std;

void foo(int value)
{
  if (value < 0)
  {
    // throw value;
    // throw "Число меньше 0!!!";

    // throw exception("ERROR");

    // У exception нет конструктора для строкового значения, в VS используется
    // расширение MSVC которое позволяет это делать. Чтобы передать строковое
    // значение используют runtime_error или logic_error.
    // писать: throw runtime_error("ERROR");
    // или: throw logic_error("ERROR");
    throw runtime_error("Число меньше 0!!!");
  }

  cout << "Переменная = " << value << endl;
}

int main()
{
  setlocale(LC_ALL, "ru");

  try
  {
    foo(-15);
  }
  // catch (const int ex)  // из foo бросается целое число
  // catch (const char *ex)  // из foo бросается строка
  catch (exception &ex)
  {
    // cout << "Поймано исключение " << ex << endl;
    cout << "Поймано исключение " << ex.what() << endl;
  }

  
  return 0;
}
