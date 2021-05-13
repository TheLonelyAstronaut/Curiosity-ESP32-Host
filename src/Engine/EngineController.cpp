#include "EngineController.h"
#include "../Utils/Logger/Logger.h"

const std::string EngineController::COMMAND = "engine_move";
int EngineController::A1A;
int EngineController::A1B;

void EngineController::setup(int _A1A, int _A1B) {
    pinMode(_A1A, OUTPUT);
    pinMode(_A1B, OUTPUT);
    delay(500);
    EngineController::A1A = _A1A;
    EngineController::A1B = _A1B;
}

void EngineController::move(double speed) {
    if(speed < 0.4) {
        int calculatedSpeed = (1 - speed) * 50;

        digitalWrite(EngineController::A1A, 0);
        digitalWrite(EngineController::A1B, calculatedSpeed);
    }else if(speed > 0.6) {
        int calculatedSpeed = speed * 50;

        digitalWrite(EngineController::A1A, calculatedSpeed);
        digitalWrite(EngineController::A1B, 0);
    } else {
        digitalWrite(EngineController::A1A, 0);
        digitalWrite(EngineController::A1B, 0);
    }
}