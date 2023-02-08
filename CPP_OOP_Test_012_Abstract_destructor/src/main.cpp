/*

Абстрактный класс

*/

#include <iostream>
#include <ctime>

using namespace std;

class A
{
public:
    A()
    {
        cout << "Выделение дин. памяти, объект класса А" << endl;
    }
    virtual ~A()
    {
        cout << "Освобождение дин. памяти, объект класса А" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "Выделение дин. памяти, объект класса B" << endl;
    }
    ~B() override
    {
        cout << "Освобождение дин. памяти, объект класса B" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    // B pB;
    
    A *bptr = new B;
    delete bptr;
    // тут происходит утечка

    // A *cptr = new B;



    return 0;
}
