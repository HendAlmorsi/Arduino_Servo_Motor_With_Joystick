#include <Servo.h>

const int servo1 = 3;         // first servo
const int servo2 = 10;        // second servo
const int joyH = A1;          // L/R Parallax Thumbstick
const int joyV = A0;          // U/D Parallax Thumbstick

int servoVal;                 // variable to read the value from the analog pin
int valH = 90, valV = 90;     // servo Horizontal and Vertical value
Servo myservo1;               // create servo object to control a servo
Servo myservo2;               // create servo object to control a servo



void setup() {

  // Servo
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
}


void loop() {

  // Read the horizontal joystick value  (value between 0 and 1023)
  servoVal = analogRead(joyH);
  Serial.println(servoVal);
  joyValueCompare(servoVal, valH);

  myservo2.write(180 - valH);                           // sets the servo position according to the scaled value

  // Read the Vertical joystick value  (value between 0 and 1023)
  servoVal = analogRead(joyV);
  joyValueCompare(servoVal, valV);

  myservo1.write(180 - valV);                           // sets the servo position according to the scaled value

  delay(15);                                            // waits for the servo to get there

}

// Compare the servoVal (Read from Joystick) and update the value of the given axis  
void joyValueCompare(int servoVal, int &val){
  
  // foward
  if(servoVal > 1000 && val < 180)
    val += 10;
  else if(servoVal > 800 && val < 180)
    val += 5;
  else if(servoVal > 600 && val < 180)
    val += 2;
    
  // backward  
  if(servoVal < 20 && val > 0)
    val -= 10;
  else if(servoVal < 200 && val > 0)
    val -= 5;
  else if(servoVal < 400 && val > 0)
    val -= 2;
    
  if(val > 180){
    val = 180;
  }
  else if(val < 0){
    val = 0;
  }
}

