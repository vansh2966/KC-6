

// Motor 1
#define M1_IN1 22
#define M1_IN2 23
#define M1_EN 2

// Motor 2
#define M2_IN1 24
#define M2_IN2 25
#define M2_EN 3

// Motor 3
#define M3_IN1 26
#define M3_IN2 27
#define M3_EN 4

// Motor 4
#define M4_IN1 28
#define M4_IN2 29
#define M4_EN 5

// Motor 5
#define M5_IN1 30
#define M5_IN2 31
#define M5_EN 6

// Motor 6
#define M6_IN1 32
#define M6_IN2 33
#define M6_EN 7

// Ultrasonic
#define TRIG 40
#define ECHO 41

// Buzzer
#define BUZZER 42

int motorSpeed = 180;

//--------------------------------------------

void setup()
{
  // Motor pins
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M3_IN1, OUTPUT);
  pinMode(M3_IN2, OUTPUT);
  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);
  pinMode(M5_IN1, OUTPUT);
  pinMode(M5_IN2, OUTPUT);
  pinMode(M6_IN1, OUTPUT);
  pinMode(M6_IN2, OUTPUT);

  pinMode(M1_EN, OUTPUT);
  pinMode(M2_EN, OUTPUT);
  pinMode(M3_EN, OUTPUT);
  pinMode(M4_EN, OUTPUT);
  pinMode(M5_EN, OUTPUT);
  pinMode(M6_EN, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

//--------------------------------------------

void loop()
{
  int distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <= 20)
  {
    stopAllMotors();
    digitalWrite(BUZZER, HIGH);
  }
  else
  {
    digitalWrite(BUZZER, LOW);
    forwardAllMotors();
  }

  delay(100);
}

//--------------------------------------------

int getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  int distance = duration * 0.034 / 2;

  return distance;
}

//--------------------------------------------

void forwardMotor(int in1, int in2, int en)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en, motorSpeed);
}

//--------------------------------------------

void stopMotor(int in1, int in2, int en)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(en, 0);
}

//--------------------------------------------

void forwardAllMotors()
{
  forwardMotor(M1_IN1, M1_IN2, M1_EN);
  forwardMotor(M2_IN1, M2_IN2, M2_EN);
  forwardMotor(M3_IN1, M3_IN2, M3_EN);
  forwardMotor(M4_IN1, M4_IN2, M4_EN);
  forwardMotor(M5_IN1, M5_IN2, M5_EN);
  forwardMotor(M6_IN1, M6_IN2, M6_EN);
}

//--------------------------------------------

void stopAllMotors()
{
  stopMotor(M1_IN1, M1_IN2, M1_EN);
  stopMotor(M2_IN1, M2_IN2, M2_EN);
  stopMotor(M3_IN1, M3_IN2, M3_EN);
  stopMotor(M4_IN1, M4_IN2, M4_EN);
  stopMotor(M5_IN1, M5_IN2, M5_EN);
  stopMotor(M6_IN1, M6_IN2, M6_EN);
}
