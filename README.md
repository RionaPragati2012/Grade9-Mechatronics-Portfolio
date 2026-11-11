# Grade 9 Mechatronics & Robotics Portfolio 🤖🚀

Welcome to my engineering development space. This repository contains the source code, schematics, and system documentation for mechatronics prototypes built during Grade 9 as part of my pathway toward studying Mechatronics Engineering.

---

## 📁 Project 1: Smart Room Climate & Lighting Controller
An automated, closed-loop environmental control unit that reads real-time sensor data to actuate mechanical systems.

### ⚙️ System Architecture & Wiring
*   **Microcontroller:** Arduino Uno R3
*   **Telemetry Inputs:** DHT11 Temperature & Humidity Sensor, Photoresistor (LDR)
*   **Mechanical Actuator:** SG90 Micro Servo Motor
*   **User Interface:** 16x2 LCD Display via I2C protocol

### 📸 Media Evidence
*   **Circuit Schematic:** `[Link or upload your top-down wiring photo here]`
*   **Video Demo:** `[Link to your YouTube or Google Drive 60-second video demo here]`

### 🧠 Logic Loop Explanation
The firmware monitors environmental variables every 2 seconds. If the ambient temperature crosses a threshold (>24.0°C), the micro-controller triggers a 90-degree servo rotation to open a physical cooling vent flap.

---

## 🏎️ Project 2: Autonomous Obstacle-Avoiding Rover
*(Coming Soon)* A differential-drive robotic rover utilizing proximity mapping algorithms to navigate spaces autonomously.
\\\\\\\\\\\\\\\\\\\\\\\\\\
