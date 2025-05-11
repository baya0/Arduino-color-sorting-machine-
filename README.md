# Arduino-Based Color Sorting Machine (Replicated Project)

This project is a working prototype of a color-sorting machine built using an Arduino Uno and a TCS3200 color sensor. It identifies the color of small objects (like skittles or marbles) and sorts them using servo motors. This project is a replication of an existing idea, built for hands-on learning and implementation of embedded systems.

---

## Components Used

- Arduino Uno
- TCS3200 Color Sensor
- 2 × SG90 Servo Motors
- Breadboard
- Jumper Wires
- Power Supply or USB
- Colored objects (red, green, blue recommended)

---

## How It Works

1. The top servo motor feeds objects one by one to the sensor.
2. The TCS3200 sensor detects the object's color by analyzing light frequency.
3. The Arduino processes the sensor data and classifies the object as red, green, or blue.
4. The bottom servo motor rotates to the correct position to drop the object into the matching bin.

---

## Code

The Arduino `.ino` file is available in the `code` folder. It contains:

- Calibration for red, green, and blue detection.
- Logic to rotate the bottom servo based on detected color.

---

## How to Use

1. Connect components according to the wiring diagram.
2. Upload the provided Arduino code via the Arduino IDE.
3. Place objects in the hopper.
4. Power the Arduino and observe the sorting in action.

---

## What I Learned

- Interfacing sensors and actuators with Arduino
- Working with PWM and servo motor control
- Understanding color sensing and signal processing
- Hardware assembly and troubleshooting

---

## Acknowledgment

This project was built based on an existing online concept. The design and idea are not originally mine, but the entire implementation and assembly were done by me to deepen my practical electronics knowledge.

---

## License

This project is open-source under the [MIT License](LICENSE).
