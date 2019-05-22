// This code is for use for aquisition of data for the pintle test.
// It is to be used with the Parallax DAQ (PLX DAQ) Macro for Excel, 
// which can be found here:  https://www.parallax.com/downloads/plx-daq

// Authors: Bertrand DeChant and Sam Hastings Hauss
// modified by: Jacob Tiller
// Pintle testing - Spring 2019
// See README.MD for more details and circuit information.

//long currenttime;
long previoustime = 0;


int pressure_pin1 = A0;  //These initialize the pins that each transducer is read from.
int pressure_pin2 = A1;


int samples_per_second = 10 ;  //this adjusts the sampling rate of the DAQ


void setup() {
  
  // initiate serial output. This code is designed to handle 9600 baud.
  Serial.begin(9600);
  
  // Initialize digital pins for reading in binary values
  
  Serial.println("CLEARDATA");   //These 
  Serial.println("LABEL, timestamp, timer, pressure_1, pressure_2");
  Serial.println("RESETTIMER");

//  analogReadResolution(12);
}

void loop() {

 // Serial.print("DATA, TIME, TIMER, "); //This line is to tell the PLX DAQ to record the following line.
  //  It also gives a time stamp to each set of data.

  if (millis() - previoustime >= 100){
    Serial.print("DATA, TIME, TIMER, ");
    Serial.print(analogRead(pressure_pin1));
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin2));
    Serial.print('\n');
    previoustime = millis();
  }

  delay(0);



}
