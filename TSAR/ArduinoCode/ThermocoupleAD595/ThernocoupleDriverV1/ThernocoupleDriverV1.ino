const int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

int sensorVal = analogRead(sensorPin);
Serial.print(" Sensor Value: ");
Serial.print(sensorVal);

float voltage = (sensorVal/1024.0) * 5.0; // Convert ADC reading to voltage

Serial.print(", Volts: ");
Serial.print(voltage);
Serial.print(", degrees C: ");
float temperature = (voltage - 0.5) * 100; // Convert the voltage to temperature 
Serial.println(temperature);

}

