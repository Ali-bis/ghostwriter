Ghost Writer: A Custom PCB Pen Plotter

🚨 Status: Hardware Validation Phase - Where Things Currently Stand\
I've got a good bit accomplished: PCB design is complete and the enclosure has been modelled. Now, we're in the midst of validating the firmware.

📖 About Ghost Writer - My Motivation Behind This Project\
To be honest, I was getting fed up with the standard open-source kits I'd been working with. They always seemed to struggle with getting the wiring tidy and electronics integration just right. That's what got me started on Ghost Writer.

🔧 Key Engineering Features - What Makes This Pen Plotter Special
Custom Carrier Board: This was a beast to get right, but I did manage to design it in KiCad with a Seeed Studio Xiao (RP2040) at its heart, plus ULN2003 stepper drivers and SG90 servo logic all neatly sorted - no more messy wiring!\
Enclosure - A Complicated Business: I designed a custom 3D-printed case with a clever "U-Slot" cable management system, which has allowed me to fit the top-mounted USB microcontroller into a low profile of just 30mm without any problems with mechanical interference.\
Motion Control Firmware - Making It Work Smoothingly: I've also developed a custom C++ validation suite (GhostWriter_Test) to get the 28BYJ-48 stepper motors sorted and working smoothly, and control the servo pen-lift logic directly from the Seeed Xiao.\
Mechanical Base - Starting from an Open-Source Design: I took the open-source EBAD Plotter gantry and tweaked it to fit the new custom electronics.\
How the Repository is Organised
/hardware/pcb - All the custom KiCad board files and fabrication outputs live in here.

/hardware/enclosure - The STL files for the enclosure are stored here.

/hardware/firmware - Grbl configuration for the RP2040 is still a work in progress.

A Sneak Peek at the Design

Figure 1: Custom Carrier Board Layout - How the PCB is laid out
![PCB Layout](docs/pcb_layout.png)
Figure 2: Just to be sure - I checked to see if the PCB would fit inside the enclosure
![EnclosureCheck](hardware/enclosure/images/DesignCheckGW.png)
