#include "WebSocketServer.h"
#include "../Utils/Logger/Logger.h"

#include <sstream>

T_HANDLERS WebSocketServer::HANDLERS;

WebSocketServer::WebSocketServer(int _port, char* _path, T_HANDLERS& handlers)
{
    WebSocketServer::HANDLERS = handlers;
    
    this->ws = new AsyncWebSocket(_path);
    this->server = new AsyncWebServer(_port);
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
        std::string command = reinterpret_cast<char*>(data);
        std::string key;
        double value;

        try
        {
            std::stringstream stream(command);
            stream >> key;
            stream >> value;
        }
        catch(const std::exception& e)
        {
            Logger::log(e.what());
        }

        auto iterator = WebSocketServer::HANDLERS.find(key);

        if(iterator != WebSocketServer::HANDLERS.end()) {
            (iterator->second)(value);
        } else {
            Logger::log("Unknown command");
        }
    }
}