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
bool Flagblt = false;
int testPrint = 0;



void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  BoardInit();
  initPump();
  initServo();
  initFireSensor();
  pinMode(42, OUTPUT);
  Serial.print("panis");
}

int readBluethoot()
{
  char Incoming_value = NULL;
  int value = 0;
  if (Serial1.available()) 
  {
   Incoming_value = Serial1.read();
   Serial.print("Valeur dents blue: ");Serial.println(Incoming_value);
   if(Incoming_value == '0')
    {
       value = 0;
    }
    else if(Incoming_value == '1')
    {
      value = 1;
    }
    else if(Incoming_value == '2')
    {
      value = 2;
    }
    else if(Incoming_value == '3')
    {
      value = 3;
    }
    else if(Incoming_value == '4')
    {
      value = 4;
    }
  }
  return(value);
 }

void giro(int etat){
  if(etat == 0){
    digitalWrite(42, LOW);
  }
  else{
    digitalWrite(42, HIGH);
  }
}
void deplacement(int zone){
  switch (zone) {
  case 1:
    Tourner(-90);
    Avancer(68);
    Tourner(90);
    Avancer(50);
    Tourner(90);
    Avancer(45);
    Tourner(-90);
    Avancer(55);
    Tourner(-90);
    Avancer(17);
    Tourner(90);
    Avancer(50);
  break;
  case 2:
    Tourner(85);
    Avancer(73);
    Tourner(-88);
    Avancer(28);
    Tourner(-83);
    Avancer(55);
    Tourner(90);
    Avancer(45);
    Tourner(87);
    Avancer(80);
    Tourner(-85);
    Avancer(77);
  break;
  case 3:
    Tourner(-90);
    Avancer(68);
    Tourner(90);
    Avancer(50);
    Tourner(90);
    Avancer(45);
  break;
  case 4:

  break;
  }
}

void loop()
{
  int flagBluetooth = readBluethoot();
  int flagGaz = 0;

  while(flagBluetooth > 0 && flagGaz == 0){
    flagGaz = ReadSmokeSensor();
    if(flagGaz == 1){
      giro(flagGaz);
    }
  }
  while (flagGaz)
  {
    //programmer la fonction qui gere les chemin
    deplacement(flagBluetooth);
    resetMOTORS();
    MOTOR_SetSpeed(0, -.15);
    MOTOR_SetSpeed(1,0.15);
    while(centerFire() != 1);
    delay(200);
    distanceFire();
    activatePump();
    put_off_fire();
    desactivatePumP();
    flagGaz = 0;
    giro(flagGaz);
  }




    /*activatePump();
    put_off_fire();
    desactivatePumP();*/
    //distanceFire();
    //delay(1000);
    /*if(Smoke)
    {
      //aller dans le secteur mentionnee et chercher le feu
      while(detectFire())
      {
        activatePump();
        put_off_fire();
      }
      desactivatePumP();
      Smoke = 0;
    }*/

  /*
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
    */
}
