int motor_lA = 9;
int motor_lB = 10;
int motor_enableA = 11;

int motor_rA = 3;
int motor_rB = 4;
int motor_enableB = 5;

int trigger_front = A0;
int echo_front = A1;

int trigger_left = A2;
int echo_left = A3;

int trigger_right = A4;
int echo_right = A5;

void setup() {
  // Initialize motor control pins
  pinMode(motor_lA, OUTPUT);
  pinMode(motor_lB, OUTPUT);
  pinMode(motor_enableA, OUTPUT);
  pinMode(motor_rA, OUTPUT);
  pinMode(motor_rB, OUTPUT);
  pinMode(motor_enableB, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigger_front, OUTPUT);
  pinMode(echo_front, INPUT);
  pinMode(trigger_left, OUTPUT);
  pinMode(echo_left, INPUT);
  pinMode(trigger_right, OUTPUT);
  pinMode(echo_right, INPUT);

  // Set initial motor speed
  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 88);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;

  // Calculate distances
  distance_front = calculateDistance(trigger_front, echo_front);
  distance_left = calculateDistance(trigger_left, echo_left);
  distance_right = calculateDistance(trigger_right, echo_right);

  // Print distances to Serial Monitor
  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);
  delay(50);

  // Navigation logic
  if (distance_front > 20) {
    forward();
    if (distance_left > 10 && distance_left < 20) {
      forward();
    } else if (distance_left >= 20) {
      left();
      delay(30);
      forward();
    } else if (distance_left < 10 && distance_left > 0) {
      right();
      delay(30);
      forward();
    }
  } else if (distance_front <= 20 && distance_right > 20) {
    Stop();
    delay(1000);
    right();
    delay(400);
  } else if (distance_front <= 20 && distance_right < 20) {
    Stop();
    delay(1000);
    right();
    delay(800);
  }
}

long calculateDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void forward() {
  digitalWrite(motor_lA, HIGH);
  digitalWrite(motor_lB, LOW);
  digitalWrite(motor_rA, HIGH);
  digitalWrite(motor_rB, LOW);
}

void right() {
  digitalWrite(motor_lA, HIGH);
  digitalWrite(motor_lB, LOW);
  digitalWrite(motor_rA, LOW);
  digitalWrite(motor_rB, HIGH);
}

void left() {
  digitalWrite(motor_lA, LOW);
  digitalWrite(motor_lB, HIGH);
  digitalWrite(motor_rA, HIGH);
  digitalWrite(motor_rB, LOW);
}

void Stop() {
  digitalWrite(motor_lA, LOW);
  digitalWrite(motor_lB, LOW);
  digitalWrite(motor_rA, LOW);
  digitalWrite(motor_rB, LOW);
}
