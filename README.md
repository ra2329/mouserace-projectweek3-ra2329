# EE22005 Mouse Race Project 

# Project Overview
This repository contains the firmware and documentation for an autonomous "mouse" designed for the EE22005 Project Week 3 Race. The goal is to navigate a 20m track defined by a 20 kHz AC wire in under 10 seconds using differential steering and real-time electromagnetic sensing.

# Technical Specifications
Microcontroller: Arduino Nano

Sensors: Dual 220µH pick-up coils (Axial Inductors)

Signal Processing: Passive Bandpass Filter (20 kHz) + TL082 Peak Detector

Motor Drive: Dual N-Channel MOSFET Switch-Mode Drive (PWM at 5 kHz)

Target Velocity: 2.0 m/s (~955 RPM wheel speed)

# Repository Structure
/src: Contains the Arduino .ino source code for the control law.

/docs: Hardware schematics and sensor calibration curves.

README.md: Project summary and version control log.

# Change Management Log
This project utilizes a Branch-per-Feature workflow to ensure the stability of the main race code.

Main Branch: Production-ready code used for official time trials.

Development Branches: Used for testing sensor gain adjustments and PID constant tuning.
