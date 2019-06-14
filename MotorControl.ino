#include <Servo.h>

#define SERVOMIN  0 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  180 // this is the 'maximum' pulse length count (out of 4096)

Servo servo;

char servoPrefix = 's';
char servoString;
char servoData;
int servoInt;
int servoPos;

#define FRONTLEFT_IN1 3
#define FRONTLEFT_IN2 2
#define FRONTRIGHT_IN1 5
#define FRONTRIGHT_IN2 4
#define BACKLEFT_IN1 7
#define BACKLEFT_IN2 6
#define BACKRIGHT_IN1 13
#define BACKRIGHT_IN2 12

int power = 255;
char powerPrefix = 'p';

int input = 0;
void setup() {
  pinMode(1, OUTPUT);
  //set up servo
  servo.attach(9); //analog pin 0
  servo.write(90);
  delay(10);
  //set up DC motors
  pinMode(FRONTLEFT_IN1, OUTPUT);
  pinMode(FRONTLEFT_IN2, OUTPUT);
  pinMode(FRONTRIGHT_IN1, OUTPUT);
  pinMode(FRONTRIGHT_IN2, OUTPUT);
  pinMode(BACKLEFT_IN1, OUTPUT);
  pinMode(BACKLEFT_IN2, OUTPUT);
  pinMode(BACKRIGHT_IN1, OUTPUT);
  pinMode(BACKRIGHT_IN2, OUTPUT);
  //begin serial connection
  Serial.begin(9600);
  Serial.println("Ready");
}

void stopMotors() {
  analogWrite(FRONTLEFT_IN2, 0);
  analogWrite(FRONTRIGHT_IN2, 0);
  analogWrite(BACKLEFT_IN2, 0);
  analogWrite(BACKRIGHT_IN2, 0);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();
    if (!isnan(input))
      int power = input;
    switch (input) {
      case 'w':
        digitalWrite(FRONTLEFT_IN1, LOW);
        digitalWrite(FRONTRIGHT_IN1, LOW);
        digitalWrite(BACKLEFT_IN1, HIGH);
        digitalWrite(BACKRIGHT_IN1, HIGH);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;
        
      case 's':
        digitalWrite(FRONTLEFT_IN1, HIGH);
        digitalWrite(FRONTRIGHT_IN1, HIGH);
        digitalWrite(BACKLEFT_IN1, LOW);
        digitalWrite(BACKRIGHT_IN1, LOW);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'a':
        digitalWrite(FRONTLEFT_IN1, HIGH);
        digitalWrite(FRONTRIGHT_IN1, LOW);
        digitalWrite(BACKLEFT_IN1, HIGH);
        digitalWrite(BACKRIGHT_IN1, LOW);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'd':
        digitalWrite(FRONTLEFT_IN1, LOW);
        digitalWrite(FRONTRIGHT_IN1, HIGH);
        digitalWrite(BACKLEFT_IN1, LOW);
        digitalWrite(BACKRIGHT_IN1, HIGH);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'q':
        digitalWrite(FRONTLEFT_IN1, HIGH);
        digitalWrite(FRONTRIGHT_IN1, LOW);
        digitalWrite(BACKLEFT_IN1, LOW);
        digitalWrite(BACKRIGHT_IN1, HIGH);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'e':
        digitalWrite(FRONTLEFT_IN1, LOW);
        digitalWrite(FRONTRIGHT_IN1, HIGH);
        digitalWrite(BACKLEFT_IN1, HIGH);
        digitalWrite(BACKRIGHT_IN1, LOW);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'z':
        digitalWrite(FRONTLEFT_IN1, HIGH);
        digitalWrite(FRONTRIGHT_IN1, HIGH);
        digitalWrite(BACKLEFT_IN1, HIGH);
        digitalWrite(BACKRIGHT_IN1, HIGH);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'x':
        digitalWrite(FRONTLEFT_IN1, LOW);
        digitalWrite(FRONTRIGHT_IN1, LOW);
        digitalWrite(BACKLEFT_IN1, LOW);
        digitalWrite(BACKRIGHT_IN1, LOW);
        analogWrite(FRONTLEFT_IN2, power);
        analogWrite(FRONTRIGHT_IN2, power);
        analogWrite(BACKLEFT_IN2, power);
        analogWrite(BACKRIGHT_IN2, power);
        delay(10);
        stopMotors();
        break;

      case 'r':
        servoPos = servo.read() + 1;
        if (servoPos <= SERVOMAX) {
          servo.write(servoPos);
          Serial.print('s');
          Serial.println(servoPos);
        }
        break;

      case 'f':
        servoPos = servo.read() - 1;
        if (servoPos >= SERVOMIN) {
          servo.write(servoPos);
          Serial.print('s');
          Serial.println(servoPos);
        }
        break;

//      case '`':
//        Serial.println("exit");
//        break;
    }
  }
}
