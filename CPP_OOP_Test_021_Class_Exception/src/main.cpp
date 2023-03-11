/*
Создание собственных исключений
*/

#include <iostream>
#include <string>
using namespace std;

class MyException : public runtime_error
{
public:
  MyException(const char *msg, int dataState) : runtime_error(msg)
  {
    this->dataState = dataState;
  }
  int getDataState()
  {
    return dataState;
  }
private:
  int dataState;
};

void foo(int value)
{
  if (value < 0)
  {
    throw runtime_error("Число меньше 0!");
    // throw "Число меньше 0!";
  }
  if (value == 1)
  {
    throw MyException("Число = 1!", value);
  }

  cout << "Переменная = " << value << endl;
}

int main()
{
  setlocale(LC_ALL, "ru");

  try
  {
    // foo(-25);
    foo(1);
  }
  catch (MyException &ex)
  {
    cout << "Блок catch №1: Поймано исключение: " << ex.what() << endl;
    cout << "Состояние данных  = " << ex.getDataState() << endl;
  }
  catch (exception &ex)
  {
    cout << "Блок catch №2: Поймано исключение: " << ex.what() << endl;
  }

  return 0;
}
