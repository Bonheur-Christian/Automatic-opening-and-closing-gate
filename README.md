# 🚗 Arduino Smart Gate Control System

This project is an automated gate system built with Arduino. It uses an ultrasonic sensor to detect approaching vehicles within 20 cm and opens the gate using a servo motor. The system also includes visual and audio indicators (LEDs and a buzzer) to enhance safety and usability.

## 🛠️ Features

- 🚘 Detects objects (e.g., vehicles) within 20 cm
- 🔄 Automatically opens and closes a gate using a servo motor
- 🔵 Blue LED signals active detection
- 🔴 Red LED indicates standby mode
- 🔊 Buzzer sounds while the gate is opening
- 🕒 Automatically closes the gate after a short delay

## 🧰 Components Used

| Component         | Quantity |
|------------------|----------|
| Arduino Uno/Nano | 1        |
| Ultrasonic Sensor  | 1 |
| Servo Motor | 1 |
| Red LED          | 1        |
| Blue LED         | 1        |
| 220Ω Resistors   | 2        |
| Buzzer           | 1        |
| Jumper Wires | 1 |

## 🔌 Pin Configuration

| Component       | Arduino Pin |
|----------------|-------------|
| Ultrasonic Trigger | D2      |
| Ultrasonic Echo    | D3      |
| Red LED (Anode)    | D4      |
| Blue LED (Anode)   | D5      |
| Servo Motor        | D6      |
| Red LED (Cathode)  | D7      |
| Blue LED (Cathode) | D8      |
| Buzzer             | D12     |


## 📋 How It Works

1. The ultrasonic sensor continuously measures distance.
2. If a vehicle is detected within 20 cm:
   - The gate opens using a servo motor.
   - The red LED turns off, blue LED turns on.
   - The buzzer beeps intermittently for 3 seconds.
3. After opening, the gate closes after a delay.
   - The LEDs and buzzer reset to standby mode.

## 📂 Files

- `gate.ino`: Main Arduino sketch that controls the gate logic and hardware components.

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git
