# Room Security WhatsApp Notifier 🛡️📱

## Overview 🔍
The **Room Security WhatsApp Notifier** is a motion detection system that uses a **PIR sensor** to monitor your room and send an alert to your phone via **WhatsApp** when motion is detected. This simple and effective solution can enhance your **home security** by notifying you immediately if there is any movement in the monitored area.

## Features ✨
- **PIR Motion Detection**: Detect motion in the room using a PIR sensor. 🏠
- **WhatsApp Notifications**: Get alerts directly on WhatsApp when motion is detected. 📲
- **Customizable Message**: Personalize the message sent when motion is detected. 💬
- **WiFi-Enabled**: Connects to your WiFi to send notifications over the internet. 🌐

## Requirements ⚙️
- **Hardware**:
  - ESP8266 or any compatible WiFi-enabled microcontroller. 💻
  - PIR Motion Sensor. 🔌
  - Jumper wires and breadboard for connections. 🛠️
  
- **Software**:
  - **Arduino IDE** or **PlatformIO** to upload the code. 💻
  - WhatsApp API key (through [CallMeBot](https://www.callmebot.com/)). 🔑

## Installation 🛠️

### 1. Set up WiFi and WhatsApp API
Edit the code to add your **WiFi credentials** and your **WhatsApp API key** as described in the code comments.

### 2. Upload the code
Upload the code to your **ESP8266** board using the **Arduino IDE**. 🚀

### 3. Run the system
Once uploaded, the system will connect to your WiFi network. When motion is detected by the PIR sensor, a WhatsApp message will be sent to the configured phone number. 📲

## How it works ⚡
1. The system continuously monitors the room for motion using the **PIR sensor**. 🚶‍♂️
2. When motion is detected, the **ESP8266** sends an HTTP request to the **CallMeBot API** with the message "Someone came!" (or a custom message) via WhatsApp. 📡
3. The message is delivered to the designated phone number through WhatsApp. 📲

## Possible Improvements 🔧
- **Add More Sensors**: Integrate additional PIR sensors for monitoring multiple rooms. 🏠
- **Customize Alerts**: Modify the code to allow more customizable messages, including different alerts for specific scenarios. 🎨
- **Send Video or Photo Alerts**: Integrate a camera module to capture images or video when motion is detected. 📷
- **Web Interface**: Add a web interface to manage settings and monitor motion events. 🌐

## Contribution 🤝
Feel free to contribute by submitting issues or pull requests! 🎉
