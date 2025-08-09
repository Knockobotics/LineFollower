#include <AFMotor.h>  // Library for L293D Motor Shield

// Define Motors using the Library
AF_DCMotor leftMotor(1);  // Left motor connected to M1
AF_DCMotor rightMotor(4); // Right motor connected to M2

// IR Sensor Pins
#define leftSensor A5
#define rightSensor A4

// Define constant speed
const int MOTOR_SPEED = 150;
const int TURN_SPEED = -100;

void setup() {
    // Set up sensorsS
    pinMode(leftSensor, INPUT);
    pinMode(rightSensor, INPUT);
    
    Serial.begin(9600); // For debugging
}

void loop() {
    int leftValue = digitalRead(leftSensor);  // Read Left Sensor
    int rightValue = digitalRead(rightSensor); // Read Right Sensor

    Serial.print("Left: ");
    Serial.print(leftValue);
    Serial.print(" Right: ");
    Serial.println(rightValue);

    // Robot movement logic
    if (leftValue == 0 && rightValue == 0) { 
        moveForward(MOTOR_SPEED);  // Both sensors on white, move forward
    } 
    else if (leftValue == 1 && rightValue == 0) { 
        turnRight(MOTOR_SPEED, TURN_SPEED);  // Left sensor on black, turn right
    } 
    else if (leftValue == 0 && rightValue == 1) { 
        turnLeft(MOTOR_SPEED, TURN_SPEED);  // Right sensor on black, turn left
    } 
    else {  
        stopMotors();  // Both sensors on black, stop
    }
}

// Move Forward
void moveForward(int speed) {
    leftMotor.setSpeed(speed);
    rightMotor.setSpeed(speed);
    leftMotor.run(FORWARD);
    rightMotor.run(FORWARD);
}

// Turn Left
void turnLeft(int speed, int turnSpeed) {
    leftMotor.setSpeed(turnSpeed); // Reduce speed for smoother turning
    rightMotor.setSpeed(speed);
    leftMotor.run(BACKWARD); // Move left wheel slightly backward for better turning
    rightMotor.run(FORWARD);
    delay(200); // Short delay for controlled turn
}

// Turn Right
void turnRight(int speed, int turnSpeed) {
    leftMotor.setSpeed(speed);
    rightMotor.setSpeed(turnSpeed); // Reduce speed for smoother turning
    leftMotor.run(FORWARD);
    rightMotor.run(BACKWARD); // Move right wheel slightly backward for better turning
    delay(200); // Short delay for controlled turn
}

// Stop Motors
void stopMotors() {
    leftMotor.setSpeed(0);
    rightMotor.setSpeed(0);
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
}
