// Lab 1: Blink an LED

void setup() {
  pinMode(13, OUTPUT); // Set pin 13 as output for LED
}

void loop() {
  digitalWrite(13, HIGH); // Turn LED ON
  delay(1000);            // Wait for 1 second
  digitalWrite(13, LOW);  // Turn LED OFF
  delay(1000);            // Wait for 1 second
}
