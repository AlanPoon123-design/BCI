// Lab 4: Control LED Brightness with Potentiometer

void setup() {
  pinMode(A0, INPUT);   // Set A0 as analog input (potentiometer)
  pinMode(9, OUTPUT);   // Set pin 9 as PWM output (LED)
}

void loop() {
  int potValue = analogRead(A0);                // Read potentiometer value (0–1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // Map to PWM range (0–255)
  analogWrite(9, brightness);                   // Set LED brightness
  delay(10);                                    // Short delay for smoother response
}
