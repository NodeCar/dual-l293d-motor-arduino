#include <AFMotor.h>
#include<Wire.h>

int ledState = 0;

AF_DCMotor motor[4] = {
  AF_DCMotor(1), AF_DCMotor(2), AF_DCMotor(3), AF_DCMotor(4)};

void setup() {
  Wire.begin(10); // join i2c bus with address #10
  Wire.onReceive(receiveData); // register event
  
  // motor test start
  for(int i = 0; i < 4; i++) {
    motor[i].run(FORWARD);
    motor[i].setSpeed(200);
  }
  delay(2000);
  for(int i = 0; i < 4; i++) {
    motor[i].run(RELEASE);
  } // motor test end
}

void loop() {
  if (ledState == 0) {
    digitalWrite(13, HIGH); // set the LED on
    ledState = 1;
  }
  else {
    digitalWrite(13, LOW); // set the LED off
    ledState = 0;
  }
  delay(1000);
}

void receiveData(int byteCount)
{
  byte reg;
  int operation;
  word spd;

  if(byteCount == 4) {
    reg = Wire.read();
    operation = Wire.read();
    byte high = Wire.read();
    byte low = Wire.read();
    spd = word(high, low); // Big Endian
    motor[reg].run(operation);
    if(operation < BRAKE) {
      motor[reg].setSpeed(spd);
    }
  }
}



