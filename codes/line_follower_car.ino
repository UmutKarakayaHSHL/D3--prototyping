// Pin Definitions
#define LEFT_IR 2      // Left IR sensor
#define RIGHT_IR 3     // Right IR sensor

#define IN1 4          // Motor driver IN1
#define IN2 5          // Motor driver IN2
#define IN3 6          // Motor driver IN3
#define IN4 7          // Motor driver IN4

#define TRIG 8         // Ultrasonic sensor TRIG
#define ECHO 9         // Ultrasonic sensor ECHO

#define ENA 10         // Left motor speed control (PWM)
#define ENB 11         // Right motor speed control (PWM)

void setup() {
  // Set IR sensor pins as input
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  // Set motor driver pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read values from the IR sensors
  int leftIR = digitalRead(LEFT_IR);
  int rightIR = digitalRead(RIGHT_IR);
  
  // Measure the distance from the ultrasonic sensor
  long distance = measureDistance();

  // Print distance to Serial Monitor for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if an obstacle is within 30 cm
  if (distance <= 30) {
    stopMotors(); // Stop the motors if obstacle is within 30 cm
  } 
  else {
    // Line Following Logic
    if (leftIR == LOW && rightIR == LOW) {
      moveForward();  // Move forward if both IR sensors see black line
    }
    else if (leftIR == LOW && rightIR == HIGH) {
      turnRight();    // Turn right if left sensor sees black and right sees white
    }
    else if (leftIR == HIGH && rightIR == LOW) {
      turnLeft();     // Turn left if right sensor sees black and left sees white
    }
    else {
      stopMotors();   // Stop if both sensors see white
    }
  }
}

// Function to move the motors forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);  // Full speed for left motor
  analogWrite(ENB, 255);  // Full speed for right motor
}

// Function to turn the motors right
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);  // Full speed for left motor
  analogWrite(ENB, 255);  // Full speed for right motor
}

// Function to turn the motors left
void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);  // Full speed for left motor
  analogWrite(ENB, 255);  // Full speed for right motor
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);  // Stop the left motor
  analogWrite(ENB, 0);  // Stop the right motor
}

// Function to measure the distance using ultrasonic sensor
long measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);
  long distance = duration * 0.034 / 2;  // Convert duration to distance in cm
  
  return distance;
}
