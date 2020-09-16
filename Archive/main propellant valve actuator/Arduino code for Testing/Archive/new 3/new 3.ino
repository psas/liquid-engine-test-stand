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
int direction;
int actuate;
int set_angle;
int error_angle;
int zero_angle;
int delta;

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
  zero_angle = pos; //Start by retrieving the zero angle on startup
  
  Serial.println("Ready. Zero angle =");
  Serial.println(pos);
}

void loop() {

	If(pin_button == LOW) {
	DriveLogic(); //use sensor output to determine how to drive motor
	}
	//wait(UPDATE_INTERVAL); 
}	
 
  
  // Auxiliary functions
  void SensorRead() {
	   SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
	//Send the Command Frame
	digitalWrite(CSN, LOW);
	delayMicroseconds(1);
	SPI.transfer16(0x3FFF);
	digitalWrite(CSN,HIGH);

	//Read data frame
	digitalWrite(CSN, LOW);
	delayMicroseconds(1);
	angle = SPI.transfer16(0xC000);
	digitalWrite(CSN, HIGH);
	SPI.endTransaction;
	
  angle = (angle & (0x3FFF)); //This is a bitwise AND - not sure why it is here?
  
 int pos = ( (unsigned long) angle)*360UL/16384UL; //convert 14 bit to angle
  }
  
  void MotorCommand(bool actuate) {
	  if(actuate = true) { 
		  digitalWrite(pin_motordir,HIGH);
		  digitalWrite(pin_motor,HIGH);
	  }
	  else() {
		  digitalWrite(pin_motor,LOW);
	  }
  }
  
  void DriveLogic() {
	  while(error_angle >= 3) {
		  SensorRead();
		  
		  delta = abs(zero_angle - pos); //intermediate variable for 360 degree rollover handling - needs optimization
		  if(delta > 180) {
			  error_angle = abs(delta - 360); 
			  }
		  else { error_angle = delta; 
		  }
		  MotorCommand(1);
		  Serial.println("Motor on, error_angle =");
		  Serial.println(error_angle);
		  
		  if(error_angle > 93) { //double check angle, break out of the loop if drives more than 90 degrees
			break;
		  }
		  wait(UPDATE_INTERVAL); //slow down loop to desired update frequency
	  }
	MotorCommand(0);
  }	
  
  
  
  
  
  
  
  