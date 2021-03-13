#include "WiFiController.h";
#include <WiFi.h>
#include "../Utils/Logger/Logger.h";

WiFiController::WiFiController(std::string _ssid, std::string _password) 
{
    this->ssid = _ssid;
    this->password = _password;   
}

int WiFiController::connect()
{
    int attempCounter = 0;

    WiFi.begin(this->ssid.c_str(), this->password.c_str());

    for(attempCounter; attempCounter <= 20; ++attempCounter) 
    {
        if(WiFi.status() == WL_CONNECTED)
        {
            char _ip[] = "xxx.xxx.xxx.xxx";  
            WiFi.localIP().toString().toCharArray(_ip, 16);

            this->localIP = _ip;

            return 0;
        }
        
        delay(500);
    }

    return -1;
}

std::string WiFiController::getLocalIP()
{
    return this->localIP;
}