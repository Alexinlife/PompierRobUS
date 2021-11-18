#include <LPs_main_lib.h>

MegaServo myservo;
 
int pos = 0;    
int initialposition = 84;
 
void initServo()
{ 
  myservo.attach(11);
  myservo.write(initialposition);
}
 
int put_off_fire()
{
    for (pos = 82; pos <= 120; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 120; pos >= 60; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
    for (pos = 60; pos <= initialposition; pos += 1) { 
    myservo.write(pos); 
    delay(10);
  }

  return(true);
}