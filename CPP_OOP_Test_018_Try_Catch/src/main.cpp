/*
Try catch - проверка исключений
*/

#include <iostream>
#include <string>
#include <fstream>
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

  ifstream fin;
  fin.exceptions(ifstream::badbit | ifstream::failbit);

  try
  {
    cout << "Попытка открыть файл!" << endl;
    fin.open(path);
    cout << "Файл успешно открыт!" << endl;
  }
  catch (const std::exception& ex)
  {
    cout << ex.what() << endl;
    cout << "Ошибка открытия файла!" << endl;
  }
  fin.close();

  return 0;
}
