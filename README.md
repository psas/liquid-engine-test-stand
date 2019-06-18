# liquid-engine-test-stand

<img src="./teststand_orth.JPG" width="400" alt="Orthographic View of Test Stand">

# Liquid Fuel Engine Test Stand (LFETS) Project Overview

  PSAS team members have already designed and built a [2.5 kN regeneratively cooled bipropellant (liquid oxygen and ethanol) rocket engine](https://github.com/psas/liquid-engine-capstone-2015). This engine design included a number of innovative features including fully parametric CAD design using python scripts and SolidWorks, direct metal laser sintering (DMLS) additive manufacturing by i3D manufacturing, direct spark ignition and pintle injection. Although the rocket engine itself has already been produced, much of the overall system complexity lies in the piping, control, and data acquisition systems which support it. This project intends to flesh out these systems in order to test the engine and its successors.

  The test stand will safely test current and PSAS future generation liquid fuel engines prior to integration into a flight vehicle. PSAS will use the stand to measure engine performance, liquid fuel and oxidizer flow rates, propellant mixing capabilities and other engine performance figures of merit. These tests will be performed remotely, using automated valve switching and data acquisition systems. The LFETS system is designed to be portable by truck, and will support propulsion testing of engines up to 10 kN of thrust. The project will be open-source and will utilize live web-based Jupyter notebook design documentation.

  The feed system uses a classic regulated pressure-fed thermodynamic cycle. Gaseous nitrogen is the pressurant. The LFETS system includes a welded thrust loading truss structure, propellant and pressurant supply tanks, and feed system flow componentry. The project also includes safety and Failure Mode Effects Analysis, and procedures for safe operation and transport.
The LFETS Electrical Ground Support Equipment (EGSE) will allow for the test stand to be controlled remotely. The test stand computer controls all actuators in the LFETS system, auto-sequences engine ignition, start, shutdown, pad-safing, and contingency procedures for any test exception, as well as receiving telemetry from sensors and instrumentation. The LFETS EGSE system is derived from the 3rd generation [PSAS launch tower computer](https://github.com/psas/launch-tower), which uses a BeagleBone Black microcontroller, the [Marionette open-source DAQ](https://marionette-daq.github.io/), and a custom “SCADA-like” GUI.

## Useful Links



[CAD Files](https://github.com/psas/liquid-engine-test-stand/tree/master/cad/Test%20Stand%20CAD%20Files/current%20assembly)

[CAD Guide](https://github.com/psas/liquid-engine-test-stand/blob/master/cad/CAD%20Guide.pdf)

[Bill of Materials](https://drive.google.com/open?id=1SeBntyje6zpfy1jSxysdBP59IyhFcIg6SvVT6w5Bf4Y)

[PID](https://github.com/psas/liquid-engine-test-stand/tree/master/PID)

[Capstone Class Work](https://github.com/psas/liquid-engine-test-stand/tree/master/2018-2019%20Capstone%20documentation/Class%20papers%20and%20presentations)
