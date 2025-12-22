Ghost Writer: A Custom PCB Pen Plotter

Status - We're Still in the Engineering Phase

Right now, I've made it to this point in the project

PCB Design is Done | Enclosure is Modelled | Sourcing Components is Ongoing.

About Ghost Writer

Ghost Writer is a custom-built 2-axis CNC pen plotter that I made after getting frustrated with the usual open-source kits that always seem to have problems with cable management and electronics integration.

Key Engineering Features of Ghost Writer

Carrier Board - I designed a custom PCB: This board takes a Seeed Studio Xiao (RP2040) and links it up with ULN2003 stepper drivers and SG90 servo logic using KiCad.

The Enclosure - I built a custom 3D printed case: This thing has a "U-Slot" cable management system to get that top-mounted USB microcontroller to fit inside it without taking up too much room (30mm).

The Mechanical Base - Modified the EBAD Plotter Gantry: I tweaked the open-source gantry from the EBAD Plotter project so it can work with my new design.

How I Organized the Repository

/hardware/pcb - All the custom KiCad board files and fabrication outputs live in here.

/hardware/enclosure - The STL files for the enclosure are stored here.

/firmware - Grbl configuration for the RP2040 is still a work in progress.

A Sneak Peek at the Design

Figure 1: Custom Carrier Board Layout - How the PCB is laid out

Figure 2: Just to be sure - I checked to see if the PCB would fit inside the enclosure
