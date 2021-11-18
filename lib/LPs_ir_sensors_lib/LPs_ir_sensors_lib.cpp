#include <Arduino.h>
#include <LPs_ir_sensors_lib.h>



#define LeftSensor 9      // left sensor
#define RightSensor 10    // right sensor
#define ForwardSensor 8   //front sensor

boolean fire = false;
void initFireSensor()
{
  pinMode(LeftSensor, INPUT);
  pinMode(RightSensor, INPUT);
  pinMode(ForwardSensor, INPUT);
}

void detectFire()
{
    if (digitalRead(LeftSensor) ==1 && digitalRead(RightSensor)==1 && digitalRead(ForwardSensor) ==1) 
    {
    }
    
    else if (digitalRead(ForwardSensor) ==0) 
    {
    fire = true;
    }
    
    else if (digitalRead(LeftSensor) ==0)
    {
    }
    
    else if (digitalRead(RightSensor) ==0) 
    {
    }
    
delay(300);// change this value to increase the distance
 
     while (fire == true)
     {
         // Active la pump et active le servo pour que ca shoot de gauche a droite
      //put_off_fire();
     }
}