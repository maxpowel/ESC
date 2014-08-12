/*
 * A simple class for control an ESC controller
 */ 
#include <Servo.h>
#include "ESC.h"

ESC::ESC(int mode){
  actualDirection = FORWARD;
  setRunningMode(mode);
}

void ESC::setSpeed(unsigned int speed)
{
        Serial.println(baseSpeed + speed);
  if(actualDirection == FORWARD){
    if(baseSpeed + speed <= MAX_PULSE)
      esc.writeMicroseconds(baseSpeed + speed);
  }else{
    if(baseSpeed + speed >= MIN_PULSE)
      esc.writeMicroseconds(baseSpeed - speed);
  }
}

void ESC::setRunningMode(int mode){
  if(mode == MODE_FORWARD_ONLY){
      baseSpeed = BASE_FORWARD_ONLY;
  }else if(mode == MODE_FORWARD_BACKWARD){
      baseSpeed = BASE_FORWARD_BACKWARD;
  }
}
void ESC::setDirection(int direction)
{
  if(direction == FORWARD)
    actualDirection = FORWARD;
  else
    actualDirection = BACKWARD;
}

void ESC::detach(){
  esc.detach();
}

void ESC::attach(int pin){
  esc.attach(pin);
  //setSpeed(0);
}