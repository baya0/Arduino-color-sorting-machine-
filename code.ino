#include <Servo.h>

// Define servo objects
Servo feederServo;   // Pushes the object in front of the sensor
Servo sorterServo;   // Rotates to drop the object in the right bin

// Color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Attach servos to digital pins
  feederServo.attach(9);   // Connected to the feeder servo
  sorterServo.attach(10);  // Connected to the sorter servo

  // Set pin modes for the sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set scaling frequency to 20% (you can adjust for accuracy)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Start serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Push the object in front of the sensor
  feederServo.write(90);   // Push position
  delay(1000);
  feederServo.write(0);    // Return to default
  delay(500);

  // Read RGB values
  redFrequency = getColorFrequency(LOW, LOW);    // Red
  greenFrequency = getColorFrequency(HIGH, HIGH); // Green
  blueFrequency = getColorFrequency(LOW, HIGH);   // Blue

  Serial.print("R: "); Serial.print(redFrequency);
  Serial.print(" | G: "); Serial.print(greenFrequency);
  Serial.print(" | B: "); Serial.println(blueFrequency);

  // Simple decision logic (you may calibrate these values)
  if (redFrequency < greenFrequency && redFrequency < blueFrequency) {
    sortTo("Red");
    sorterServo.write(45);  // Position 1: red bin
  } 
  else if (greenFrequency < redFrequency && greenFrequency < blueFrequency) {
    sortTo("Green");
    sorterServo.write(90);  // Position 2: green bin
  } 
  else {
    sortTo("Blue");
    sorterServo.write(135); // Position 3: blue bin
  }

  delay(1500); // Wait before next object
}

// Helper function to get color frequency
int getColorFrequency(bool s2Val, bool s3Val) {
  digitalWrite(S2, s2Val);
  digitalWrite(S3, s3Val);
  delay(50);  // Let the sensor stabilize
  return pulseIn(sensorOut, LOW);
}

// Optional: print the detected color
void sortTo(String color) {
  Serial.print("Detected Color: ");
  Serial.println(color);
}
