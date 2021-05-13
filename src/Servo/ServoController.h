#ifndef ServoController_h
#define ServoController_h

#include <iostream>
#include <Servo.h>

class ServoController{
    static Servo servo;
    static int _servoPin;
    static int _LEFT_DELTA;
    static int _RIGHT_DELTA;
public:
    static void setup(int pin);
    static const std::string COMMAND; 
    static void rotate(double angle);
};

#endif