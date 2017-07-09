# 12VDC Motor controlled Main Fuel Valve

# DC Motor Valve control overview

   The 12VDC Motor Control project uses a very high torque planetary geared DC motor to crack, open, and close the main fuel valve. To control the position of the valve, a rotary encoding disk allows photo-sensors to receive light through concentric holes in the disk. The holes are designed to position the valve at shutoff, cracked from 0 to +50 degrees in 5 degree increments, and full open. The device is currently being conttrolled by an arduino.

###

## CAD Models

   The main assembly file is 12VDC_valve_assembly.SLDASM

## Control

   The device uses Gray Code built into the encoding disk. The scheme is as follows: 

      0  - 0000 - detent (ALL)
	  1  - 0001 - Closed
	  2  - 0011 - closed <-> cracked
      3  - 0010 - cracked +0 degrees
      4  - 0110 - cracked +5 degrees
      5  - 0111 - cracked +10 degrees
      6  - 0101 - cracked +15 degrees
      7  - 0100 - cracked +20 degrees
      8  - 1100 - cracked +25 degrees
      9  - 1101 - cracked +30 degrees
      10 - 1111 - cracked +35 degrees
      11 - 1110 - cracked +40 degrees
      12 - 1010 - cracked +45 degrees
      13 - 1011 - cracked +50 degrees
      14 - 1001 - Cracked <-> Open
      15 - 1000 - Open (closed plus 180 degrees)
