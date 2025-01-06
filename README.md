# Spring-Mounted Pendulum Simulation
This simulation models a spring-mounted pendulum using Lagrangian mechanics to calculate the forces acting on the system. The simulation is built using raylib, a C library for game development, to visualize the system’s motion, energy, and dynamics over time.

## Overview
The spring-mounted pendulum consists of a pendulum (a mass on a string) connected to a spring. The motion of the pendulum is influenced by gravitational forces, spring forces, and the movement of the bob. The system is simulated by solving the equations of motion derived using Lagrangian mechanics.

## Parameters
The simulation uses the following parameters:
bash ```
- g: Gravitational acceleration (10.0 m/s²)
- m: Mass of the pendulum bob (0.2 kg)
- k: Spring constant (10.0 N/m)
- lp: Length of the pendulum string (4.0 m)
- ls: Rest length of the spring (4.0 m)
- radius: Radius of the pendulum bob and pivot points (0.4 m)
- dt: Time step for the simulation (0.001 s) ```
## Initial Conditions
- theta: Initial angle of the pendulum (-pi/4.0 radians)
- thetadot: Initial angular velocity (0.0 rad/s)
- s: Initial elongation of the spring (0.6 m)
- sdot: Initial velocity of the spring elongation (0.0 m/s)
- t: Time (0.0 s) 
## Lagrangian Mechanics Formulas
The equations of motion for the spring-mounted pendulum are derived using Lagrangian mechanics. The Lagrangian of the system is:


- **L = T - U**

Where:

- T is the kinetic energy of the system.
- U is the potential energy of the system.
The formulas for the accelerations are as follows:

Angular acceleration of the pendulum:

- θ'' = sin(θ) * θ'² / cos(θ) - k * s * sin(θ) / (lp * m * cos(θ)²)
Linear acceleration of the spring:

- s'' = lp * sin(θ)² * θ'² / cos(θ) + lp * cos(θ) * θ'² + g - k * s * sin(θ)² / (m * cos(θ)²) - k * s / m

Where:

- θ is the angular displacement of the pendulum.
- s is the elongation of the spring.
- m is the mass of the pendulum bob.
- k is the spring constant.
- g is the gravitational acceleration.
- lp is the length of the pendulum string.
- θ' is the angular velocity of the pendulum.
- s' is the velocity of the spring.


## Conclusion
This simulation models the motion of a spring-mounted pendulum, with calculations based on Lagrangian mechanics. The program provides a basic framework for further exploration of spring and pendulum dynamics, energy analysis, and graphical representation.
