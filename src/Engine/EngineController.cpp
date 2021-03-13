#include "EngineController.h"
#include "../Utils/Logger/Logger.h"

const std::string EngineController::COMMAND = "engine_move";

void EngineController::move(double speed) {
    Logger::log("Engine moving");
    Logger::log(speed);
}