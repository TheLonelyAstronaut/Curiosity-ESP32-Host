#ifndef WebSocketServer_h
#define WebSocketServer_h

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <map>
#include <iostream>

typedef std::map<std::string, void (*)(double)> T_HANDLERS;

class WebSocketServer
{
    AsyncWebServer* server;
    AsyncWebSocket* ws; 
    static T_HANDLERS HANDLERS;  
public:
    WebSocketServer(int _port, char* _path, T_HANDLERS& handlers);
    void start();
    static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
    static void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
};


#endif