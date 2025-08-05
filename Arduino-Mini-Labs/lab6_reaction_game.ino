// Lab 6: Reaction Game with Button and Buzzer

void setup() {
  pinMode(2, INPUT);      // Set pin 2 as input (button)
  pinMode(13, OUTPUT);    // Set pin 13 as output (LED)
  pinMode(9, OUTPUT);     // Set pin 9 as output (buzzer)
}

void loop() {
  digitalWrite(13, HIGH);  // Turn LED on
  delay(1000);             // Wait for 1 second
  digitalWrite(13, LOW);   // Turn LED off

  int buttonState = digitalRead(2);  // Read button input
  
  if (buttonState == HIGH) {
    digitalWrite(9, HIGH);  // Turn buzzer on if button is pressed
    delay(500);             
    digitalWrite(9, LOW);   // Turn buzzer off
  }

  delay(1000);  // Cooldown before next round
}
