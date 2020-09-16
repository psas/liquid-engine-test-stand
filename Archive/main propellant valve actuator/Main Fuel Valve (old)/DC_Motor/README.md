# 12VDC Motor controlled Main Fuel Valve
<p align="center">
<img src="./image_01.PNG" width="400">
</p>

 DC Motor Valve control overview

   The 12VDC Motor Control project uses a very high torque planetary geared DC motor to crack, open, and close the main fuel valve. To control the position of the valve, a rotary encoding disk allows photo-sensors to receive light through concentric holes in the disk. The holes are designed to position the valve at shutoff, cracked from 0 to +60 degrees in 5 degree increments, and full open. The device is currently being controlled by an arduino.

###

## CAD Models
  
   The main assembly file is 12VDC_valve_assembly.SLDASM  
     
   PSAS authored files are:  
  
   12VDC_valve_assembly.SLDASM  
   Motor_12VDC_638263.SLDPRT - From drawing  
   Motor_12VDC_638263_shaft.SLDPRT - from drawing  
   Sensor_Head.SLDPRT  
   encoding_wheel.SLDPRT  
   Housing-Back.SLDPRT  
   Housing-Front.SLDPRT  

## Control

#### Basic Theory

The device uses Gray Code built into the encoding disk. The scheme is as follows: 

State - Code - Position

  00 - 0000 - detent (all)  
  01 - 0001 - closed  
  02 - 0011 - closed +5 dgrees  
  03 - 0010 - closed +10 degrees  
  04 - 0110 - closed +15 degrees  
  05 - 0111 - closed +20 degrees  
  06 - 0101 - closed +25 degrees  
  07 - 0100 - closed +30 degrees  
  08 - 1100 - closed +35 degrees  
  09 - 1101 - closed +40 degrees  
  10 - 1111 - closed +45 degrees  
  11 - 1110 - closed +50 degrees  
  12 - 1010 - closed +55 degrees  
  13 - 1011 - closed +60 degrees  
  14 - 1001 - Cracked <-> Open  
  15 - 1000 - Open (closed plus 90 degrees)  
  
  Detent position idicates an extreme condition. When a detent condition occurs, the script will determine the corrective action base on desired state.
  
  #### Control profiling
  
  Two control features requiring implementation are **Encoding Disk Interpolation** and **DC Motor Inertia Lag Profile**.
  
  **Encoding DIsk Interpolation**
      The source LED light is sensed by the photo-tranistors as the encoding wheel turns. At times the source LEDs will be partially occluded by the encoding wheel. The voltage throughput of the phototransistors will have a period of ramping up and ramping down due to this partial occlusion as the encoding wheel turns. If these ramping periods are profiled, a state can be identified more accurately than the 5 degree increments of the gray code. If these intermediate states can be proven accurate and reliable the encoding wheel should provide significantly improved resolution.
      
  **DC Motor Intertia Lag Profile**
      Due to the gearing and the inertia of the rotating mass in the motor, the motor continues to turn for a short time after it is switched off. This lag needs to be profiled so a switching point may be automatically determined based on desired state.
  
## To do:
  
  - [x] Design Motor to mount housing using jacob's design for the servo-motor as a base
    - [x] Must maintain motor and valve-housing position against torque during action
    - [x] Must have a mount for the "Sender" LED's (5mm) to provide bright light to the sensors
        - [ ] Bonus: Shield the "sender" and sensor heads from outside sources of light
    - [ ] Print the Housing front, back, LED Sender head, and photosensor head
        - [x] Initial printing of front, back, LED Sender head, and photosensor head
        - [ ] Print updated encoding wheel
        - [ ] Post-process housing front & back
    - [ ] Acquire hardware & bits
    - [ ] Assemble

