char t;
int Speed = 255;
void setup() {
  pinMode(3, OUTPUT);  //direction motor
  pinMode(5, OUTPUT);  //direction motor
  pinMode(6, OUTPUT);  //driving motor
  pinMode(9, OUTPUT);  //driving motor
  Serial.begin(9300);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);

    if (t == 'F') {          //move forward(all motors rotate in forward direction)
      forward();
    }

    else if (t == 'B') {    //move reverse (all moto
      backward();
    }

    else if (t == 'L') {    //turn right
      left();
    }

    else if (t == 'R') {    //turn left
      right();
    }
    else if ( t == 'I') {
      //FR
      forward();
      right();
    }
    else if ( t == 'G')//FL
    {
      forward();
      left();
    }
    else if ( t == 'H')//BL
    {
      backward();
      left();
    }
    else if ( t == 'J')//BR
    {
      backward();
      right();
    }
    else if (t == 'S') {    //STOP (all motors stop)
      analogWrite(3, 0);
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
    }
    else if (t == '1')
      Speed = 80;
    else if (t == '2')
      Speed = 90;
    else if (t == '3')
      Speed = 100;
    else if (t == '4')
      Speed = 120;
    else if (t == '5')
      Speed = 150;
    else if (t == '6')
      Speed = 170;
    else if (t == '7')
      Speed = 190;
    else if (t == '8')
      Speed = 210;
    else if (t == '9')
      Speed = 230;
    else if (t == 'q')
      Speed = 255;
  }
}
void forward() {
  analogWrite(9, Speed);
  analogWrite(6, 0);
}
void backward() {
  analogWrite(9, 0);
  analogWrite(6, Speed);
}
void left() {
  analogWrite(5, 120);
  analogWrite(3, 0);
}
void right() {
  analogWrite(5, 0);
  analogWrite(3, 120);
}
