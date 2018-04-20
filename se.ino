#include <AFMotor.h>
#include <SoftwareSerial.h>
//define steppers
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

char data;
int8_t motor1state = 0; // 0=> Stopped, -1=>Reverse, 1=>Forward
int8_t motor2state = 0;

void setup()
{
  motor1.setSpeed(100);  // 10 rpm
  motor2.setSpeed(100);  // 10 rpm
  Serial.begin(9600);
}

void loop()
{
  Serial.println(data);
  if (Serial.available())
  {
    data = Serial.read();
    if (data == 'A')
    {
      motor1state = 1;
    }
    if (data == 'B')
    {
      motor1state = -1;
    }
    if (data == 'C')
    {
      motor2state = 1;
    }
    if (data == 'D')
    {
      motor2state = -1;
    }
    if (data == 'F')
    {
      motor1state = 0;
    }
    if (data == 'G')
    {
      motor2state = 0;
    }
  }

  if (motor1state > 0)
  {
    // Step forward
    motor1.step(100, FORWARD, SINGLE);
  }
  else if (motor1state < 0)
  {
    // Step backward
    motor1.step(100, BACKWARD, SINGLE);
  }
  else
  {
    // Do nothing
  }

  if (motor2state > 0)
  {
    // Step forward
    motor2.step(100, FORWARD, SINGLE);
  }
  else if (motor2state < 0)
  {
    // Step backward
    motor2.step(100, BACKWARD, SINGLE);
  }
  else
  {
    // Do nothing
  }
}
