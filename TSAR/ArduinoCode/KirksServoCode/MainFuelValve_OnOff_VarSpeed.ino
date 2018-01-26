/* Variable Speed Open and Close
 
Program actuates servo based on input from a switch or push button connected to digital pin 8. 

When switch is in off position, pin 8 is high, 
Servo moves to or remains at position = 0 at user defined speed

When switch is asserted, pin 8 is low,
Servo moves to position = 180 at user defined speed.

*/


#include <VarSpeedServo.h>

VarSpeedServo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
//Servo can operate at various speeds

int pos = 0;    // variable to store the servo position

 // pushbutton pin
 const int buttonPin = 8;

void setup() {
  myservo.attach(3);  // attaches the servo on pin 8 to the servo object
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if(!buttonState) //If switch is in "on", pin 8 is low, servo moves to 180 degrees; If switch is "off", pin 8 is high, servo returns to 0;
  {
    myservo.write(180, 90, true); //Parameters: (final pos, speed(varies from 1-255 slowest to fastest), won't move to next line of code until pos 180 is reached)
  }else{
    myservo.write(0, 90, true); 
  }
  delay(300);

}

