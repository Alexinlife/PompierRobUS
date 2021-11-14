#include <LPs_sonar_lib.h>

#define echoPin A6
#define trigPin A5
#define ledjaune 53
#define ledbleu 45
#define ledverte 47
#define ledrouge 49


int getUS()
{
  int distance = (int)SONAR_GetRange(0);
  return(distance);
}


void hitQuille(int us)
{
  if(us<=20){
    us = 20;
  }
  digitalWrite(ledbleu, LOW);
  digitalWrite(ledjaune, LOW);
  digitalWrite(ledrouge, LOW);
  digitalWrite(ledverte, HIGH);
  resetMOTORS();
  Tourner(-95);
  CloseCage();
  resetMOTORS();
  Avancer(us);
  Tourner(20);
  Tourner(-40);
  Tourner(20);
  OpenCage();
  digitalWrite(ledverte, LOW);
}
