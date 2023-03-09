/*
Работа с файлами C++. Чтение из файла  С++ ifstream.

Чтение данных из файла.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
  setlocale(LC_ALL, "ru");

  string path = "myFile.txt";
  // cin >> path;
  ofstream fout;
  // fout.open(path);  // Сюда записать или адрес или имя файла, который
                    // будет сохранён в папке проекта
                    // Перезаписывает существующий файл
  fout.open(path, ofstream::app);
  if (!fout.is_open()) {
    cout << "Ошибка открытия файла." << endl;
  } else {
    fout << "\nЭто мои данные. Запись в файл.";
    cout << "Ввеидете число!" << endl;
    int a;
    cin >> a;
    fout << "\t" << a;
  }
  fout.close();

  return 0;
}
