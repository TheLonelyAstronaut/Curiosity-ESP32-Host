#ifndef Logger_h
#define Logger_h

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
};

#endif