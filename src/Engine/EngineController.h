#ifndef EngineController_h
#define EngineController_h

#include <iostream>

class EngineController{
public:
    static const std::string COMMAND; 
    static void move(double speed);
};

#endif