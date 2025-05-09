# GestureBasedCommunicatorUsing_IoT
AirGlyph is a gesture-based communication project using an MPU6050 sensor and I2C LCD to display simple messages based on hand tilts.  It’s open source and easy to customize. Made as my 1st-year project. :)

# AirGlyph – Gesture-Based Communication Project 🤝✨

**AirGlyph** is a simple, open-source gesture-based communication system built using an **MPU6050 motion sensor** and an **I2C LCD display**. Developed as part of my 1st-year, 2nd-semester B.Tech (CSE) project, AirGlyph allows users to trigger short phrases like “hello” or “how are you?” by tilting the sensor in specific directions. It’s great for silent communication, accessibility tools, and Arduino beginners interested in working with motion sensors.

---

## 🚀 Features

- Detects tilt gestures using MPU6050’s accelerometer
- Displays mapped phrases on a 16x2 LCD via I2C
- Includes optional gesture actions (commented)
- Beginner-friendly and customizable
- Fully open-source!

---

## 🛠️ Components Used

- Arduino Uno / Nano
- MPU6050 (Accelerometer + Gyroscope)
- I2C 16x2 LCD (typically with address `0x27`)
- Jumper wires and breadboard

---

## 🔌 Wiring Diagram

| MPU6050 Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| SDA         | A4          |
| SCL         | A5          |

| LCD Pin     | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| SDA         | A4          |
| SCL         | A5          |

*Both LCD and MPU6050 share the I2C bus.*

---

## 📄 How It Works

AirGlyph reads accelerometer data from the MPU6050 using the `getMotion6()` function. Based on the tilt of the sensor (`ax`, `ay`, `az` values), it maps gestures to predefined phrases.

For example:

- Tilt forward → **"hello"**
- Tilt left → **"how are you?"**
- Tilt back → **"bye"**
- Tilt right → **"have a great day!"**

Additional gestures like upward/downward face, or quick wrist flicks (gyroscope data), are included in the code but commented out. You can uncomment and tweak the thresholds as needed.

---

## 🧠 Example Code Snippet

```cpp
if (ax > 12000) {
  message = "hello"; // Forward
} else if (ax < -12000) {
  message = "bye"; // Backward
} else if (ay < -12000) {
  message = "how are you?"; // Left
} else if (ay > 12000) {
  message = "have a great day!"; // Right
}

// Optional gestures (commented):
// if (az > 16000) message = "yes";
// if (gx > 15000) message = "stop";
// ...
