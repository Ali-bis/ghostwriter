🖋️ Ghost Writer - A Custom PCB Pen Plotter
Ghost Writer is a precision pen plotter that can be used to solve the "messy wiring" problem you usually get when you build one of those open-source plotter kits. To make that happen, I built a custom board that works with a compact - and 3D printed - parallel linkage gantry, which gives Ghost Writer high-torque motion control in a tiny footprint.

Figure 1: The Final Assembled Project, shown in CAD
![PCB Layout](docs/GW_assembled_vid.mp4)
🚀 Why I Did This
Most open-source kits have a problem with cable management and getting the electronics to work together without breaking. Ghost Writer was made to move away from the "breadboard prototype" stage and into something a bit more robust.

What I Wanted to Achieve:
No More Messy Wiring: A custom PCB means you can ditch the jumper wires and use dedicated traces for power and signal instead.
It's Super Compact: A custom 3D printed enclosure with a special cable management system keeps the whole thing at a tiny 30mm high.
It Draws Precisely: Powered by high-torque NEMA 17 steppers and a Seeed Studio XIAO (RP2040) for real-time inverse kinematics - that's a mouthful, but basically it draws very nicely.


🛠️ Hardware
Here are the key bits that make Ghost Writer tick
Main Processor: Seeed Studio XIAO RP2040 (a dual-core ARM Cortex M0+ processor)
Motion: 2x NEMA 17 Stepper Motors (each one with a 1.8° step angle for smooth movement)
Motor Drivers: 2x A4988 Stepper Drivers (these are super powerful and tuned to get the most out of the motors)
Pen Lift: a SG90 Micro Servo that you can control with a pulse-width modulation signal
Display: A tiny 0.96" I2C OLED Display so you can keep an eye on what's going on and where things are moving to
Power: 12V 2A DC via a standard barrel jack

🏗️ Mechanical Design & CAD
The enclosure was designed in Tinkercad with one main goal - stop the mechanical bits getting in the way of each other.
Carrier Board Mounting: the PCB is held in place with 9mm internal pillars which keeps it nice and insulated from the rest of the robot.
Parallel Linkage: the 80mm shoulder and 100mm forearm lengths give it a pretty generous drawing area for its size
U-Slot Management: a special cable path keeps the wiring clear of the moving parts
Figure 2: a clearance check between the custom PCB and the 3D printed housing

📂 Repository Structure
├── /hardware\
│   ├── /pcb        # the KiCad board files and Fabrication outputs (Gerbers)\
│   ├── /enclosure  # the STL files for the Box, Lid, and Linkage Arms\
│   └── /firmware   # the custom C++ validation suite (GhostWriter_Test)\
├── BOM.csv         # the Bill of Materials (itemised costs and links)\
└── README.md       # the Project documentation\

📋 Bill of Materials
The breakdown of costs and sourcing is in the BOM.csv file.
Note: This project tried to stay within a $100 budget by doing some creative 3D printing and choosing shipping methods that are pretty cost-effective

⚙️ Firmware
The system is currently running a custom C++ validation suite (GhostWriter_Test) to get the motors and servo working smoothly.
At the moment: I'm still working on getting G-Code interpretation via GRBL for RP2040 to work properly.
Motion Logic: the inverse kinematics calculations are being done on the second core of the RP2040 so the motor pulses are nice and smooth.
A Sneak Peek at the Design


Figure 2: Just to be sure - I checked to see if the PCB would fit inside the enclosure
![EnclosureCheck](hardware/enclosure/images/DesignCheckGW.png)
