/*
Работа с файлами C++. Запись в файл. C++ ofstream.

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


int main()
{
  setlocale(LC_ALL, "ru");

  string path = "myFile.txt";
  ifstream fin;
  fin.open(path);
  if (!fin.is_open()) {
    cout << "Ошибка открытия файла!" << endl;
  } else {
    cout << "Файл открыт!" << endl;
    
    // // Файл считывается по символьно
    // char ch;
    // while (fin.get(ch))  // Считывание пока есть символы
    // {
    //   cout << ch;
    // }
    // cout << endl;

    // Файл считывается по строчно
    string str;
    // char str_ch[50];

    while (!fin.eof())  // Считывание пока не конец файла
    {
      str = "";    // очистить строку, чтобы он не выводил лишние символы если
                   // в конце файла стоит переход на новую строку.
      // fin >> str;  // >> оператор считывает до первого пробела (до " " или  \n)
      // cout << str << endl;

      getline(fin, str);  // getline из пространства имён std:: , пропускает
                          // пробелы идя до \n или eof
                          // первый элемент - откуда считывать
                          // второй параметр - куда записывать
      cout << str << endl;

      // fin.getline(str_ch, 50);  // откуда записывать и сколько символов брать,
      //                           // работает с char, нужно следить за размерами
      //                           // массивами
      // cout << str_ch << endl;
    }

  }
  fin.close();

  return 0;
}
