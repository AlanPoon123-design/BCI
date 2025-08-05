// Lab 3: Read Analog Input from Potentiometer

void setup() {
  Serial.begin(9600);       // Initialize Serial Monitor
  pinMode(A0, INPUT);       // Set A0 as analog input
}

void loop() {
  int potValue = analogRead(A0);   // Read analog value (0 to 1023)
  Serial.println(potValue);        // Display value in Serial Monitor
  delay(200);                      // Wait 200ms before next read
}
