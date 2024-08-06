// Define motor pins
const int motor1Pin1 = 2; // Motor A forward
const int motor1Pin2 = 3; // Motor A backward
const int motor2Pin1 = 4; // Motor B forward
const int motor2Pin2 = 5; // Motor B backward

// Define ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Define distance threshold (in cm)
const int distanceThreshold = 15;

void setup() {
    // Initialize motor pins
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);

    // Initialize ultrasonic sensor pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Start serial communication for debugging
    Serial.begin(9600);
}

void loop() {
    // Measure distance
    long duration, distance;
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1; // Convert to cm
    
    // Print distance for debugging
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    // Control robot movement
    if (distance < distanceThreshold) {
        // Stop and turn if obstacle is detected
        stopMotors();
        delay(500); // Delay to simulate turning
        turnRight(); // Adjust to turn in the desired direction
        delay(500); // Delay for turn duration
    } else {
        // Move forward if no obstacle
        moveForward();
    }
}

void moveForward() {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}
