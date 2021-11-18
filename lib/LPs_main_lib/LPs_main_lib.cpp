#include <LPs_main_lib.h>

#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;

 
void initServo()
{ 
  myservo.attach(11);
  myservo.write(90); 
}
 
void put_off_fire()
{
    for (pos = 90; pos <= 120; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 120; pos >= 60; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  myservo.write(90);

  fire=false;
}