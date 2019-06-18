int crossings = 0;
boolean lastflow = true;
int flowpin = 6;
//long currenttime;
long previoustime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (flowpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  currenttime = millis();
  if (digitalRead(flowpin) != lastflow){
    if(lastflow == true){
      lastflow = false;
    }else{
      lastflow = true;
    }
    crossings++;
  }

  if (millis() - previoustime >= 100){
    Serial.println(crossings);
    crossings = 0;
    previoustime = millis();
  }

  delay(0);
}
