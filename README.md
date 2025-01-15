# DIY Arduino Quadruped Robot

A lightweight, affordable quadruped robot powered by Arduino Nano and ESP32, featuring ultrasonic sensing capabilities. This project aims to provide an accessible entry point into robotics and programming through a DIY approach.

![Quadruped Robot](robot-image-placeholder.jpg)

## Features

- 8-DOF quadruped design (2 servos per leg)
- Wireless control through ESP32 access point
- Obstacle detection using ultrasonic sensor
- Custom PCB design for component integration
- Arduino Nano-based control system
- Lightweight and modular construction

## Prerequisites

### Hardware Components

- 1× Arduino Nano
- 1× ESP32 development board
- 8× SG90 servo motors (or compatible)
- 1× HC-SR04 ultrasonic sensor
- 1× Custom PCB (Gerber files provided)
- Chassis components (laser-cut or 3D printed)
- M3 screws and nuts
- Jumper wires
- LiPo battery (7.4V recommended)
- Servo power supply module

### Tools Required

- Soldering iron and solder
- Screwdriver set
- Wire strippers
- Hot glue gun
- Basic electronic tools

### Software Requirements

- Arduino IDE
- Required Libraries:
  - Servo.h
  - ESP32WiFi.h
  - NewPing.h

## Assembly Instructions

### 1. Chassis Assembly

1. Cut or 3D print the chassis components using provided files
2. Assemble the base frame using M3 screws
3. Attach servo motors to each leg mount point
4. Secure the leg segments to servo horns

### 2. Electronics Assembly

1. Solder components to the custom PCB:
   - Arduino Nano headers
   - ESP32 headers
   - Servo connectors
   - Power distribution
2. Connect servo motors to designated ports
3. Mount ultrasonic sensor at the front
4. Install power supply module

### 3. Wiring Guide

```
Arduino Nano Connections:
- D2-D9: Servo control signals
- D10: Ultrasonic TRIG
- D11: Ultrasonic ECHO
- A4: SDA (ESP32 communication)
- A5: SCL (ESP32 communication)

ESP32 Connections:
- GPIO21: SDA
- GPIO22: SCL
- GPIO16: Status LED
```

## Software Setup

1. Install Arduino IDE and required libraries
2. Upload provided code:
   - `quadruped_control.ino` to Arduino Nano
   - `esp32_wireless.ino` to ESP32

### Initial Configuration

```cpp
// WiFi credentials in esp32_wireless.ino
const char* ssid = "QuadrupedBot";
const char* password = "robotics123";
```

## Usage

1. Power on the robot
2. Connect to the ESP32's WiFi network
3. Access control interface at `192.168.4.1`
4. Available commands:
   - Forward/Backward movement
   - Left/Right turns
   - Stand/Sit positions
   - Obstacle avoidance mode

## Troubleshooting

Common issues and solutions:

1. Erratic servo movement
   - Check power supply voltage
   - Verify servo connections
   - Calibrate servo positions in code

2. WiFi connection issues
   - Reset ESP32
   - Verify credentials
   - Check signal strength

## Contributing

1. Fork the repository
2. Create a feature branch
3. Submit a pull request

## License

This project is licensed under the MIT License - see LICENSE file for details.

## Acknowledgments

- Inspired by various open-source robotics projects
- Thanks to the Arduino and ESP32 communities

## Project Status

Currently in active development. New features and improvements are welcome through pull requests.

## Contact

For questions or suggestions, please open an issue in the repository.