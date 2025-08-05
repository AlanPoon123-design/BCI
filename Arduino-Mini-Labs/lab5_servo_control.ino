// Lab 5: Control Servo Motor with Potentiometer

#include <Servo.h>

Servo myServo;  // Create Servo object

void setup() {
  myServo.attach(9);     // Connect servo signal wire to pin 9
  pinMode(A0, INPUT);    // Set A0 as analog input (potentiometer)
}

void loop() {
  int potValue = analogRead(A0);               // Read potentiometer (0–1023)
  int angle = map(potValue, 0, 1023, 0, 180);   // Map value to servo angle (0–180)
  myServo.write(angle);                        // Rotate servo to calculated angle
  delay(10);                                   // Smooth movement
}
