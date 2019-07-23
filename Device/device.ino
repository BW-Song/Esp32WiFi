#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <WiFiManager.h>

WiFiManager wifiManager;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // wifiManager.resetSettings();
  wifiManager.autoConnect("ESP32-WiFiConfig", "AzureSet");
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
}
