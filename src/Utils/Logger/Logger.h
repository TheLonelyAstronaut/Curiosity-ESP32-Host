#ifndef Logger_h
#define Logger_h

#include <iostream>

class Logger {
public:
    static inline void configure() {
        Serial.begin(115200);
	    Serial.setDebugOutput(true);
    }

    static inline void log(char* string) {
        Serial.println(string);
    }

    static inline void log(std::string _string) {
        Serial.println(_string.c_str());
    }
};

#endif