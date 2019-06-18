// This code is for use for aquisition of data for the pintle test.
// It is to be used with the Parallax DAQ (PLX DAQ) Macro for Excel, 
// which can be found here:  https://www.parallax.com/downloads/plx-daq

// Authors: Bertrand DeChant and Sam Hastings Hauss
// Pintle test - Fall 2018
// See README.MD for more details and circuit information.

int crossings = 0;
boolean lastflow = true;
int flowpin = 6;
//long currenttime;
long previoustime = 0;


int pressure_pin1 = 0;  //These initialize the pins that each transducer is read from.
int pressure_pin2 = 1;
int pressure_pin3 = 2;
int pressure_pin4 = 3;
int pressure_pin5 = 4;

int samples_per_second = 10 ;  //this adjusts the sampling rate of the DAQ


void setup() {
  
  // initiate serial output. This code is designed to handle 9600 baud.
  Serial.begin(9600);
  
  // Initialize digital pins for reading in binary values
  pinMode (flowpin, INPUT);
  
  Serial.println("CLEARDATA");   //These 
  Serial.println("LABEL, timestamp, timer, flow_rate_crossings, pressure_1, pressure_2, pressure_3, pressure_4, pressure_5");
  Serial.println("RESETTIMER");

  analogReadResolution(12);
}

void loop() {

 // Serial.print("DATA, TIME, TIMER, "); //This line is to tell the PLX DAQ to record the following line.
  //  It also gives a time stamp to each set of data.
   
    if (digitalRead(flowpin) != lastflow){
    if(lastflow == true){
      lastflow = false;
    }else{
      lastflow = true;
    }
    crossings++;
  }

  if (millis() - previoustime >= 100){
    Serial.print("DATA, TIME, TIMER, ");
    Serial.print(crossings);
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin1));
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin2));
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin3));
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin4));
    Serial.print(", ");
    Serial.print(analogRead(pressure_pin5));
    Serial.print('\n');
    crossings = 0;
    previoustime = millis();
  }

  delay(0);



}
