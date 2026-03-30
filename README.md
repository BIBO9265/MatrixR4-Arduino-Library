# MatrixR4-Arduino-Library

A competition-oriented library collection for Matrix R4 development, providing motion control, I/O control, and reusable control algorithms.

## Overview

This repository provides a set of libraries developed for Matrix R4-based projects.
It is intended to serve as a foundation library for competition robots and embedded control applications.

The project contains two types of modules:

* **Matrix R4 specific modules**
  These modules depend on Matrix R4 hardware and are designed for motor control and I/O port control.

* **Generic control algorithm modules**
  These modules implement reusable control algorithms and can be used on other boards or platforms.

## Module Support

### Matrix R4 Specific

The following modules are intended for **Matrix R4 only**:

* **AXISController**
  Motion / axis control functions for Matrix R4.

* **UIController**
  I/O-related control functions for Matrix R4 peripherals and ports.

### Generic Modules

The following modules are designed as **general-purpose control algorithms**:

* **ACCController**
  Generic acceleration or motion-profile-related control logic.

* **PIDController**
  Generic PID control algorithm for reusable closed-loop control applications.

## Purpose

This library is mainly built for:

* competition robot development
* Matrix R4-based control projects
* reusable embedded control functions
* faster development of motion and I/O control applications

## Repository Structure

```text
ACCController/
AXISController/
PIDController/
UIController/
```

Each module currently exists as an independent library component.

## Platform Support

| Module         | Support            |
| -------------- | ------------------ |
| AXISController | Matrix R4 only     |
| UIController   | Matrix R4 only     |
| ACCController  | Generic / reusable |
| PIDController  | Generic / reusable |

## Installation

Currently, this repository is provided as a source collection of libraries.

### Manual Installation

1. Download or clone this repository.
2. Copy the target library folder into your Arduino `libraries` directory.
3. Restart Arduino IDE.
4. Include the required header files in your project.

## Status

This project is currently in an **early development stage**.

Initial version includes the basic module structure for:

* acceleration-related control
* PID control
* axis control
* I/O control

## Notes

* Some modules are hardware-dependent and only work on Matrix R4.
* Generic algorithm modules may be reused on other boards.
* API design, examples, and documentation are still being refined.

## Roadmap

Planned improvements may include:

* clearer API design
* usage examples
* better module integration
* expanded documentation
* additional competition-oriented control utilities

## License

License not specified yet.
