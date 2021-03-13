#include <iostream>
#include "src/WiFi/WiFiController.h";
#include "src/Utils/Logger/Logger.h";

std::string _ssid = "1b4077";
std::string _password = "268726006";
unsigned int _baudRate = 115200;
bool _debugEnabled = true;

WiFiController wifi = WiFiController(_ssid, _password);

void setup() {
	Logger::configure(_baudRate, _debugEnabled);
	Logger::log("\nStarting application");
	Logger::log("Connecting to WiFi point\n");

  	int connectionResult = wifi.connect();

  	if(!connectionResult) {
		Logger::log(WiFiController::WIFI_CONNECTION_SUCCESS);
		Logger::log(wifi.getLocalIP());
  	} else {
		Logger::log(WiFiController::WIFI_CONNECTION_ERROR);
		Logger::log("Exiting...");
		
		return;
	}
}

void loop() {
  	// put your main code here, to run repeatedly:
}
