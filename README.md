# Curiosity ESP32 Host
ESP32 Host for WiFi/Bluetooth controlled car.

Used libraries:
- WiFi
- AsyncTCP
- ESPAsyncWebServer
- ESP32 STL

## Start instructions:
- Install all necessary drivers for FTDI232 or analog
- Install ESP32 lib for Arduino IDE
- Connect ESP32-CAM to PC with FTDI232/etc.
- Open sketch in Arduino IDE, in Tools choose "ESP32 Wrover Module" on "board" section and "Huge APP" on "Partition Scheme"
- Flash
- Open COM monitor, choose 115200 baud rate, restart board and copy IP Address

## Usage
You can test connection with mobile app (in development) or with html page (in the root of repository, change hardcoded IP address in html to address from COM monitor)