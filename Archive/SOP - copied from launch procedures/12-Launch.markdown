---
title: Launch Procedures
layout: base
---

# LAUNCH

## Procedures for LAUNCH CONTROL

### Trackmaster

 1. Plug in ethernet and power-over-ethernet (POE) injector.  

### Telemetry Server

 1. Boot telemetry server (laptop)

## Full Powerup

 1. With Rocket on pad and preped (see: Pre-Launch)
 1. Use commander to power all on
 1. Clear FC log files
 1. Attempt to verify telemetry
 1. Use commander to turn on the following
    - IMU
    - GPS
    - Raspberry Pi camera ONE
    - Raspberry Pi camera TWO
    - Roll
    - WiFi
 1. Verify data streams through telemetry server over trackmaster WiFi link
 1. Send version commands to:
    - IMU
    - GPS
    - Raspberry Pi camera ONE
    - Raspberry Pi camera TWO
    - Roll
    - Flight computer
    - Rocket net hub

## Arm FCF

 1. Disable Shore Power
 1. Send ARM Commands

Proceded to Terminal Count

## Procedures for LAUNCH TOWER

## Final Pre-Launch Procedures

### Arm Recovery System

![Payload module switch layout](diagrams/switches.png)

1. Turn on TeleMetrum (SW 4)
    1. Listen for beeps. 3 beeps good, low tone bad, 10 seconds Morse P ( .--. )
    1. Radio down to launch control to verify telemetry is streaming.
    1. Radio down to launch control to verify configuration coming from TeleMetrum is as expected.
1. Turn on ARTs (SW 3), verify good beep code (3 beeps).


## Run Igniter Cables

 1. Lay out Ignition Extension Cable with 3 boxes.
    - Motor Box ~7ft away from nozzle.
    - Away Box as far as possible, but try to keep orange cord from being run over.
 1. _Call with Launch Control for go-ahead to hook up igniter_
 1. Clear all personnel other than L3
 1. Check Manual Arm switch on LTC is off.
 1. Check that the LTC igniter relay is off.
 1. Check that the RocketReadyRelay is off.
 1. Verify short bar/launch key is in place
 1. Check that the Away Box is empty (no shorting bar) and the light is off.
 1. Check that the LTC igniter relay and the RocketReadyRelay are off.
 1. Verify alligator clips are connected to the motor box.
 1. Insert motor igniter into motor.
 1. _Call Launch Control that igniter is in_ and confirm they understand..
 1. Verify Motor Box indicator is dark
 1. Connect the alligator clips to Igniter.
 1. Switch Manual Arm Switch to **ON**
 1. _Call Launch Control that Arm Switch is on_. Verify LC understands.
 1. Remove short bar/launch key.
 1. Move Away from the box.
 1. Final check that area is clear of other personnel.
 1. Verify that red LED in away box is OFF.
 1. Insert shorting jumper into the Away box
 1. Leave the Launch area (**run away**).
 1. _Call Launch Control that arming is complete_. Verify LC understands.


## Terminal Count

 1. Clear area for launch
    - All observers should look and affirm that no one is close enough to the tower that it's a problem.
 1. Check ground
    - Telemetry
    - Video
    - TeleMetrium
 1. Check GPS lock
 1. Get in positions
    - Recovery eyes up
    - Cameras set
    - Trackmaster and spotter
 1. Go/No-go poll
    - LTC (launch tower comm app)
    - Recovery (radio leads)
    - TeleMetrum
    - Video
    - Trackmaster
    - Telemetry
    - FCF
    - FD
    - RSO
 1. Turn on siren and light.
 1. Start countdown (30 seconds)
 1. Send ignite signal (T-0)


## Ignition Instructions

 1. Make sure the launch tower computer is operational and on the network
 1. From a computer on the ground network, run the kivy app with ./ltc.py found in the [launch-tower-comm/launch-tower-comm](https://github.com/psas/launch-tower-comm/tree/master/launch-tower-comm)
 1. The app will come up breifly in the disconnected state, and then establish a connection to the LTC. This is indicated by the status indicator in the top right displaying "Nominal". 
 1. Verify all the values in the sensor display widget (bottom half of screen) are nominal.
 1. To arm the launch tower shorepower must be off. Once it is so the tower can be armed by clicking the "Arm" button.
 1. In the Armed state the top left buttons will swap over to "Ignite" and "Abort", and the status indicator will indicate "Armed" in a red font.
 1. To return to the unarmed state click abort.
 1. To proceed with ignition, click the Ignite button. A popup will ask you to confirm this action.
 1. To command the igniter to ignite, click the ignite button on the popup. Otherwise you can click abort to return to Armed screen.
 1. Once the popup ignite button has been pressed it will return to the Armed screen. When the LTC has confirmed that the igniter is active the Ignite button will turn blue and the status indicator will show "Ignited!" in teal text.
 1. Verify the rocket has launched. Visual cues include the rocket no longer being on the launch tower and a smoke trail leading off into the sky. Auditory cues include loud noises. 
 1. The LTCcom software will automatically turn off the igniter after 10 seconds. By pressing either the Ignite or Abort buttons the command to shut off the igniter can be sent early.

