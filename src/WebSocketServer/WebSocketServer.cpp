#include "WebSocketServer.h"

WebSocketServer::WebSocketServer()
{
    this->ws = new AsyncWebSocket("/ws");
    this->server = new AsyncWebServer(82);
    this->ws->onEvent(WebSocketServer::onEvent);
    this->server->addHandler(this->ws);
}

void WebSocketServer::start()
{
    this->server->begin();
}

void WebSocketServer::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) 
{
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            WebSocketServer::handleWebSocketMessage(arg, data, len);
            break;
        case WS_EVT_PONG:
        case WS_EVT_ERROR:
            break;
  }
}

void WebSocketServer::handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;

        if (strcmp((char*)data, "toggle") == 0) {
           
        }
  }
}