#include <Servo.h>

Servo servoMotor;  // Create a servo object to control the cradle's movement
int tiltAngle = 90; // Initial angle for the cradle (horizontal position)
int tiltPin = A0;  // Analog pin for reading a sensor (e.g., accelerometer)
int pirPin = 2;    // Digital pin for the PIR motion sensor
int wetPin = 3;    // Digital pin for the wet sensor

void setup() {
  servoMotor.attach(9);  // Attach the servo to pin 9
  pinMode(pirPin, INPUT); // Set PIR sensor pin as an input
  pinMode(wetPin, INPUT); // Set wet sensor pin as an input
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  int sensorValue = analogRead(tiltPin);

  // Map the sensor value to an angle (adjust this according to your sensor)
  tiltAngle = map(sensorValue, 0, 1023, 0, 180);

  // Limit the angle to prevent over-tilting
  tiltAngle = constrain(tiltAngle, 0, 180);

  // Control the servo motor to tilt the cradle
  servoMotor.write(tiltAngle);

  // Read the PIR sensor
  int motionDetected = digitalRead(pirPin);

  // Read the wet sensor
  int isWet = digitalRead(wetPin);

  // Print the current angle, PIR status, and wet sensor status to the serial monitor
  Serial.print("Current Angle: ");
  Serial.println(tiltAngle);
  Serial.print("Motion Detected: ");
  Serial.println(motionDetected);
  Serial.print("Wet Sensor Status: ");
  Serial.println(isWet);

  // Check if motion is detected and take action
  if (motionDetected == HIGH) {
    // Motion detected, you can implement your action here, such as playing music or rocking the cradle.
  }

  // Check if the wet sensor indicates moisture
  if (isWet == LOW) {
    // Wetness detected, you can implement your action here, such as sending an alert.
  }

  // Add a delay to prevent rapid updates (adjust as needed)
  delay(1000);  // 1-second delay
}