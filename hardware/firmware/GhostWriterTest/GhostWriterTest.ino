/*
 * Ghost Writer - Test V1
 * Purpose: Just checking if the motors spin and servo moves.
 * * Hardware: 
 * - Seeed Xiao RP2040
 * - 2x Steppers (28BYJ-48)
 * - 1x Servo (SG90)
 */

#include <Servo.h>
#include <AccelStepper.h>

// --- WIRING NOTES ---
// Motor X is plugged into D0-D3
// Motor Y is plugged into D4-D7
// Servo is on D8

// NOTE: AccelStepper needs the pins in 1-3-2-4 order for these cheap motors!!
// Don't change this order or it just vibrates.
#define X_PIN1 0 
#define X_PIN2 1 
#define X_PIN3 2 
#define X_PIN4 3 

#define Y_PIN1 4 
#define Y_PIN2 5 
#define Y_PIN3 6 
#define Y_PIN4 7 

#define SERVO_PIN 8

// --- SETTINGS ---
// 8 = HALF4WIRE mode (best for 28byj-48)
#define MOTOR_TYPE 8 

// TODO: Tune these speeds later. 1000 seems safe for now.
float speed = 800.0; 
float accel = 500.0;

// Pen angles
int UP_POS = 90;
int DOWN_POS = 15; // tweaked this, 10 was hitting the paper too hard

// Objects
// passing pins as 1-3-2-4
AccelStepper stepperX(MOTOR_TYPE, X_PIN1, X_PIN3, X_PIN2, X_PIN4);
AccelStepper stepperY(MOTOR_TYPE, Y_PIN1, Y_PIN3, Y_PIN2, Y_PIN4);
Servo myServo;

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to open the monitor
  Serial.println("Ghost Writer System Test...");

  // Setup Servo first so pen doesn't drag
  myServo.attach(SERVO_PIN);
  Serial.println("Lifting pen...");
  penUp();

  // Setup Motors
  stepperX.setMaxSpeed(speed);
  stepperX.setAcceleration(accel);
  
  stepperY.setMaxSpeed(speed);
  stepperY.setAcceleration(accel);

  Serial.println("Setup done. Waiting 2s...");
  delay(2000);
}

void loop() {
  Serial.println("Starting square test...");
  
  // Draw a 5x5cm box (approx)
  // 2048 steps is roughly one full revolution of the motor shaft
  
  // Move Right
  penDown();
  runToPosition(2048, 0); 
  
  // Move Down
  runToPosition(2048, 2048); 
  
  // Move Left
  runToPosition(0, 2048); 
  
  // Move Up (Home)
  runToPosition(0, 0); 
  
  penUp();
  Serial.println("Test complete. Sleeping.");
  
  // Stop everything
  while(true) {
    delay(100); 
  }
}

// Helper to save typing
void runToPosition(long x, long y) {
  stepperX.moveTo(x);
  stepperY.moveTo(y);
  
  // block until we get there
  while (stepperX.distanceToGo() != 0 || stepperY.distanceToGo() != 0) {
    stepperX.run();
    stepperY.run();
  }
}

void penUp() {
  myServo.write(UP_POS);
  delay(200); // wait for servo to get there
}

void penDown() {
  myServo.write(DOWN_POS);
  delay(200);
}
