---
title: Rocket Button Up
layout: base
---

# Final Rocket Button Up

## ARTS-2

### Program the ARTS-2

 1. Connect 9v power, and RS-232 serial cable
 1. Start up Data Analyzer application from Ozark Aerospace
 1. Specify com port if necessary

### Verify correct operation of ARTS-2

 1. Goto altimeter -> diagnostics
 1. Press chirp to test tone generation
 1. With pyros disconnected, click boomer/sw, both pyros should show bad. Switch 2 should show 'off', and switch 1 show 'on'
 1. Connect the resistor/led combo to each pyro channel, click boomer/sw to verify that the respective channel shows OK. Also test-fire each pyro with the respective LED to make sure it lights the LED.

### Setup profiles

 1. We will be using flight profile 1 (one). Make sure respective dip switch on (dip switch 1 should be 'On')
 1. Goto the Altimeter -> Configuration
 1. Verify Profile 1 is configured to deploy drogue at apogee, and main at 1000ft, with a 50hz sample rate. You can 'Load from Alt', and verify these numbers, and 'Save to Alt'. When saving to alt for profile 1, you'll hear 1 beep.
 1. Verify Profile 2 is configured do deploy channel 1 at apogee, channel 2 at 1000ft, and a 50 hz rate... Just to be safe, save this to the altimeter. When saving to alt for profile 2, you'll hear 2 beeps.

## Avionics Module

### Firmware
 1. Begin with the Avionics stack outside of the CPA airframe section.
 1. Build the following stm32 projects in flight configuration (in the individual project directory `make flight`). Your repo should not have any uncommited changes.
   - flight-gps
   - flight-imu
   - flight-rnh
   - flight-servo
 1. Connect JTAG debugger to each of the physical microcontroller boards in turn and flash the correct firmware to it using `make write_stl`.
 1. Using Commander turn on each of the boards.
 1. Use telnet to verify that the boards are talking and return the correct version string.
    - All versions should have the flight- prefix, have the same 7 character hash, and not have M appended to the end.

## Payload Module

### Pre-Assembly

 1. Check Battery voltages
    - ARTS
    - TeleMetrum


### Assembly

 1. Cabling:
    - PWM cable to roll control servo
    - RNH To RasPiCam in payload bay
    - Screw in connectos
    - RasPiCam to 360 camera connector
    - Pyro (to recovery) must go up channels to not interfere with camera module
 1. Check 9 V leads are terminated into ARTS
 1. Aeroshell:
    1. Slide aeroshell down so the square hole lines up with the APS in the front of the camera sled
    1. Slide until flush with top of module
 1. Camera block
    1. Double check SD card is in place and tapped in.
    1. Screw in camera block
 1. Recovery:
    1. Leave off until 11-PreLaunch
 1. Motor Module:
    1. Attach spincan/motor mount but leave motor out until 11-PreLaunch
# Post Assembly tests
 1. Verify Rocketready works using the dev umbilical cable
