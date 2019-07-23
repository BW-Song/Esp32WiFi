# 1 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino"
# 1 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino"
// #include <Preferences.h>
// #include "SD.h"
# 4 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino" 2
// #include "FS.h"
// #include <M5Stack.h>
# 7 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino" 2
# 8 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino" 2

# 10 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino" 2
# 11 "c:\\Users\\t-bosong\\Documents\\code\\ESP32\\WriteToEEPROM\\Device\\device.ino" 2

// Preferences prefs;
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // prefs.begin("Settings");
  // String WiFiSSID = "HUAWEI P9 song";
  // String WiFiPassword = "dongsong0802";
  // String ConStr = "HostName=bwsong-test.azure-devices.net;DeviceId=ESP32;SharedAccessKey=EfVJ6UZsd30wOlC4KN+ywlI4YWQcjrNdh6VmzDA12Ms=";
  // prefs.putString("WiFiSSID",WiFiSSID);
  // prefs.putString("WiFiPassword",WiFiPassword);
  // prefs.putString("ConStr",ConStr);

  // String WiFiSSID, WiFiPassword, ConStr;
  // WiFiPassword = prefs.getString("WiFiPassword");
  // WiFiSSID = prefs.getString("WiFiSSID");
  // ConStr = prefs.getString("ConStr");
  // Serial.println("WiFiSSID:");
  // Serial.println(WiFiSSID);
  // Serial.println("WiFiPassword:");
  // Serial.println(WiFiPassword);
  // Serial.println("ConStr:");
  // Serial.println(ConStr);

  // WiFi.mode(WIFI_AP_STA);
  // WiFi.beginSmartConfig();
  // Serial.println("Waiting for SmartConfig.");
  // while (!WiFi.smartConfigDone()) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("");
  // Serial.println("SmartConfig received.");

  WiFiManager wifiManager;
  // wifiManager.resetSettings();
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.autoConnect("ESP32-WiFiConfig", "AzureSet");
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:

}
