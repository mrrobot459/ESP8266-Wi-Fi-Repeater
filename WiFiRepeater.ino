





You said:
how to save this file with which extension 
#include <ESP8266WiFi.h>

// Replace with your existing network credentials
const char* primarySSID = "Your_Existing_Network_SSID";
const char* primaryPassword = "Your_Existing_Network_Password";

// Replace with your desired extended network credentials
const char* extendedSSID = "Extended_Network_SSID";
const char* extendedPassword = "Extended_Network_Password";

// Set up access point IP
IPAddress apIP(192, 168, 4, 1);
IPAddress apSubnet(255, 255, 255, 0);

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  // Connect to the existing Wi-Fi network
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(primarySSID, primaryPassword);
  
  Serial.print("Connecting to ");
  Serial.print(primarySSID);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("Connected to the existing network.");
  
  // Set up the access point
  WiFi.softAP(extendedSSID, extendedPassword);
  WiFi.softAPConfig(apIP, apIP, apSubnet);
  
  Serial.print("Access Point \"");
  Serial.print(extendedSSID);
  Serial.println("\" started.");
  
  Serial.print("IP address of AP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // In this example, the loop function is empty. 
  // All handling is done in setup. You might want to implement additional functionality.
}
