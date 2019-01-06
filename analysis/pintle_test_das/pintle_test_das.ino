// This code is for use for aquisition of data for the pintle test.
// It is to be used with the Parallax DAQ (PLX DAQ) Macro for Excel, 
// which can be found here:  https://www.parallax.com/downloads/plx-daq

// Authors: Bertrand DeChant and Sam Hastings Hauss
// Pintle test - Fall 2018
// See README.MD for more details and circuit information.

int num_bits = 8;
int pinval[8] = {0};  // We're using an 8-bit counter so initialize an array of length num_btis at 0.
int pin_0 = 30;   // Physical pin on the arduino, other bits plugged in sequentially from here.
int state_read = 0;
int state_last = 0;
int time_last = 0;
int run_avg[4] = {0};
int average_freq = 0;

int pressure_pin1 = 0;  //These initialize the pins that each transducer is read from.
int pressure_pin2 = 1;
int pressure_pin3 = 2;
int pressure_pin4 = 3;
int pressure_pin5 = 4;

int samples_per_second = 5;  //this adjusts the sampling rate of the DAQ


void setup() {
  
  // initiate serial output. This code is designed to handle 9600 baud.
  Serial.begin(9600);
  
  // Initialize digital pins for reading in binary values
  for (int i = 0; i < num_bits; i++){
    pinMode(pin_0 + i, INPUT);
  }
  Serial.println("CLEARDATA");
  Serial.println("LABEL, timestamp, timer, flow_rate_frequency, pressure_1, pressure_2, pressure_3, pressure_4, pressure_5");
  Serial.println("RESETTIMER");
  
}

void loop() {

  // Read in the hig/low values of each pin
  for (int i = 0; i < num_bits; i++){
    pinval[i] = digitalRead(pin_0 + i);
  }

  // Calulate the decimal number of the state
  state_read = 0;

  state_read += pinval[0];
  state_read += pinval[1] * 2;
  state_read += pinval[2] * 4;
  state_read += pinval[3] * 8;
  state_read += pinval[4] * 16;
  state_read += pinval[5] * 32;
  state_read += pinval[6] * 64;
  state_read += pinval[7] * 128;

  // The counter resets to zero when passing 255 so this subtracts 255 from the last state.
  if(state_read < state_last){
    state_last -= 255;
  }

  // 4-point average filter to reduce flowmeter errors
  run_avg[3] = run_avg[2];
  run_avg[2] = run_avg[1];
  run_avg[1] = run_avg[0];
  run_avg[0] = state_read - state_last;

//  average_freq = run_avg[0] + run_avg[1] + run_avg[2] + run_avg[3];
  average_freq = run_avg[0];
  average_freq = average_freq * 100000;   // Integer math is faster on arduinos
  average_freq = average_freq / (10000);

  // Send the last read flowrate and time since arduino start to the computer
  Serial.print("DATA, TIME, TIMER, "); //This line is to tell the PLX DAQ to record the following line.
  //  It also gives a time stamp to each set of data.
  
  Serial.print(average_freq);
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

  // Reset the metrics for the next loop
  state_last = state_read;
  time_last = millis();

  // The counting is happening externally to the arduino so we can take things slow.
  delay (1000 / samples_per_second);
}
