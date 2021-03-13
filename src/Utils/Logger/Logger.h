#ifndef Logger_h
#define Logger_h

#include "Arduino.h"
#include <iostream>

class Logger {
public:
    static inline void configure(unsigned int _baud, bool _debug) {
        Serial.begin(_baud);
	    Serial.setDebugOutput(_debug);
    }

    static inline void log(char* _string) {
        Serial.println(_string);
    }

    static inline void log(std::string _string) {
        Serial.println(_string.c_str());
    }

    static inline void log(int _number) {
        Serial.println(_number);
    }

    static inline void log(double _number) {
        Serial.println(_number);
    }
};

#endif