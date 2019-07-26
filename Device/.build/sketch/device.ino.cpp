#include <Arduino.h>
#line 1 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
#line 1 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <WiFiManager.h>
#include <Preferences.h>

WiFiManager wifiManager;
char* connectionString;
Preferences preferences;
WiFiManagerParameter conStr("ConnectionString","ConnectionString",connectionString,40);

#line 12 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
void saveConfigCallback();
#line 29 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
void setup();
#line 42 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
void loop();
#line 12 "c:\\Users\\t-bosong\\Documents\\GitHub\\Esp32WiFi\\Device\\device.ino"
void saveConfigCallback()
{
  // Serial.println(wifiManager.getSSID());
  // Serial.println(wifiManager.getPassword());
  // Serial.println(conStr.getValue());
  preferences.putString("WiFi_SSID",wifiManager.getSSID());
  preferences.putString("WiFi_Password",wifiManager.getPassword());
  preferences.putString("ConStr",String(conStr.getValue()));

  const char* s = preferences.getString("WiFi_SSID").c_str();
  Serial.println(s);
  const char* p = preferences.getString("WiFi_Password").c_str();
  Serial.println(p);
  const char* cs = preferences.getString("ConStr").c_str();
  Serial.println(cs);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  preferences.begin("Connections");
  
  wifiManager.resetSettings();
  wifiManager.setDebugOutput(false);
  wifiManager.addParameter(&conStr);
  wifiManager.setSaveParamsCallback(saveConfigCallback);
  wifiManager.autoConnect("ESP32-WiFiConfig", "AzureSet");
  preferences.end();
}

void loop() {
  // put your main code here, to run repeatedly:
}

