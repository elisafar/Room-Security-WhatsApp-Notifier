/* Ali Safarli   
Made with AI */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// +international_country_code + phone number
// Portugal +351, example: +351912345678
String phoneNumber = "REPLACE_WITH_YOUR_PHONE_NUMBER";
String apiKey = "REPLACE_WITH_API_KEY";

// PIR sensor pin
const int pirPin = D1;  // Adjust the pin number based on your setup

unsigned long lastMessageTime = 0;  // Timestamp of the last message
const unsigned long messageInterval = 10000;  // 10 seconds in milliseconds

void sendMessage(String message) {
  // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void setup() {
  Serial.begin(115200);

  // Initialize PIR sensor pin
  pinMode(pirPin, INPUT);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if motion is detected
  int motionState = digitalRead(pirPin);

  if (motionState == HIGH) {  // Motion detected
    unsigned long currentTime = millis();

    // Check if enough time has passed since the last message
    if (currentTime - lastMessageTime >= messageInterval) {
      Serial.println("Motion detected!");
      sendMessage("Someone came!");  // Send message
      lastMessageTime = currentTime;  // Update the last message time
    }
  }

  // Add a small delay to avoid excessive checking
  delay(200);
}
