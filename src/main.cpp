#include <Arduino.h>
#include <LibRobus.h>
#include <LPs_main_lib.h>


int us = 0;
unsigned long tempsUS = millis();
float PreviousTime = 0;
float speed0 = 0;
float speed1 = 0.5; 
unsigned char compteur = 0;
bool test = false;
bool feu = false;
bool gazDetecter = false;
bool flagObstacle = false;

void setup()
{
  Serial.begin(9600);
  BoardInit();
  initPump();
  initServo();
  initFireSensor();
}

void audit2()
{
  if(ROBUS_IsBumper(3))
  {
    compteur++;
    if(compteur > 5)
    {
      compteur = 1;
    }
    delay(500);
  }
    switch (compteur) {
    case 1:
      Serial.print("Gaz detecter:"); Serial.println(ReadSmokeSensor());
      break;
    case 2:
      activatePump();
      Serial.println("Pompe activer:");
      delay(500);
      desactivatePumP();
      Serial.println("Pompe desactiver:");
      delay(500);
      break;
    case 3:
      Serial.print("Distance:"); Serial.println(getUS());
      break;
    case 4:
      detectFire();
      break;
    case 5:
      put_off_fire();
      break;
  }
}
void loop()
{
  //bluethoot reception
  // if bluethoot reception is good

  if(ROBUS_IsBumper(3))
  {
    compteur++;
    if(compteur > 5)
    {
      compteur = 1;
    }
    delay(500);
  }
    switch (compteur) {
    case 1:
      Serial.print("Gaz detecter:"); Serial.println(ReadSmokeSensor());
      break;
    case 2:
      activatePump();
      Serial.println("Pompe activer:");
      delay(2000);
      desactivatePumP();
      Serial.println("Pompe desactiver:");
      delay(500);
      break;
    case 3:
      Serial.print("Distance:"); Serial.println(getUS());
      break;
    case 4:
      detectFire();
      break;
    case 5:
      put_off_fire();
      compteur = 1;
      break;
  }


  /*flagObstacle = false;
  do 
  {
    if(millis() >= tempsUS + 100)
    {
      tempsUS = millis();
      us = getUS(); 
    }
    if (speed0 <= speed1)
    {
      speed0 += .01;
      delay(15);    //  Fonctionne bien a 5ms
      MOTOR_SetSpeed(0, speed0);
    }
    PreviousTime = PID(PreviousTime, speed0);
    flagObstacle = true;
  }while(us >= 15);

  if(flagObstacle)
  {
    Reculer(-8);
    Tourner(90);
    int distanceD = getUS();
    delay(100);
    Tourner(-180);
    int distanceG = getUS();
    delay(100);
    Tourner(90);
    if(distanceD>=distanceG)
    {
      Tourner(90);
    }
    else
    {
      Tourner(-90);
    }
  }*/
/*
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
  */
}
