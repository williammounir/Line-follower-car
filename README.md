# Line Follower Car using Arduino

This project is a basic line follower robot built with an Arduino Uno, two IR sensors, and two DC motors. The car is designed to follow a black line on a white surface by detecting the line using infrared sensors and adjusting motor directions accordingly.

### How It Works

- Two IR sensors are mounted on the front of the car.
- The sensors detect whether they are above a black line or a white surface.
- Based on the sensor readings:
  - If both sensors detect white: the car moves forward.
  - If the left sensor detects the line (black) and the right doesn’t: the car turns right.
  - If the right sensor detects the line and the left doesn’t: the car turns left.
  - If both sensors detect the line: the car stops.

### Components Used

- Arduino Uno
- 2x IR Sensors (digital)
- L298N Motor Driver
- 2x DC Motors with wheels
- Chassis and battery pack

This project demonstrates basic robotics and control logic using simple sensor feedback and motor control.
