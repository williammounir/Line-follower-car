
// IR Sensor Pins
#define leftSensor 3
#define rightSensor 5

// Motor A - Left Motor
#define motor1Pin1 10
#define motor1Pin2 9

// Motor B - Right Motor
#define motor2Pin1 7
#define motor2Pin2 8

// Enable Pins
#define ena 11
#define enb 6

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Optional: for debugging
  Serial.begin(9600);
}

void loop() {
  int left = digitalRead(leftSensor);
  int right = digitalRead(rightSensor);

  // Motor speed control
  analogWrite(ena, 80);  // Left motor speed
  analogWrite(enb, 80);  // Right motor speed

  // Optional: debug IR sensor values
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" | Right: ");
  Serial.println(right);

  // Line following logic
  if (left == HIGH && right == HIGH) {
    forward();
  } else if (right == LOW && left == HIGH) {
    leftTurn();
  } else if (left == LOW && right == HIGH) {
    rightTurn();
  } else {
    stopCar();
  }
}

void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void leftTurn() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(100);
}

void rightTurn() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(100);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
