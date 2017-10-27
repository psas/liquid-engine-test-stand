# TSAR
Test Stand Automation and Regulation system for the Portland State Aerospace Society's (PSAS) Liquid fuel engine test stand.

##New Member Onboarding

If you are interested in joining the TSAR team, please reference 'Onboarding.pdf' in the root of this repository. 

##Definitions

LFETS - Liquid fuel engine test stand

Module - Valves, sensors, the engine, the igniter. Anything that is a single moving, sensing or functional unit.

##Test Stand Automation and Regulation System Overview

The TSAR group will build an embedded controls and data acquisition system (CDAQ) for a liquid fuel rocket engine test stand for the Portland State Aerospace Society. Solving this issue is vital because developing a liquid fuel rocket engine will decrease PSAS’s cost per launch drastically while also opening the door for considerably higher peak apogees. Without the development of a safe CDAQ solution for the test stand, PSAS cannot reach its goals. The TSAR solution is a student led, in house solution which will create a custom taylored, safety oriented soluton for test stand CDAQ. Our solution is unique because it will be entirely open-sourced with a focus on repeatability and simplicity to allow other amateur rocket groups to benefit from the liquid rocket engine technology. We will use an off-the-shelf Beagle Bone Black embedded computer and a Marionette DAQ board (a former PSU capstone) to implement this system and all software will be developed by the TSAR team of PSU undergraduates.

Project Contact: Mark Musil - Junior in Electrical Engineering at Portland State University (mmusil@pdx.edu)

##Key Requirements

The following aspects of the system are mandatory. More details are present in the document 'TSAR_Requirements.docx' in the root of this repository. The core features are:

1. Interactive graphical dashboard for state control
2. Safety and security of the entire system
3. Clean, thorough documentation of all group efforts including well-commented code, photographic and videographic artifacts, and thorough usage and debugging resources. 


####What are the major deliverables?
A graphical front end with safety features. A nervous system of sensors and actuators with realtime data output from the RPi3 to the front-end.

####How will we get to those deliverables and the deadline?

Divison of the project into: 

High level application design - GUI, interactive LFETS diagram, state control, security features, real-time data output, data storage

Mid-level system architecture - Discretization of the firing sequence into states, designation of states for each module.

Low-Level sensor specification and sensing - Specification of each sensor's range, and performance characteristics and interfacing of the sensors and actuatuators with the marionette/Rpi3.

####What are the milestones we need to hit?
October: assessment of each High,mid,low system requirements and the tools which will be used for each system.
November: Completed state-machine design, Front end specifications completed, sensor specifications completed.
December: Interface with the fuel sensor or other LFETS needs and provide data output for their project.
January: All sensors specified, all valves under control.
February: Interface with all sensors and have real-time, time alligned data output.
March: 
April:
May: Hot fire :)
####Are there dependencies that could impact the timeline?

It is important that we allign with the needs of the test stand team's needs. In addition, we need to begin delivering a part's list to the Beta project people. 

##Critical Objectives in Temporal Order (To-do list)

1. ### Pre-design
	1. Team Orientation
		1. General Training
			- [] GitHub
			- [] Python Notebook
			- [] System Overview
	2. Task Distribution
		1. Sensor Acquisition and Interfacing
		2. Actuator Acquisiton and Interfacing 
		3. Beagle Bone Black to Actuators
		4. Marionette To sensors
		5. System Design 
		6. Front-End and GUI
		7. Networking
		8. Record Keeping and Documentation
2. ### Design Stage
	1. Consult with Doug Hall concerning System Design
	2. Meet with Jacob Tiller about sensor requirements
	3. Investigate tools such as PyQT
	4. Brainstorm
	5. Determine Critical Path
3. ### Prototyping Stage 1
	1. Develop skeletal prototype of each sub system
		1. Minimal working set for interfacing
	2. Build sensor to screen prototype. 

