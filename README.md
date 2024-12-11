# Contactless-Iot-Doorbell

This project is a contactless doorbell system designed to enhance convenience and hygiene in residential and commercial spaces. It uses IoT technology to detect visitors, send notifications, and enable remote interaction with the doorbell.

## Features
- Contactless Ringing: Detects visitors using sensors (e.g., motion or proximity or ultrasonic).
- Smart Notifications: Sends alerts to your phone or other devices when someone rings the bell.
- Two-Way Communication: Allows you to interact with visitors remotely through a mobile app.
- Cloud Integration: Logs doorbell events for security and monitoring.
- Customizable Settings: Adjust sensitivity, notification preferences, and other configurations.

## Technologies Used

### Hardware
- Microcontroller: ESP32/ESP8266 (or any other IoT-compatible board).
- Sensor: Proximity or motion sensor (e.g., PIR, ultrasonic).
- Power Supply: DC adapter or rechargeable battery.

### Software
- Programming Language: C/C++ for microcontroller programming.
- IoT Platform: MQTT, Firebase, or AWS IoT for cloud integration.
- Mobile App: Built using Flutter/React Native for notifications and interaction.
- Backend: Node.js/Express.js (optional) for advanced features.

## How It Works

1. The doorbell detects a visitor using the installed proximity or motion sensor.
2. Upon detection, the system triggers a notification to the connected app via the IoT platform.
3. The user can view the notification, interact with the visitor, or check the event log.

## Installation

### Hardware Setup
1. Connect the sensor to the microcontroller.
2. Power the microcontroller using a reliable power source.
3. Mount the device near your door.

### Software Setup
1. Clone the project repository:
   ```bash
   git clone https://github.com/MuskanVerma07/contactless-doorbell.git
   ```
2. Install the necessary dependencies for microcontroller programming.
3. Flash the code onto the microcontroller using Arduino IDE or PlatformIO.
4. Set up the mobile app by following the instructions in the `mobile-app` folder.

### Cloud Configuration
1. Create an account on your chosen IoT platform (e.g., Firebase, AWS IoT).
2. Configure the database and notification settings.
3. Update the IoT credentials in the microcontroller code.

## Usage

1. Power on the device.
2. Install the mobile app and connect it to the device.
3. Test the system by triggering the sensor and observing the notification.

## Future Improvements
- Add video capabilities for real-time interaction.
- Implement AI-based visitor recognition.
- Expand compatibility with smart home ecosystems (e.g., Alexa, Google Home).
- Include a backup power source for increased reliability.









