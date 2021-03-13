#include <iostream>
#include "src/WiFi/WiFiController.h";
#include "src/Utils/Logger/Logger.h";
#include "src/Camera/CameraController.h";

std::string _ssid = "1b4077";
std::string _password = "268726006";
unsigned int _baudRate = 115200;
bool _debugEnabled = true;

WiFiController* wifi;
CameraController* camera;

void setup() {
	Logger::configure(_baudRate, _debugEnabled);
	Logger::log("\nStarting application");
	Logger::log("Connecting to WiFi point\n");

	wifi = new WiFiController(_ssid, _password);
	camera = new CameraController();

  	int connectionResult = wifi->connect();

  	if(!connectionResult) {
		Logger::log(WiFiController::WIFI_CONNECTION_SUCCESS);
		Logger::log(wifi->getLocalIP());
  	} else {
		Logger::log(WiFiController::WIFI_CONNECTION_ERROR);
		Logger::log("Exiting...");
		
		return;
	}

	camera->startCamera();
}

void loop() {
  	// put your main code here, to run repeatedly:
	delay(10000);
}
