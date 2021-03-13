#include <iostream>
#include "src/WiFi/WiFiController.h";
#include "src/Utils/Logger/Logger.h";

std::string _ssid = "1b4077";
std::string _password = "268726006";

WiFiController wifi = WiFiController(_ssid, _password);

void setup() {
	Logger::configure();
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
