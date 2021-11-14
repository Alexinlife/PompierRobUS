#include <LPs_main_lib.h>


#define capteurCentre A1
#define MIN_CAPTEURC 160


void etapeJaune()
{
  Avancer(26);
  CloseCage();
  delay(500);
  Tourner(90);
  Avancer(45);
  Tourner(-90);
  Avancer(225);
  delay(1000);
  OpenCage();
  Reculer(-270);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.2);
    MOTOR_SetSpeed(1, -.2);
  }
  delay(500);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.1);
    MOTOR_SetSpeed(1, .1);
  }
}

void etapeBleu()
{
  Avancer(25);
  CloseCage();
  delay(500);
  Tourner(-88);
  Avancer(45);
  Tourner(88);
  Avancer(219);
  delay(1000);
  OpenCage();
  Reculer(-270);
  Tourner(-20);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.2);
    MOTOR_SetSpeed(1, -.2);
  }
  delay(500);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.1);
    MOTOR_SetSpeed(1, .1);
  }
}

void etapeRouge()
{
  Avancer(25);
  CloseCage();
  delay(500);
  Avancer(217);
  delay(1000);
  OpenCage();
  Reculer(-270);
  Tourner(-5);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.2);
    MOTOR_SetSpeed(1, -.2);
  }
  delay(500);
  while(analogRead(capteurCentre) > MIN_CAPTEURC)
  {
    MOTOR_SetSpeed(0,-.1);
    MOTOR_SetSpeed(1, .1);
  }
}