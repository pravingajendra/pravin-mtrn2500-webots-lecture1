#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

const int TIME_STEP {64};
const double MAX_SPEED {6.28};

int main(int argc, char **argv) {

  webots::Robot Rowdy {};
  
  webots::Motor* lMotor {Rowdy.getMotor("left wheel motor")};
  webots::Motor* rMotor {Rowdy.getMotor("right wheel motor")};
  
  // lMotor->setPosition(10.0)
  // rMotor->setPosition(10.0);

  lMotor->setPosition(INFINITY);
  rMotor->setPosition(INFINITY);
  
  lMotor->setVelocity(0.1 * MAX_SPEED);
  rMotor->setVelocity(0.1 * MAX_SPEED);
  
  while (Rowdy.step(TIME_STEP) != -1) {
  
  }


  return 0;
}
