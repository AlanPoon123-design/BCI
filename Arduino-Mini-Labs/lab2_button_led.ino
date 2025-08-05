// Lab 2: Button-Controlled LED

void setup() {
  pinMode(2, INPUT);      // Set pin 2 as input for button
  pinMode(13, OUTPUT);    // Set pin 13 as output for LED
}

void loop() {
  int buttonState = digitalRead(2);  // Read the button state

  if (buttonState == HIGH) {
    digitalWrite(13, HIGH);  // Turn LED ON when button is pressed
  } else {
    digitalWrite(13, LOW);   // Turn LED OFF when button is released
  }
}
