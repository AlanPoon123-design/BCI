// Lab 8: Control LED using IR Remote

#include <IRremote.h>

const int recv_pin = 11;         // IR receiver data pin
IRrecv irrecv(recv_pin);         // Create IR receiver object
decode_results results;          // Stores decoded result

void setup() {
  Serial.begin(9600);            // Start serial monitor
  irrecv.enableIRIn();           // Enable IR receiver
  pinMode(13, OUTPUT);           // Set LED pin as output
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);  // Print received IR code in HEX

    if (results.value == 0xFFA25D) {     // Example button code (change as needed)
      digitalWrite(13, HIGH);            // Turn LED ON
    } else {
      digitalWrite(13, LOW);             // Turn LED OFF
    }

    irrecv.resume(); // Prepare for next IR signal
  }
}
