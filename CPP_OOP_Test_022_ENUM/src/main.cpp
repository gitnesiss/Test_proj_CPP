/*
Перечисляемый тип ENUM
*/

#include <iostream>
#include <string>
using namespace std;

enum AIRSPEED
{
  STALL_SPEED = 80,
  CRUISING_SPEED = 190,
  MAXIMUM_SPEED = 240
};

class PC
{
public:
  
  enum PCState
  {
    OFF,
    ON,
    SLEEP
  };

  PCState getState() {return state;}
  void setState(PCState state) {this->state = state;}
private:
  PCState state;
};

int main()
{
  setlocale(LC_ALL, "ru");

  PC pc;
  pc.setState(PC::PCState::ON);

  if (pc.getState() == PC::PCState::ON)
  {
    cout << "Компьютер работает!" << endl;
  }

  pc.setState(PC::PCState::SLEEP);
  switch (pc.getState())
  {
    case PC::PCState::OFF:
      cout << "Компьютер выключен!" << endl;
      break;
    case PC::PCState::ON:
      cout << "Компьютер работает!" << endl;
      break;
    case PC::PCState::SLEEP:
      cout << "Компьютер спит!" << endl;
      break;
  }



  AIRSPEED sp = AIRSPEED::MAXIMUM_SPEED;
  cout << sp << endl;

  return 0;
}
