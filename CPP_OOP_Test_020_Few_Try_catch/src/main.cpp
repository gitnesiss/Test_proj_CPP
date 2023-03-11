/*
Несколько Try catch
*/

#include <iostream>
#include <string>
using namespace std;

void foo(int value)
{
  if (value < 0)
  {
    // throw runtime_error("Число меньше 0!!!");
    throw "Число меньше 0!";
  }

  if (value == 0)
  {
    throw runtime_error("Число равно 0!");
  }

  if (value == 1)
  {
    throw 1;
  }

  cout << "Переменная = " << value << endl;
}

int main()
{
  setlocale(LC_ALL, "ru");

  try
  {
    foo(1);
  }
  catch (exception &ex)
  {
    cout << "Блок catch №1: Поймано исключение: " << ex.what() << endl;
  }
  catch (const char *ex)
  {
    cout << "Блок catch №2: Поймано исключение: " << ex << endl;
  }
  catch (...)
  {
    cout << "Блок catch №3: Что-то пошло не так. " << endl;
  }

  return 0;
}
