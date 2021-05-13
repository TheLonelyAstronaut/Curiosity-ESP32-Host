#include "ServoController.h"
#include "../Utils/Logger/Logger.h"

const std::string ServoController::COMMAND = "servo_rotate";
int ServoController::_servoPin;
int ServoController::_LEFT_DELTA = 25;
int ServoController::_RIGHT_DELTA = -35;
Servo ServoController::servo;

void ServoController::setup(int pin) {
    ServoController::_servoPin = pin;
    ServoController::servo.attach(pin, 8);
    ServoController::servo.write(90);
}

void ServoController::rotate(double angle) {
    int newAngle = 90; 

    if(angle > 0.6) {
        newAngle = 90 + (angle - 0.5) * ServoController::_RIGHT_DELTA * 2;
    } else if(angle < 0.4) {
        newAngle = 90 + (0.5 - angle) * ServoController::_LEFT_DELTA * 2;
    }

    Logger::log(newAngle);
    ServoController::servo.write(newAngle);
}   