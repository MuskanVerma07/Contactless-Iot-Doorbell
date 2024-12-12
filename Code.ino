#include <WiFi.h>
#include <FirebaseESP32.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Firebase credentials
#define FIREBASE_HOST "your-project-id.firebaseio.com"
#define FIREBASE_AUTH "your-firebase-database-secret"

// Pins
const int sensorPin = 12; // PIR sensor pin
const int buzzerPin = 13; // Buzzer pin

// Firebase instance
FirebaseData firebaseData;

// Global variables
bool visitorDetected = false;

void setup() {
  Serial.begin(115200);

  // Initialize pins
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.println("Firebase initialized");
}

void loop() {
  // Check sensor input
  int sensorValue = digitalRead(sensorPin);
  if (sensorValue == HIGH && !visitorDetected) {
    visitorDetected = true;
    Serial.println("Visitor detected!");

    // Trigger buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);

    // Send notification to Firebase
    sendNotification();
  }

  // Reset visitor detection
  if (sensorValue == LOW) {
    visitorDetected = false;
  }

  delay(100);
}

void sendNotification() {
  // Prepare JSON payload
  StaticJsonDocument<200> doc;
  doc["message"] = "Visitor detected at the door";
  doc["timestamp"] = millis();

  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);

  // Push notification to Firebase
  if (Firebase.pushJSON(firebaseData, "/doorbell/notifications", doc)) {
    Serial.println("Notification sent!");
  } else {
    Serial.print("Failed to send notification: ");
    Serial.println(firebaseData.errorReason());
  }
}
