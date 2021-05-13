#include <iostream>
#include <map>
#include <Servo.h>
#include "src/WiFi/WiFiController.h"
#include "src/Utils/Logger/Logger.h"
#include "src/Camera/CameraController.h"
#include "src/WebSocketServer/WebSocketServer.h"
#include "src/Servo/ServoController.h"
#include "src/Engine/EngineController.h"

std::string _SSID = "LonelyNetwork";
std::string _password = "268726006";

std::string _hotspotSSID = "RC Car";
std::string _hotspotPassword = "LoginHorizon4";

unsigned int _baudRate = 115200;
bool _debugEnabled = false;

int _asyncWebServerPort = 82;
char* _asyncWebSocketPath = "/ws";

int A1A = 14;
int A1B = 15;

int _servoPin = 2;

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

	wifi = new WiFiController(_SSID, _password);
	//wifi = new WiFiController(_hotspotSSID, _hotspotPassword);
	camera = new CameraController();
	server = new WebSocketServer(_asyncWebServerPort, _asyncWebSocketPath, map);

  	EngineController::setup(A1A, A1B);
  	ServoController::setup(_servoPin);

  	//int connectionResult = wifi->enableHotspot();
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
	/*for(double i=0; i<1; i+=0.1) {
		ServoController::rotate(i);
		delay(15);
	}
	
	for(double i=1; i>0; i-=0.1) {
		ServoController::rotate(i);
		delay(15);
	}*/
}
