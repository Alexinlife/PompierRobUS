#include <Arduino.h>
#include <LibRobus.h>
#include <LPs_main_lib.h>


bool test = false;
bool feu = false;
bool gazDetecter = false;

void setup()  
{
  Serial.begin(9600);
  BoardInit();
  initPump();
  initServo();
  initFireSensor();
}

void loop()
{
  //bluethoot reception
  // if bluethoot reception is good

  int Gaz = ReadSmokeSensor();
  if (Gaz)
  {
    gazDetecter = true;
  }
  
  if(gazDetecter)
  {
    //aller dans le secteur mentionnee et chercher le feu
    feu = detectFire();
    while(feu)
    {
      activatePump();
      put_off_fire();
    }
    desactivatePumP();
  }