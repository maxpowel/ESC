#ifndef __ESC_H__
#define __ESC_H__

#include <Arduino.h>

//You may need to configure this values
#define BASE_FORWARD_ONLY 1000 //number of pulse microseconds for 0 speed
#define BASE_FORWARD_BACKWARD 1500 //number of pulse microseconds for 0 speed for forward/backward
#define MAX_PULSE 2000
#define MIN_PULSE 1000

/* A normal ESC controller goes only forward
 * 0 speed is a pulse of 1 millisecond (1000 microseconds)
 * max speed is a pulse of 2 milliseconds
 */

/* A forward/backward ESC controller 
 * 0 speed is a pulse of 1.5 millisecond (1500 microseconds)
 * max speed forward is a pulse of 2 milliseconds
 * max speed backward is a 1 millisecond pulse.
 * Backward speed increases when the pulse decreases (from 1499 to 1000)
 */

class ESC
{
private:
  int actualDirection;
  int actualSpeed;
  int baseSpeed;
  Servo esc;
  bool checkSpeed(int speed);
public:
  static const int FORWARD = 0;
  static const int BACKWARD = 1;
  static const int MODE_FORWARD_ONLY = 0;
  static const int MODE_FORWARD_BACKWARD = 1;
  
  ESC(int mode = MODE_FORWARD_ONLY);
  //if only forward ESC, speed range: 0, 1000
  //if forward/backward ESC, speed range: 0, 500
  void setSpeed(unsigned int speed);
  void setDirection(int direction);
  void setRunningMode(int mode);
  void detach();
  void attach(int pin);
};

#endif
