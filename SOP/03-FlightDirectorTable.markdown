---
title: Seting up the flight director table
layout: base
---

# Flight director table setup

## Starting up the flight director table

1. Plug it in to the wall
1. Switch on the surge protector
1. Check for blinking lights on the router
1. Turn on the NUC (bottom slider shelf, silver button on top)
1. Login as root, pass on the sticky

## Start up the launch tower computer

1. Setup LTC {link to other procedure book}

## Boot up Kivi on the flight director table

1. Open terminal
1. `cd psas/launch-tower-comm/launch-tower-comm`
1. `./ltc.py`
1. Verify that the upper right says "Nominal"
1. Play with the LTC to your heart's content

## Boot Commander on the flight director table

1. New terminal tab
1. `cd psas/commander`
1. `python app.py` to run in debug mode. Then you can point your laptop at the NUC directly

## Bring up the flight computer

1. {link again to other procedure book}

## Bring up telemetry

1. New terminal tab
1. `cd psas/telemetry`
1. `./telemetry.py`
1. <http://ground.psas.lan:8080/>

### Getting the trackmaster running

1. `ssh root@10.10.10.10` (password on the base of the avionics stack)
1. `./startFC`
  1. It should give you a happy message

### Start up the trackmaster

1. Check that the lan and PoE cables are correctly installed
  1. LAN goes to router (NOT THE POE CABLE!)
  1. POE cable goisg to the black box on the trackmaster
1. Plug in the cable labeled POE
  1. Green light on the black box
  1. A little later a blue blinky light on the clear box
  1. Green light on the board by the antenna
1. Data should be coming in to ground.psas.lan

## Getting video from the raspicams

1. Get the flight computer running via Commander
1. Boot up raspicam1 from Commander
1. Make sure the trackmaster is running
1. Open VLC on your laptop and connect to `rtsp://10.0.0.3:8554/`