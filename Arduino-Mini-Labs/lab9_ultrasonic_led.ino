// Lab 9: Distance Sensing with Ultrasonic Sensor (HC-SR04)

const int trigPin = 9;      // Trigger pin of ultrasonic sensor
const int echoPin = 10;     // Echo pin of ultrasonic sensor
long duration;              // Time taken by pulse
int distance;               // Calculated distance

void setup() {
  pinMode(trigPin, OUTPUT);   // Set trigger pin as output
  pinMode(echoPin, INPUT);    // Set echo pin as input
  pinMode(13, OUTPUT);        // LED output
  Serial.begin(9600);         // Start Serial Monitor
}

void loop() {
  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Speed of sound = 0.034 cm/us

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Turn LED on if object is close (< 10 cm)
  if (distance < 10) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  delay(500);  // Wait before next reading
}
