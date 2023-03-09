/*
Запись объекта класса в файл С++. Чтение объекта из файла С++.

Сохранение данных.

fstream основные классы: 
fstream  - класс, хранящий функционал для записи и чтения данных
ifstream - (input file stream) - чтение данных из файла
ofstream - (output file stream) - запись (сохранение) данных в файл
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
  
  // Point point(124, 625, 917);
  // point.print();

  // ofstream fout;
  // // fout.open(path);  // Сюда записать или адрес или имя файла, который
  //                   // будет сохранён в папке проекта
  //                   // Перезаписывает существующий файл
  // fout.open(path, ofstream::app);  // данные будут дописываться в файл
  // if (!fout.is_open()) {
  //   cout << "Ошибка открытия файла." << endl;
  // } else {
  //   cout << "Запись объекта в файл" << endl;
  //   fout.write((char*)&point, sizeof(Point));  // в качетстве параметров
  //                                       // принимает объект и размер объекта
  // }
  // fout.close();

  ifstream fin;
  fin.open(path);
  if (!fin.is_open()) 
  {
    cout << "Ошибка открытия файла!" << endl;
  }
  else 
  {
    cout << "Файл открыт!" << endl;
    Point pnt;
    while (fin.read((char*)&pnt, sizeof(Point)))
    {
      pnt.print();
    }
  }
  fin.close();

  return 0;
}
