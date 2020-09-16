---
title: Pre Launch
layout: base
---

# Pre Launch

## Launch Control Setup

### Radio Checks

 1. 2 meter mobile on and locked on PSAS freq (see References)
 1. Sound-off personnel with HTs
 1. PSAS Linksys router up and running
 1. Setup Telemetry server
 1. Plug in TM3K
    - ping to verify


## Procedures for LAUNCH TOWER

#### Tools for On Tower Procedures

 - Procedure book
 - Small flashlight to view inside aeroshell
 - Medium flat-head screw driver, for main switches, make sure it will fit thru the aeroshell holes
 - Flight Umbilical cable
 - Motor box
   - Igniters
   - Dowel for igniter

#### LTC On
 1. Verify Igniters **NOT in**
 1. Power on LTC
 1. _Call launch control for LTC update_
 1. Attach umbilical cable
 1. _Call launch control for FC update_
 1. Test umbilical connector disconnector disconnects correctly by physically lifting the rocket on the launch rail.
 1. _Call launch control to verify that they saw umbilical disconnect_
 1. Reattach Umbilical


## Procudures for LAUNCH CONTROL

### LTC On

 1. Wait for call from tower that LTC is on
 1. Verify LTC (ping)
 1. Bring up
    - LTComm
    - Commander
    - Telemetry window
       - Check for connected in top right
 1. _Call tower to continue and attach umbilcal_
 1. _Wait for tower to confirm conduct umbilical connector disconnector test via radio_
 1. When Away team has completed umbilical connector disconnector test, verify using telemetry that the umbilical has disconnected
 1. _Call tower to confirm we see detached umbilical_
 1. Check for umbilical reattachment. 
 1. Using Commander check umbilical by sending RNH version request
 1. Using LTComm, turn on shore power
    - Look for shorepower voltage within nominal bounds in LTComm
 1. Using Commander RNH tab, **Turn on FC**
 1. Wait for FC to boot (about 30 seconds)
 1. Verify Trackmaster power amp is on
 1. Turn on rocket wifi power amp
 1. Check telemetry server for FC packets

At this point we are set up physicaly. The tower crew can come back to launch control if they need water or there is an expected wait time for launch.

## Pre Launch Software Testing

### Power up

 1. Turn on all ports on the RNH using Commander
 1. Send version request and self test for each device using Commander
    1. RNH
        -  Verify port faults for no unexpected errors
    1. FC
    1. IMU
    1. Roll
    1. RasPiCam 1
    1. RasPiCam 2
    1. GPS

### Working Checks

 1. RNH
    1. Check telemetry viewer that port current draw is nominal
    1. Verify that umbilical detect is detecting the umbilical
    1. Verify battery is within nominal bounds and has no unexpected errors
 1. IMU
    1. In telemetry viewer look for data
 1. RasPiCam 1
    1. Bring up streaming view and check stream
 1. RasPiCam 2
    1. Bring up streaming view and check stream
 1. Roll
    1. Use commander to send Roll test command
    1. Watch fin movement through RasPiCam stream
 1. GPS
    1. In telemetry viewer wait for good GPS Lock
 1. Full system check:
    1. With IMU on, rotate the rocket about all axises for the IMU calibration procedure 


## Post Check Power Down

 1. SSH into the flight computer
 1. Manually stop the FCF service
 1. Purge the log files
 1. Set any and all flags to FLIGHT
 1. Shutdown FC
 1. Power off everything but RNH
    1. Use Commander to send **All Off** command
 1. Check that shore power is still on in LTComm
 1. Purge Telemetry logs and restart the telemetry server
 1. Attach recovery and motor modules
Now ready to continue to final launch countdown as window conditions allow.
