#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

#include <iostream>

const int TIME_STEP {64};
const double MAX_SPEED {6.28};
const double WHEEL_RADIUS {0.02};
const double AXLE_LENGTH {0.052};

int main(int argc, char **argv) {

  webots::Robot Rowdy {};

  // Getting the Motors  
  webots::Motor* lMotor {Rowdy.getMotor("left wheel motor")};
  webots::Motor* rMotor {Rowdy.getMotor("right wheel motor")};
  
  // Getting the Motor Position Sensors
  webots::PositionSensor* lEncoder {lMotor->getPositionSensor()};
  webots::PositionSensor* rEncoder {rMotor->getPositionSensor()};
  lEncoder->enable(TIME_STEP);
  rEncoder->enable(TIME_STEP);  
  
  // Position Control
  /* lMotor->setPosition(10.0)
  rMotor->setPosition(10.0); */
  lMotor->setPosition(INFINITY);
  rMotor->setPosition(INFINITY);
  
  // Velocity Control
  lMotor->setVelocity(0.8 * MAX_SPEED);
  rMotor->setVelocity(0.3 * MAX_SPEED);
  
  // Printing the position values while robot moves
  while (Rowdy.step(TIME_STEP) != -1) {
    double lPos {lEncoder->getValue()};
    double rPos {rEncoder->getValue()};
    double angle {(rPos - lPos) * (WHEEL_RADIUS / AXLE_LENGTH)};
    double displacement {(lPos + rPos) * (WHEEL_RADIUS / 2)};
    
    std::cout << lPos << "  " << rPos << "  " << angle << "  " << displacement << std::endl;
  }


  return 0;
}
