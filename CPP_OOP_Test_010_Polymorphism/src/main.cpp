/*

Полиморфизм

*/

#include <iostream>
#include <ctime>

using namespace std;

class Gun {
public:
    // virtual - позволяет в классе наследнике переопределить функцию - полиморфимзм
    virtual void shoot() {  // этот метод будет переопределяться
        cout << "BANG!" << endl;
    }
};

class SubmachineGun : public Gun {
public:
    void shoot() override {  // метод переопределяется
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka : public Gun {
public:
    void shoot() override {  // метод переопределяется
        cout << "BAAADAAABUUUUUUM!" << endl;
    }
};

class Player {
public:
    void shoot(Gun *gun) {
        gun->shoot();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Gun gun;
    gun.shoot();

    SubmachineGun sgun;
    sgun.shoot();

    Bazooka bgun;

    Gun *weapon = &sgun;
    weapon->shoot();

    Player player;
    player.shoot(&gun);
    player.shoot(&sgun);
    player.shoot(&bgun);

    return 0;
}
