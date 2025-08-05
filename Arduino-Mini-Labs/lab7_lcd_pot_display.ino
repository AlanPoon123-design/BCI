// Lab 7: Display Potentiometer Value on 16x2 LCD

#include <LiquidCrystal.h>

// Initialize LCD: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);              // Set up the LCD (16 columns, 2 rows)
  lcd.print("Hello, Alan!");     // Display a welcome message
  delay(2000);                   // Wait for 2 seconds
  lcd.clear();                   // Clear the screen
}

void loop() {
  int potValue = analogRead(A0);  // Read potentiometer value (0–1023)

  lcd.setCursor(0, 0);            // First row, first column
  lcd.print("Pot Value: ");       // Print label

  lcd.setCursor(11, 0);           // First row, 12th column
  lcd.print("    ");              // Clear leftover digits
  lcd.setCursor(11, 0);           // Reset position
  lcd.print(potValue);            // Display value

  delay(200);                     // Update delay
}
