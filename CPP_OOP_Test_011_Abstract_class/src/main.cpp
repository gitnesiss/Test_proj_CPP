/*

Абстрактный класс

*/

#include <iostream>
#include <ctime>

using namespace std;

class Weapon  // абстрактный класс
{
public:
    // чистый виртуальный метод - не имеющий реализации
    virtual void shoot() = 0;  // = 0 - говорит о том что это только чистая виртуальная функция
    // обычный метод тоже реализуется во всех наследуемых классах
    void foo()
    {
        cout << "Запуск метода foo()" << endl;
    }
};

class Gun : public Weapon
{
public:
    // virtual - позволяет в классе наследнике переопределить функцию - полиморфимзм
    void shoot() override  // этот метод будет переопределяться
    {
        cout << "BANG!" << endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void shoot() override // метод переопределяется
    {
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka : public Weapon
{
public:
    void shoot() override  // метод переопределяется
    {
        cout << "BAAADAAABUUUUUUM!" << endl;
    }
};

class Knife : public Weapon
{
public:
    void shoot() override
    {
        cout << "VJUUUUCH!" << endl;
    }
};

class Player
{
public:
    void shoot(Weapon *weapon)
    {
        weapon->shoot();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Gun gun;
    gun.shoot();

    SubmachineGun sgun;
    sgun.shoot();

    Bazooka bgun;

    Gun *weapon = &sgun;
    weapon->shoot();

    Knife knife;
    knife.foo();

    Player player;
    player.shoot(&gun);
    player.shoot(&sgun);
    player.shoot(&bgun);

    player.shoot(&knife);  

    return 0;
}
