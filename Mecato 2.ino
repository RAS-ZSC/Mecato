#include <Servo.h>
#define motorPin1 3
#define motorPin2 5
#define motorPin3 6
#define motorPin4 9
#define frequency 10

#define EN_PIN 2
#define EN_PIN2 4
int Speed = 255;
char recieved_data;
uint8_t x = 0;
void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, 1);
  pinMode(motorPin2, 1);
  pinMode(motorPin3, 1);
  pinMode(motorPin4, 1);
  digitalWrite(EN_PIN, 1);
  digitalWrite(EN_PIN2, 1);

}
void loop() {
  if (Serial.available() > 0) {
    recieved_data = Serial.read();
    Serial.println(recieved_data);
    switch (recieved_data) {
      case 'F':
        //forward
        motors(Speed, 0, Speed , 0); //90% pwm
        delay(frequency);
        break;
      case 'B':
        //back
        motors(0, Speed, 0, Speed );
        delay(frequency);
        break;
      case 'L':
        //left
        motors(0, Speed, Speed, 0);
        delay(frequency);
        break;
      case 'R':
        //right
        motors(Speed, 0, 0, Speed);
        delay(frequency);
        break;
      case 'S':
        //stop
        motors(0, 0, 0, 0);
        delay(frequency);
        break;
      case '1':
        Speed = 80;
        break;
      case '2':
        Speed = 130;
        break;
      case '3':
        Speed = 170;
        break;
      case '4':
        Speed = 255;
        break;
    }
  }
}
  void motors(int pinA, int pinB, int pinC, int pinD) {
    analogWrite(motorPin1, pinA);
    analogWrite(motorPin2, pinB);
    analogWrite(motorPin3, pinC);
    analogWrite(motorPin4, pinD);
  }
  void stopAll() {
    motors(0, 0, 0, 0);
  }
