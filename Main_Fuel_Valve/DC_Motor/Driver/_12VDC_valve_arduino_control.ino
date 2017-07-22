 /*  12V DC Motorized Valve Controller (Main Fuel Valve)
  *  Bertrand DeChant
  *  Portland Space Aerospace Society (PSAS)
  *  Liquid Fueled Engine Test Stand (LFETS)
  *  
  *  This controller uses a rotary encoding wheel with a physical gray coding scheme to allow null, partial, 
  *  and full opening of a ball type valve via a 12VDC Motor and linkage.
  *  
  *  Code and definition:
  *  
  *  ## - Code - Position
  *
  *  00 - 0000 - detent (all)
  *  01 - 0001 - closed
  *  02 - 0011 - closed +5 dgrees
  *  03 - 0010 - closed +10 degrees
  *  04 - 0110 - closed +15 degrees
  *  05 - 0111 - closed +20 degrees
  *  06 - 0101 - closed +25 degrees
  *  07 - 0100 - closed +30 degrees
  *  08 - 1100 - closed +35 degrees
  *  09 - 1101 - closed +40 degrees
  *  10 - 1111 - closed +45 degrees
  *  11 - 1110 - closed +50 degrees
  *  12 - 1010 - closed +55 degrees
  *  13 - 1011 - closed +60 degrees
  *  14 - 1001 - Cracked <-> Open
  *  15 - 1000 - Open (closed plus 90 degrees)
  *  
  *  The valve van be closed either by returning to the close position or turning forward to a close position.
  *  The pattern on the rotary encoder is mirrored so any half-rotation can be considered equivalent to 
  *  initial state. Therefore, given the brush type and gearing of the motor, it is desireable to cycle
  *  forward through the sequence to close the valve.
 */
 
// Use _supVolt for controller supply voltage. Arduino Uno uses a 5 volt supply.
#define _supVolt 5

// Use tripVolt to calibrate the sensors individually. This is the value for which the arduino will recognize a state.
const float tripVolt[4] = {1.0, 1.0, 1.0, 1.0};

int photoSensePin[4] = {A0, A1, A2, A3};       // Assign an array member 0-3 to a pin number 0-3
// int photoSenseValue[4] = {0, 0, 0, 0};         // Initialize the sensor reading value and wipe to zero
float senseVoltage[4] = {0.0, 0.0, 0.0, 0.0};  // Initialize calculated voltage and assign to zero


void setup() {
  Serial.begin(9600);
  
}

void loop() {

  for (int i = 0; i < 4; i++){
    senseVoltage[i] = 5 * (analogRead(photoSensePin[i])/1023);
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(senseVoltage[i]);
    Serial.print("V");
    Serial.println();
  }

/*
  switch(senseVoltage){
    case 0000: // Open -> Closed (detent a)
      break;
    case 0001: // closed
      break;
    case 0011: // closed +5
      break;
    case 0010: // closed +10
      break;
    case 0110: // closed +15
      break;
    case 0111: // closed +20
      break;
    case 0101: // closed +25
      break;
    case 0100: // closed +30
      break;
    case 1100: // closed +35
      break;
    case 1101: // closed +40
      break;
    case 1111: // closed +45
      break;
    case 1110: // closed +50
      break;
    case 1010: // closed +55
      break;
    case 1011: // closed +60
      break;
    case 1001: // cracked -> open (detent b)
      break;
    case 1000: // open
      break;
  }
  */
  
  delay(1000);
}
