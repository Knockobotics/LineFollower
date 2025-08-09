# Line Follower Robot

A compact line-following robot that uses an array of IR reflectance sensors to detect a dark line on a light surface and steer a differential-drive chassis to follow it. Includes basic PID steering for smooth tracking and a simple state machine for intersections and stops.

---

## Features
- 2 IR reflectance sensor array support (e.g., QTR, TCRT5000)
- Differential drive (two motors + motor driver)
- Proportional or PID steering control
- Optional intersection detection and line-loss recovery
- Easy-to-follow wiring and calibration instructions
- Minimal Arduino sketch included

---

## Hardware (example)
- **Microcontroller:** Arduino Uno / Nano / Pro Mini (or ESP32/RPi)
- **Motors:** 2 DC geared motors
- **Motor driver:** L298N, TB6612, or similar
- **Sensors:** 3x QTR-1A / 5x QTR / TCRT5000 sensor strip
- **Power:** 7.4V LiPo or 6x AA battery pack (match motors & driver) || (2 x 9v in our case)
- **Chassis:** 2-wheel differential chassis + caster wheel
- **Misc:** jumper wires, battery connector, mounting hardware

---

## Wiring (typical)
- connect to m1 and m3 for optimal results involving code.
- Left motor → Motor driver channel A (IN1, IN2), enable to PWM pin  
- Right motor → Motor driver channel B (IN3, IN4), enable to PWM pin  
- Sensor array analog/digital outputs → A0..A4 (or digital pins for QTR digital mode)  
- Battery negative → Arduino GND; Battery positive → Motor driver VIN (do **NOT** feed high battery directly into Arduino VIN)  
- Connect all grounds (motor driver, Arduino, sensors) together

Example pin mapping (Arduino):
