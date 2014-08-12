ESC Controller Library
======================

This arduino library is a Servo library wrapper that allows you to use an ESC controller.
As Servo library is used, the default frequency is 50 hz (which is the common frequency).

With this library you can use a normal ESC (only forward) and FORWARD/BACKWARD ESC.

If you use a normal ESC, you can set the speed from 0 (stop) to 1000 (max speed).
If you use a forward/backward ESC you can set the speed from 0 (stop) to 500 and
specify the direction (forward or backward). Yes, when using forward/backward
ESC the speed range is reduced (because you have 2 directions instead of one).

Methods provided
=================

  ESC(int mode = MODE_FORWARD_ONLY);
  void setSpeed(unsigned int speed);
  void setDirection(int direction);
  void setRunningMode(int mode);
  void detach();
  void attach(int pin);
  
If you are going to use a forward only ESC you dont have to use setDirection and setRunningMode.
In the constructor you can specify the type of ESC (ESC::MODE_FORWARE_ONLY or ESC::MODE_FORWARD_BACKWARD)
but ESC::MODE_FORWARE_ONLY is used by default.

Input data
==========
When using mode ESC::MODE_FORWARE_ONLY the speed range is from 0 to 1000
When using mode ESC::MODE_FORWARD_BACKWARD the speed range is from 0 to 500 and you can specify
the direction ESC::FORWARD or ESC::BACKWARD
