---
title: SSH In to Flight Computer Test
layout: base
---

# Rocket table setup

## Common Setup
Start with the Avionics Stack on the rocket cart and batteries charged

 1. Make sure there is something attached to the wifi radio connector (SMA at the top of the Avionics Stack)
    - Either the antenna or a load
 1. Plug in table
 1. Turn on LTC Power brick
 1. Switch on launch tower computer main power
    - Wait a few seconds, verify lights: four reds, blinking blue, blinking green
 1. Visually verify umbilical cord is plugged into the avionics module

## Connect to wifi

 1. Turn on ground control router
 1. Connect to `psas` wifi network
    - Password will be written on the AP or the table

## Verify LTC

 1. `ping ltc`
    - `ltc` should be in the DNS offered via DHCP

## Get flight computer going

 1. Power on Avionics Stack
    - On off switch on battery cable
 1. `ping 10.10.10.5`
    - Actually talking to the RocketNet Hub
 1. Connect to [commander](https://github.com/psas/commander) running on the nuc from  your laptop.
    - Open a browser to <http://ground.psas.lan:5000/>

## In commander
 1. RNH tab -> click "[1] FC On"
    - Click only this, nothing else!
    - Wait for flight computer to boot and establish networking (about 40 seconds? ping 10.10.10.10)
 1. Boot up other services
    - Do *NOT* click "[6] Wifi PA On"
    - Click other on buttons and verify blinky lights for each board
    - You can turn on RasPiCam 2, but the camera is attached to the air frame so it may be a little dull.
 1. Default tab
    - Verify versions of major subsystems by clicking on each button under the "Versions" header

## At laptop
 1. `ssh root@10.10.10.10`
    - Actually talking to Flight Computer
    - See note on wood base of avionics stack for password

## Turning on the RasPiCams
 1. Still on the RNH tab -> click "[2] RasPiCam 1 On"
    - Verify the bottom-most green board starts blinking yellow and green
    - `ping 10.10.10.50` or `ping 10.10.10.60`
 1. `ssh pi@10.10.10.50` or `ssh pi@10.10.10.60` based on which RasPi you're trying to get to
    - Use the usual password

## Common Shutdown
 1. Cleanly shut down the Flight Computer
    - `shutdown now`
    - Wait for FC to shut down (about 30 seconds?  Or 5(?) seconds after it stops responding to pings.)
 1. Using commander: click FC Off (Green button)
    - Green light on computer will go out
 1. Using commander: click All Off
 1. Switch off Avionics Stack
    - On off switch on battery cable
 1. Switch off Launch Tower Computer main power
    - Red switch on side of LTC case
 1. Turn off LTC Power brick
 1. Disconnect laptop from `psas` wifi network
 1. Turn off ground control router.
 1. Unplug table
