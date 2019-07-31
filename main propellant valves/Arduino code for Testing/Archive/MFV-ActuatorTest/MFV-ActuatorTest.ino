/*AMS Rotary Sensor AS5147
 Measures absolute angle position referenced at a set NORTH

 Circuit
 UNO: MOSI pin 11
      MISO pin 12 
      CLK  pin 13
      CSN  pin 10

 Mega: MOSI pin 51
       MISO pin 50 
       CLK  pin 52
       CSN  pin 53  
 */

#include <SPI.h>

//Set Slave Select Pin
//MOSI, MISO, CLK are handeled automatically
int CSN = 10;
int SO = 12;
int SI = 11;
int CLK = 13 ;
unsigned int angle;
int pos;

int ledPin = 9; // choose the pin for the LED
volatile int store = 0; // variable for storing angle at moment of button press
int motor = 4; // choose motor output pin
int motordir = 5; // choose motor direction pin
volatile int actuate = 0; // should motor run
int delta = 0; //error b/w measured & desired

void setup() {
  
  Serial.begin(9600);

  //Set Pin Modes
  pinMode(CSN, OUTPUT);
  pinMode(SI, OUTPUT);
  pinMode(SO, INPUT);
  pinMode(CLK, OUTPUT);
  //Set Slave Select High to Start i.e disable chip
  digitalWrite(CSN, HIGH);
  //Initialize SPI 
  SPI.begin();

  pinMode(ledPin, OUTPUT);  // declare LED as output
  attachInterrupt(digitalPinToInterrupt(2), buttonPress, FALLING); //interrupt for button press - unsure if should be RISING or FALLING trigger
}

void loop() {

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

  angle = (angle & (0x3FFF));
  
  int pos = ( (unsigned long) angle)*360UL/16384UL; //convert 14 bit to angle

  //Motor handling
  if (actuate = 1) {   
    delta = abs(store - pos);
      if (delta > 180) {
        delta = abs(delta - 360);   //Ugly rotational handling to produce smaller angle b/w values
      }
      if (delta >= 90) {      //If it already went 90 degrees, stop!
        actuate = 0; //turn off motor trigger
        analogWrite(motor,0); //turn off motor
        digitalWrite(ledPin,LOW); //turn off led
      }
  }
  if (actuate = 1) {
    digitalWrite(motordir,HIGH); //Need to determine correct rotation direction, HIGH or LOW
    analogWrite(motor,255); //turn on motor at full speed
    digitalWrite(ledPin,HIGH); //turn on LED
  }

 // Serial.println(pos);    //Option to print current position
  Serial.println(delta);
  
  delay(100); //small delay
}

void buttonPress()  //Interrupt function, ostensibly
{
  store = pos;
  actuate = 1;
}
