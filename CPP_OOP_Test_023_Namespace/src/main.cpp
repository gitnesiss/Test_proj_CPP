/*
Перечисляемый тип ENUM
*/

#include <iostream>
#include <string>
using namespace std;

namespace coffieMill
{
  void start()
  {
    cout << "Кофемашина запущена!" << endl;
  }
}

namespace juicer
{
  void start()
  {
    cout << "Соковыжималка запущена!" << endl;
  }
}

int main()
{
  setlocale(LC_ALL, "ru");

  coffieMill::start();
  juicer::start();

  return 0;
}
