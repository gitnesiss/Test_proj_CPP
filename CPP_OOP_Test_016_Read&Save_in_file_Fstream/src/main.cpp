/*
Чтение и запись в файл С++.

fstream чтение и хранение данных
*/

#include <iostream>
#include <string>
#include <fstream>
// #include <windows.h>  // для винды, чтобы правильно работали русские символы,
                      // записываемые в файл из консоли
using namespace std;

class Point
{
public:
  Point()
  {
    x = y = z = 0;
  }

  Point(int x, int y, int z)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void print()
  {
    cout << "   X: " << x << "   Y: " << y << "   Z: " << z << endl;
  }

  int x;
  int y;
  int z;
};

int main()
{
  setlocale(LC_ALL, "ru");

  string path = "myFile.txt";

  fstream fs;
  fs.open(path, fstream::in | fstream::out | fstream::app);  // in открытие файла на чтение
                                              // | побитовое или
                                              // out - открытие на запись
  if (!fs.is_open())
  {
    cout << "Ошибка открытия файла!" << endl;
  }
  else
  {
    string msg;
    int value;
    cout << "Файл открыт!" << endl;
    cout << "Введите 1 для записи данных в файл:" << endl;
    cout << "Введите 2 для считывания всех сообщений из файла:" << endl;
    cin >> value;
    if (value == 1)
    {
      cout << "Введите ваше сообщение!" << endl;
      // SetConsoleCP(1251);  // для правильного отображения кирилицы в консоли
      cin >> msg;
      fs << msg << "\n";
      // SetConsoleCP(866);  // для правильного отображения кирилицы в консоли
    }
    if (value == 2)
    {
      cout << "Чтение данных из файла!" << endl;
      while (!fs.eof())
      {
        msg = "";
        fs >> msg;
        cout << msg << endl;
      }
    }
  }
  fs.close();
  
  return 0;
}
