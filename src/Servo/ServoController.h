#ifndef ServoController_h
#define ServoController_h

#include <iostream>

class ServoController{
public:
    static const std::string COMMAND; 
    static void rotate(double angle);
};

#endif