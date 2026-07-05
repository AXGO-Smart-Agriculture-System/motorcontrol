#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define MAX_SPEED 225
#define MIN_SPEED 0
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void motor_1_Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor_2_Stop(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void motor_1_Dash(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 225 - speed);
}

void motor_2_Dash(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);
}

void motor_2_Reverse(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN3, HIGH);
  analogWrite(IN4, 225 - speed);
}

void loop() {
  motor_1_Dash(MAX_SPEED);
  delay(5000);
  motor_2_Reverse(MAX_SPEED);
  delay(2000);
  motor_1_Stop();
  motor_2_Stop();
  delay(10000);

}