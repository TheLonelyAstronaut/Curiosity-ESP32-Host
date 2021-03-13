#include "ServoController.h"
#include "../Utils/Logger/Logger.h"

const std::string ServoController::COMMAND = "servo_rotate";

void ServoController::rotate(double angle) {
    Logger::log("Servo rotating");
    Logger::log(angle);
}