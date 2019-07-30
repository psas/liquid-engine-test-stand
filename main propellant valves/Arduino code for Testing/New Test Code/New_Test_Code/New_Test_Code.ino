/* Hydrotest code for LFETS MFV

 SPI Fuctions
 UNO: MOSI pin 11
      MISO pin 12 
      CLK  pin 13
      CSN  pin 10
    */

#include <SPI.h>


//Constants 
static const uint64_t UPDATE_INTERVAL = 100;


//Variables
int dir;
int actuate;
int set_angle;
int error_angle;
int zero_angle;
int delta;
int home_delta;
int command;

int CSN = 10;
int SO = 12;
int SI = 11;
int CLK = 13 ;

unsigned int angle; 
int pos;

//Need to define motor input pins & button pin
int pin_motor = 5;
int pin_motordir = 4;
int pin_button = 3;


void setup(){

  //Set Pin Modes for magnetic encoder
  pinMode(CSN, OUTPUT);
  pinMode(SI, OUTPUT);
  pinMode(SO, INPUT);
  pinMode(CLK, OUTPUT);
  
  //Set Pin Modes for motor
  pinMode(pin_motor, OUTPUT);
  pinMode(pin_motordir, OUTPUT);
  pinMode(pin_button, INPUT_PULLUP);
  
  //Set Slave Select High to Start i.e disable chip
  digitalWrite(CSN, HIGH);
  
  //Initialize SPI 
  SPI.begin();
  
  Serial.begin(9600);
  
  SensorRead();
  zero_angle = pos; //Start by retrieving the initial angle on startup
  
  Serial.println("Ready. Zero angle =");
  Serial.println(zero_angle);

  delay(500);
}

void loop() {
	
 SerialRead()
 if(command > 0) {
    SensorRead();
	home_delta = abs(zero_angle - pos)  //Determine if currently in the home position
	if(home_delta > 180) {
        home_delta = abs(home_delta - 360); 
        }
    if(home_delta < 10) {  //In home position, drive to +90
		set_angle = (zero_angle + 90);
		set_angle %= 360;
		dir = 0;
	}
	if(home_delta >= 10 {  //Not in home position, drive to home
		set_angle = zero_angle;
		dir = 1;
	}
	  
   // set_angle = (pos + 90);
   // set_angle %= 360;
    Serial.println("set angle:");
    Serial.println(set_angle);
    DriveLogic(); //use sensor output to determine how to drive motor
    command = 0;
	}
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

  
  // Auxiliary functions 
  void SerialRead() {
	  if(Serial.available() > 0) {
	  command = Serial.read();
	  }
	  else {command = 0;}
	  
  
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
	
    delta = abs(set_angle - pos); //intermediate variable to determine min angle between
      if(delta > 180) {
        error_angle = abs(delta - 360); 
        }
      else { error_angle = delta; 
      }
	
    while(error_angle >= 2) {
      SensorRead();
      delta = abs(set_angle - pos); //intermediate variable for 360 degree rollover handling - needs optimization
      if(delta > 180) {
        error_angle = abs(delta - 360); 
        }
      else { error_angle = delta; 
      }
      if(error_angle > 95){ //Dheck if error overrun exists & stop motor
        break;
        }
      MotorCommand(1);
      Serial.println("Motor on, error_angle =");
      Serial.println(error_angle);
      
      }
      
   MotorCommand(0);
  } 
  
  
  
  
  
  
  
  
