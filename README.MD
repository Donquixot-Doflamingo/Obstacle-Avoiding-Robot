# OBSTACLE AVOIDING ROBOT
## Aim of the project
The aim of the project was to make a car robot which detects obstacle in its way and make decision accordingly.

* ## Software related things Used
- AdaFruit Library
- Servo.h Library
- Language used C++
- Arduino Software

* ## Hardware related things Used
- Arduino UNO
- L293D Motor Driver Shield
- Ultrasound Sensor with its mounting backet
- Servo motor
- 2 - 5V Rechargeable battery
- Battery Charger
- 2 - DC Motors 
- Jumper wires
- 2 - Wheels
- 360 rotating wheel
- Foam board

* ## Circuit Design

<div>
  <img src="https://imagizer.imageshack.com/img923/3797/sfbQpx.png" width="600" height="350"/>
</div>

* ## Solution Approach
- Obstacle Avoiding is a car that is fitted with Ultrasonic sensor. It works on ultrasonic principle with Arduino board playing a vital role.
- When we will switched on the car. It will move in forward direction.
- Ultrasonic will transmit ultrasonic waves and will check if there is an obstacle in the path.
- If there comes an obstacle, then the car will stop and servo motor will rotate 90° right, ultrasonic sensor attached to the motor will also rotate and sends the ultrasonic waves.
- If there is no obstacle in right direction, then car turns right.
- If there is an obstacle in right also, then car will check the obstacle in left direction
similarly.
- If there is no obstacle in left direction, then car turns left. Otherwise it will stop.
