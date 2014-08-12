#include <Servo.h>

#include "ESC.h"

/* This example shows how to use an ESC controller that can go
 * only forward
 */
ESC esc;

void setup() 
{ 
    esc.attach(9);
    esc.setSpeed(30);
    delay(1000);
    esc.setSpeed(0);
    delay(1000);
    esc.setSpeed(35);
    delay(1000);
    esc.setSpeed(0);  
} 
 
void loop() 
{ 

} 