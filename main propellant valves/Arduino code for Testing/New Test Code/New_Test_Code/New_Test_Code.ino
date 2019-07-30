/*******Hydrotest code for Main Propellant Valves*********
	7/30/19
	
Functions:
	- Reads data from AS5047 rotary encoder over SPI interface
	- Drives valve open 90 deg or closed 90 deg on button press via Pololu G2 motor driver
	- Allows adjustments of position in 3 degree increments (or arbitrary)
	- Note - program re-zeroes on startup, so reset arduino after making open/closed position adjustment
	- Note - motor driver accepts PWM for speed control, however full speed is desired, so motor pin is driven HIGH or LOW.

 SPI Fuctions
 UNO: MOSI pin 11
      MISO pin 12 
      CLK  pin 13
      CSN  pin 10
    */

#include <SPI.h>


//Variables
int dir;
int actuate;
int set_angle;
int error_angle;
int zero_angle;
int delta;
int home_delta;
int buttonstate1;
int buttonstate2;
int buttonstate3;

int CSN = 10;
int SO = 12;
int SI = 11;
int CLK = 13 ;

unsigned int angle; 
int pos;

//Definitions for motor output & button input pins
int pin_motor = 5;
int pin_motordir = 4;
int pin_button1 = 7;
int pin_button2 = 8;
int pin_button3 = 9;


void setup(){

  //Set Pin Modes for magnetic encoder SPI interface
  pinMode(CSN, OUTPUT);
  pinMode(SI, OUTPUT);
  pinMode(SO, INPUT);
  pinMode(CLK, OUTPUT);
  
  //Set Pin Modes for motor & buttons
  pinMode(pin_motor, OUTPUT);
  pinMode(pin_motordir, OUTPUT);
  pinMode(pin_button1, INPUT_PULLUP);
  pinMode(pin_button2, INPUT_PULLUP);
  pinMode(pin_button3, INPUT_PULLUP);
  
  //Set Slave Select High to Start i.e disable SPI chip
  digitalWrite(CSN, HIGH);
 
 //Initialize SPI 
  SPI.begin();
  
  Serial.begin(9600);
  
  SensorRead();
  zero_angle = pos; 		//Read current position & save as zero_angle on startup.
  
  Serial.println("Ready. Zero angle =");
  Serial.println(zero_angle);

  delay(500);
}

void loop() {

  buttonstate1 = digitalRead(pin_button1);
  buttonstate2 = digitalRead(pin_button2);
  buttonstate3 = digitalRead(pin_button3);
  
  if(buttonstate1 == LOW){
    SensorRead();
  	home_delta = abs(zero_angle - pos);  //Determine if currently in the home position
  	if(home_delta > 180) {
          home_delta = abs(home_delta - 360); 
          }
    Serial.println("degrees from home pos:");
    Serial.println(home_delta);
      if(home_delta < 10) {           	//Less than 10 degrees from home, drive to +90
  		set_angle = (zero_angle + 90);
  		set_angle %= 360;
  		dir = 0;
  	}
  	if(home_delta >= 10) {         		//More than 10 deg from home, drive to home position
  		set_angle = zero_angle;
  		dir = 1;
  	}
   // set_angle = (pos + 90);		//Old logic, removed due to possible accumulating errors
   // set_angle %= 360;
    Serial.println("set angle:");
    Serial.println(set_angle);
    DriveLogic(); 						
	}

// Experiment to see if you can budge the valve with a button press
  if(buttonstate2 == LOW){
	  SensorRead();
	  set_angle = pos + 3;
	  set_angle %= 360;
	  Serial.println("Adjust +3 degrees");
	  dir = 0;
	  DriveLogic();
  }
  
  if(buttonstate3 == LOW){
	  SensorRead();
	  set_angle = pos - 3;
	  if(set_angle < 0){
		  set_angle += 360;
	  }
	  Serial.println("Adjust -3 degrees");
	  dir = 1;
	  DriveLogic();

  }
 
  /**********Test of functions:*************
  MotorCommand(1);
  delay(1000);
  SensorRead();
  Serial.println(pos);
  MotorCommand(0);
  delay(1000);
  SensorRead();
  Serial.println(pos);
  */

  
  // ***************Auxiliary functions****************

  void SensorRead() {
     SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
  //Send the Command Frame
  digitalWrite(CSN, LOW);
  delayMicroseconds(1);
  SPI.transfer16(0xFFFF);
  digitalWrite(CSN,HIGH);

  //Read data frame
  digitalWrite(CSN, LOW);
  delayMicroseconds(1);
  angle = SPI.transfer16(0xC000);
  digitalWrite(CSN, HIGH);
  SPI.endTransaction;
  
  angle = (angle & (0x3FFF)); //This is a bitwise AND - not sure why it is here?
  
  pos = ( (unsigned long) angle)*360UL/16384UL; //convert 14 bit to angle
  }
  
  // *****MOTORCOMMAND,(1)=ON,(0)=OFF*****
  void MotorCommand(int actuate) {
    if(actuate == 1) { 
      digitalWrite(pin_motordir,dir);
      digitalWrite(pin_motor,HIGH);
    }
    else {
      digitalWrite(pin_motor,LOW);
    }
  }
  
  void DriveLogic() {
	SensorRead();
	
    delta = abs(set_angle - pos); 		//intermediate variable to determine mininmum angle between current & set
      if(delta > 180) {
        error_angle = abs(delta - 360); 
        }
      else { error_angle = delta; 
      }cvg
	  2) {
      SensorRead();
      delta = abs(set_angle - pos); 		//360 degree rollover handling
      if(delta > 180) {
        error_angle = abs(delta - 360); 
        }
      else { error_angle = delta; 
      }
     // if(error_angle > 95){ //Dheck if something went wrong & stop motor
     //   break;
      MotorCommand(1);
      Serial.println("Motor on, error_angle:");
      Serial.println(error_angle);
      }
      
   MotorCommand(0);
  } 
  
  
  
  
  
  
  
  
