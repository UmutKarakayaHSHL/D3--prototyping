Project Title
Autonomous Line-Following and Obstacle-Avoidance Vehicle

Project Description
This project focuses on the design, development, and optimization of an autonomous vehicle capable of navigating a predefined track using line detection, obstacle recognition, and adaptive behavior. It is carried out as part of the Prototyping and Systems Engineering course under the supervision of Prof. Dr. Stefan Henkler at the University of Applied Sciences Hamm-Lippstadt.

Objectives
Develop an autonomous vehicle using structured, modular system design.

Enable the robot to follow a black line and react to obstacles by detecting and maneuvering around them.

Incorporate behavior adaptation based on environmental variables such as voltage levels or lighting.

Use tools like UPPAAL for validating timed behavior and GitHub for version control and collaboration.

System Features
Line Following
Uses infrared sensors to detect and follow a black line on a white surface.

Obstacle Detection & Avoidance
Employs an ultrasonic sensor to detect obstacles.

Detects obstacle colors and makes decisions (e.g., stop, bypass, change direction).

Color-Based Decision Making
Uses a color sensor to detect:

Red → Stop

Green → Speed up

Blue → Turn

Adaptive Behavior
Adjusts performance based on battery voltage and lighting conditions.

Allows parameter tuning for motor speed, sensor thresholds, etc.

System Design Approach
Systems Engineering & Initial Prototype
SysML diagrams for requirements, use cases, block structure.

Simulated prototype in Tinkercad.

First hardware prototype using switch-case based control code.

Electronic System Design
Voltage and current analysis.

Circuit simulation using Multisim.

Focus on proper wiring, safety, and power regulation.

Software Module Development
Modular code design using structured programming.

Defined interfaces and unit/module testing.

Use of GitHub for team collaboration and version control.

Timed Behavior Modeling
Transformation of state machines into timed automata using UPPAAL.

Validation of sensor reading and motor reaction times.

Optimization
Adaptation of system to disturbances such as battery drop or environmental noise.

Software-level adjustments and performance tuning.

Tools and Technologies Used
Arduino (with IR sensors, ultrasonic sensor, servo, TCS3200 color sensor)

UPPAAL (for timed automata modeling)

Multisim (for circuit simulation)

GitHub (version control and collaboration)

Tinkercad (for early simulation)

Deliverables
Complete prototype of the robot with functional hardware and software

Full documentation with SysML diagrams, simulation models, wiring design, and optimization logic

GitHub repository with source code, test logs, and version history

Demonstration of the robot following a line, avoiding obstacles, and adapting to color signals


