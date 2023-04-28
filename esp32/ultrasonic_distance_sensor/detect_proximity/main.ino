const int trigPin = 23; // TRIG pin of RS1764 ultrasonic distance sensor
const int echoPin = 22; // ECHO pin of RS1764 ultrasonic distance sensor
const int ledPin = 2; // Built-in LED pin of ESP32 development board

void setup() {
  pinMode(trigPin, OUTPUT); // Set TRIG pin as OUTPUT
  pinMode(echoPin, INPUT); // Set ECHO pin as INPUT
  pinMode(ledPin, OUTPUT); // Set LED pin as OUTPUT
  Serial.begin(9600); // Start Serial communication
}

void loop() {
  long duration, distance; // Variables for duration and distance measurements

  // Send a 10 microsecond pulse to the TRIG pin to start the measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse received from the ECHO pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm using the duration of the pulse
  distance = duration * 0.034 / 2;

  // Print the distance on Serial Monitor for debugging purposes
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn on the LED if distance is less than 100 cm, otherwise turn it off
  if (distance < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); // Wait for 500 milliseconds before taking the next measurement
}
