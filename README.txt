### ESP8266 Wi-Fi Repeater

This guide demonstrates how to configure an ESP8266 microcontroller to function as a Wi-Fi repeater. The device connects to an existing Wi-Fi network and creates a new extended Wi-Fi network, effectively increasing the range of the original network. The ESP8266 operates in both Station Mode (STA) and Access Point (AP) mode simultaneously.

---

### Features

- Connects to an Existing Network:
  - Connects to a primary Wi-Fi network using the provided SSID and Password.

- Creates a Secondary Network:
  - Sets up a new Wi-Fi network (extended network) with its own SSID and Password.
  - Assigns a static IP address to the new network.

- Dual Mode Operation:
  - Operates in both Station Mode (to connect to the existing network) and Access Point Mode (to broadcast the extended network).

- Static IP for Access Point:
  - The access point is assigned the IP address `192.168.4.1`.

---

### Hardware Requirements

- ESP8266 Development Board:
  - Examples: NodeMCU, Wemos D1 Mini, or any other ESP8266-based board.

- USB Cable:
  - For connecting the ESP8266 board to your computer.

- Computer:
  - To upload the code and monitor the serial output.

- Wi-Fi Network:
  - A functional Wi-Fi network to extend.

---

### Software Requirements

- Arduino IDE:
  - Install the Arduino IDE to write and upload the code to the ESP8266 board.

- ESP8266 Board Package:
  - Add the ESP8266 board package to the Arduino IDE.

- Drivers:
  - Ensure you have the necessary drivers installed for your ESP8266 board.

---

### Configuration

1. Replace `Your_Existing_Network_SSID` and `Your_Existing_Network_Password` in the code with your primary Wi-Fi network's credentials.
2. Replace `Extended_Network_SSID` and `Extended_Network_Password` with the desired credentials for the extended network.

---

### Step-by-Step Guide

#### Step 1: Install Software

1. Download and install the Arduino IDE from [arduino.cc](https://www.arduino.cc).
2. Open the Arduino IDE and navigate to **File > Preferences**.
3. In the **Additional Board Manager URLs** field, add:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. Go to **Tools > Board > Boards Manager**, search for "ESP8266," and install the package.

#### Step 2: Set Up the Hardware

1. Connect your ESP8266 board to your computer using a USB cable.
2. Ensure the board is powered and detected by your computer.

#### Step 3: Write the Code

1. Open the Arduino IDE.
2. Copy and paste the following code into a new sketch:

   ```cpp
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
     
     Serial.print("Access Point ");
     Serial.print(extendedSSID);
     Serial.println(" started.");
     
     Serial.print("IP address of AP: ");
     Serial.println(WiFi.softAPIP());
   }

   void loop() {
     // In this example, the loop function is empty.
     // All handling is done in setup. You might want to implement additional functionality.
   }
   ```

3. Replace the placeholders with your network credentials.

#### Step 4: Upload the Code

1. Select the correct board and port in the Arduino IDE:
   - Go to **Tools > Board** and select `NodeMCU 1.0 (ESP-12E Module)` or the appropriate board.
   - Go to **Tools > Port** and select the port your ESP8266 is connected to.
2. Click the **Upload** button to upload the code to the ESP8266.

#### Step 5: Test the Setup

1. Open the Serial Monitor in the Arduino IDE (set the baud rate to 115200).
2. Observe the following output:
   ```
   Connecting to Your_Existing_Network_SSID...
   Connected to the existing network.
   Access Point "Extended_Network_SSID" started.
   IP address of AP: 192.168.4.1
   ```
3. Use another device to connect to the extended network using the `Extended_Network_SSID` and `Extended_Network_Password`.

---

### Notes

- **Static IP**: The access point is assigned the IP `192.168.4.1` by default. You can change this in the code if needed.
- **Security**: Use strong passwords for both the primary and extended networks to prevent unauthorized access.
- **Range**: The range of the extended network depends on the ESP8266's Wi-Fi capabilities, which are typically sufficient for small to medium areas.
- **Further Customization**: You can add features like a web server to monitor or control the repeater functionality.

---

### Troubleshooting

- **Unable to Connect**:
  - Ensure the primary network credentials are correct.
  - Check if the ESP8266 is in range of the primary network.

- No Serial Output:
  - Confirm the correct port and board are selected in the Arduino IDE.

---

This document provides a structured approach to setting up an ESP8266 as a Wi-Fi repeater. Follow each step carefully for a successful implementation.

