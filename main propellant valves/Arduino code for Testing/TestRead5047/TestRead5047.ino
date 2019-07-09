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
  
  int pos = ( (unsigned long) angle)*360UL/16384UL;

  Serial.println(pos);
  

  delay(1000);
  
}
