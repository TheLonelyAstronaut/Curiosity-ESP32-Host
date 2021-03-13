#ifndef WebSocketServer_h
#define WebSocketServer_h

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class WebSocketServer
{
    AsyncWebServer* server;
    AsyncWebSocket* ws;   
public:
    WebSocketServer();
    void start();
    static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
    static void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
};


#endif