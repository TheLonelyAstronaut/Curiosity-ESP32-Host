#include <iostream>
#include <map>
#include "src/WiFi/WiFiController.h"
#include "src/Utils/Logger/Logger.h"
#include "src/Camera/CameraController.h"
#include "src/WebSocketServer/WebSocketServer.h"
#include "src/Servo/ServoController.h"
#include "src/Engine/EngineController.h"

std::string _ssid = "1b4077";
std::string _password = "268726006";
unsigned int _baudRate = 115200;
bool _debugEnabled = true;
int _asyncWebServerPort = 82;
char* _asyncWebSocketPath = "/ws";

WiFiController* wifi;
CameraController* camera;
WebSocketServer* server;

void setup() {
	Logger::configure(_baudRate, _debugEnabled);
	Logger::log("\nStarting application");
	Logger::log("Connecting to WiFi point\n");

	T_HANDLERS map;

	map.insert(std::pair<std::string, void (*)(double)>(ServoController::COMMAND, ServoController::rotate));
	map.insert(std::pair<std::string, void (*)(double)>(EngineController::COMMAND, EngineController::move));

	wifi = new WiFiController(_ssid, _password);
	camera = new CameraController();
	server = new WebSocketServer(_asyncWebServerPort, _asyncWebSocketPath, map);

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
	server->start();
}

void loop() {
  	// put your main code here, to run repeatedly:
	delay(10000);
}
