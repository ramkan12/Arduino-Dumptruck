Autonomous Arduino Dump Truck
An educational hands-on robotics project designed for K-12 students to learn engineering principles through building and programming an autonomous obstacle-avoiding dump truck.
Overview
This project features an autonomous dump truck that uses three ultrasonic sensors for 360-degree obstacle detection, enabling the vehicle to navigate its environment intelligently while avoiding collisions. The truck uses differential steering for precise turning control and includes audio feedback for enhanced user interaction.
Features

Triangulated Ultrasonic Sensors: Three HC-SR04 sensors provide complete frontal coverage

Left sensor: Detects obstacles on the left side
Center sensor: Primary forward-facing collision detection
Right sensor: Detects obstacles on the right side


Autonomous Navigation: Intelligent decision-making based on sensor fusion

Automatic obstacle avoidance
Smart turning logic comparing left vs. right clearance
Dynamic speed control based on obstacle proximity


Audio Feedback: Horn/buzzer provides audio cues during operation

Sounds when backing up
Alert tones for different maneuvers


Differential Steering: Independent motor control for precise turning

Forward/backward movement
Left/right turning
Stop functionality



Hardware Components

Microcontroller: Arduino Uno
Motors: 2x DC motors with H-Bridge motor driver
Sensors: 3x HC-SR04 ultrasonic distance sensors
Power: 15V (Lithium-ion + Alkaline batteries)
Chassis: 3D-printed PLA (10" x 5" x 7")
Speaker: Piezo buzzer for audio feedback
Wheels: 4x yellow wheels with differential steering

Total Cost: ~$26 (economical for educational use)
Pin Configuration
Ultrasonic Sensors
Sensor 1 (Left):   Trig: Pin 7, Echo: Pin 6
Sensor 2 (Center): Trig: Pin 4, Echo: Pin 5
Sensor 3 (Right):  Trig: Pin 2, Echo: Pin 3
Motor Control (H-Bridge)
Motor A: IN1 (Pin 8), IN2 (Pin 9)
Motor B: IN3 (Pin 12), IN4 (Pin 13)
PWM: ENA (Pin 10)
Audio
Speaker: Pin 11
How It Works
Navigation Logic

Obstacle Detection: All three sensors continuously measure distances
Decision Making:

Close obstacle (≤20cm): Back up and sound horn
Medium distance (≤25cm): Stop temporarily
Safe distance (≤100cm): Move forward slowly
Clear path (>100cm): Compare left vs. right sensors and turn toward clearer side


Turning Logic:

If left sensor detects more clearance (>3cm difference): Turn right
If right sensor detects more clearance (>3cm difference): Turn left
Otherwise: Move forward



Sensor Data Processing
Each ultrasonic sensor:

Sends a 10-microsecond pulse
Measures echo return time
Calculates distance: distance (cm) = time (μs) / 29 / 2
Updates every loop cycle for real-time response

Installation & Setup
Hardware Assembly

Mount three ultrasonic sensors on the front of the chassis (left, center, right)
Connect H-Bridge motor driver to Arduino
Wire DC motors to H-Bridge outputs
Connect speaker to Pin 11
Install battery pack (15V total)
Secure all components inside the truck bed

Software Upload

Install Arduino IDE
Clone this repository or download the .ino file
Open the sketch in Arduino IDE
Select Board: Arduino Uno
Select correct Port
Click Upload

First Run

Place truck on a flat surface with clear space ahead
Power on the Arduino
The truck will immediately begin autonomous operation
Observe the serial monitor (38400 baud) for sensor readings and debug info

Code Structure
cpp// Main Functions
void loop()           // Main control loop
void forward()        // Move truck forward
void backward()       // Move truck backward  
void left()           // Turn left (differential steering)
void right()          // Turn right (differential steering)
void Stop()           // Stop all motors

// Sensor Functions
float sensorOne()     // Read left sensor
float sensorTwo()     // Read center sensor
float sensorThree()   // Read right sensor
Technical Specifications
SpecificationValueDimensions10" × 5" × 7"Weight1800gTurn Radius60°Speed7 cm/sPower15V (dual battery)Sensors3× ultrasonic (360° coverage)Motor SpeedPWM controlled at 70/255
Safety Features

Automatic stopping when obstacles detected <25cm
Backup with warning when obstacles <20cm
Audio feedback for all critical maneuvers
Low speed operation (7cm/s) for safety
Manual kill switch via power disconnect

Safety Rating: 9/10
Educational Value
This project teaches students:

Programming: C++ syntax, conditional logic, functions
Electronics: Arduino interfacing, H-Bridge operation, sensor integration
Physics: Ultrasonic wave propagation, distance calculation
Mechanical Engineering: Differential steering, motor control
Problem Solving: Autonomous navigation algorithms

Target Audience: K-12 students (with instructor guidance)
Troubleshooting
Truck doesn't move:

Check battery connections and charge level
Verify motor wiring to H-Bridge
Ensure Arduino is powered and sketch uploaded

Erratic sensor readings:

Verify sensor wiring (Trig/Echo pins)
Ensure sensors have clear line of sight
Check for loose connections

Wheels slipping:

Reduce motor speed in code (#define MotorSpeed)
Check surface friction
Verify equal power to both motors

No audio feedback:

Confirm speaker connection to Pin 11
Check speaker polarity
Verify tone() function calls in code

Future Improvements

Add motorized dump bed mechanism (currently manual)
Implement line-following capability
Add Bluetooth/WiFi remote control option
Expand to 5+ sensors for full 360° coverage
Integrate LED indicators for status
Add data logging to SD card

Project Credits
Team Supreme - Group #9

Dominic Lobosco
Maryam Ashraf
Riham Khan (Navigation Logic & Sensor Integration)
Natalie Geer
Jared Relao

License
This project is open-source and available for educational use. Feel free to modify and adapt for your own learning purposes.
Demo & Resources

Video Demo: https://www.youtube.com/watch?v=MdCv9IWylZ0
Full Documentation: See Showcase_Portfolio.pdf for complete project presentation
