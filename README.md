# maze-solver-robot

This Arduino code is designed to control a simple robot equipped with ultrasonic sensors and DC motors for navigation. The robot can move forward, turn left, or turn right based on the distance measurements from its front, left, and right sensors.

---

## Hardware Setup:

 - **Motors:** Two sets of motors, left and right, are connected to pins 9, 10, 11 (left motors) and 3, 4, 5 (right motors).  
 - **Ultrasonic Sensors:** Three ultrasonic sensors are connected to the Arduino, with the front sensor using pins A0 (trigger) and A1 (echo), the left sensor using pins A2 (trigger) and A3 (echo), and the right sensor using pins A4 (trigger) and A5 (echo).

---

## Functions:

### 1. setup():
- Initializes the motor control pins as outputs.
- Initializes the ultrasonic sensor pins as outputs (trigger) and inputs (echo).
- Sets the initial speed for the motors using analogWrite.

### 2. loop():
- Continuously reads distance measurements from the front, left, and right ultrasonic sensors.
- Based on the distance readings, it makes decisions to move the robot forward, turn left, turn right, or stop.

### 3. forward():
- Drives both motors forward.

### 4. right():
- Turns the robot to the right by driving the left motors forward and the right motors backward.

### 5. left():
- Turns the robot to the left by driving the left motors backward and the right motors forward.

### 6.Stop():
- Stops all motors.

---

## Control Logic:

- The robot moves forward if there is no obstacle within 20 cm in front.
- It adjusts its direction based on the distances measured by the left and right sensors.
- If an obstacle is detected within 20 cm in front, the robot stops and turns to the right.
- If both the front and right paths are blocked, it turns further to the right.

---

## Serial Output:

The code outputs the distance readings from the front, left, and right sensors to the Serial Monitor for debugging purposes.
