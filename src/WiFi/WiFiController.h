#ifndef WiFiController_h
#define WiFiController_h

#include <iostream>

class WiFiController 
{
    std::string localIP;
    std::string ssid;
    std::string password;
public:
    static constexpr char* WIFI_CONNECTION_ERROR = "Unadble to connect to the network!";
    static constexpr char* WIFI_CONNECTION_SUCCESS = "Connected to the network!";

    WiFiController(std::string _ssid, std::string _password);
    int connect();
    std::string getLocalIP();
};
#endif