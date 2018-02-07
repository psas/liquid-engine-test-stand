//Demo code for calibrating pressure transducers for the TSAR
//control system for the LFETS system
//Mark Musil January 26th 2018

const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print(" Sensor Value:  ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0; 
  
  Serial.print(", Volts:  ");
  Serial.print(voltage);
  Serial.print("\n");
  delay(1000);
  
}


