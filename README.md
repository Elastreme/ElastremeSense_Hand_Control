# Robotic Arm Control Using ElastremeSense Sensors

## Description
This project demonstrates how to use ElastremeSense stretchable strain sensors with Arduino to control a robotic arm with 5 servos. The system consists of two Arduino boards:
- **Arduino Uno**: Reads sensor data, calibrates, and transmits mapped values to the second Arduino.
- **Arduino Nano**: Receives data and controls the robotic arm's servos accordingly.

## Features
- Real-time calibration of sensor input.
- Mapping of sensor values to servo angles.
- Smooth and synchronized robotic arm movements.

## Setup Instructions
1. **Hardware Requirements:**
   - Arduino Uno (for sensor input and transmission).
   - Arduino Nano (for servo control).
   - 5 stretchable strain sensors.
   - 5 servo motors.
   - Breadboards and jumper wires.

2. **Steps:**
   - Upload the code to each Arduino:
     - Arduino Uno: `/arduino-uno-sensor/sensor_control.ino`
     - Arduino Nano: `/arduino-nano-servo/servo_control.ino`
   - Connect the hardware as described in the documentation.
   - Power on the system and follow the calibration steps.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
