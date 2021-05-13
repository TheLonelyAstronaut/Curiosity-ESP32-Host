#ifndef EngineController_h
#define EngineController_h

#include <iostream>

class EngineController{
    static int A1A;
    static int A1B;
public:
    static void setup(int _A1A, int _A1B);
    static const std::string COMMAND; 
    static void move(double speed);
};

#endif