#include <LPs_movement_lib.h>


long PID(long PreviousTime, float TargetSpeed)
{
  float pid = 0;
  float Kp = 0.001;
  float Ki = 1;
  float Erreur = 0;
  float sec = 7000;
  unsigned int CT = 50;
  long CurrentTime = millis();
  unsigned int TimeSample = CurrentTime - PreviousTime;

  if (TimeSample >= CT) //CT est une constante de temps systeme definit plus haut
  {
    int encodeur_0 = ENCODER_Read(0);
    int encodeur_1 = ENCODER_Read(1);
    Erreur = encodeur_0 - encodeur_1;
    pid = (Erreur * Kp) + ((Erreur * Ki) / sec) + TargetSpeed;
    PreviousTime = CurrentTime;
    MOTOR_SetSpeed(1, pid);
  }
  return PreviousTime;
}

void Tourner(int angle)
{
  float arc = angle*(3.1416*19.2)/360;
  float nb_pulse = 3200 * arc/24;
    if(angle>0)
    {
      MOTOR_SetSpeed(0, 0.22);
      MOTOR_SetSpeed(1, -0.22);

      while(nb_pulse >= ENCODER_Read(0) && nb_pulse >= -ENCODER_Read(1)) {
        delay(10); 
      }
      if(nb_pulse<=ENCODER_Read(0)){
          MOTOR_SetSpeed(0, 0);
          MOTOR_SetSpeed(1,-0.1);
          while(nb_pulse>=-ENCODER_Read(1));
          MOTOR_SetSpeed(1,0);
      } 
      else if(nb_pulse<=-ENCODER_Read(1)){
          MOTOR_SetSpeed(1, 0);
          MOTOR_SetSpeed(0,0.1);
          while(nb_pulse>=ENCODER_Read(0));
          MOTOR_SetSpeed(0,0);
      } 
    }
    else if(angle<0)
    {
      MOTOR_SetSpeed(0, -0.22);
      MOTOR_SetSpeed(1, 0.22);

      nb_pulse = -1*nb_pulse;

      while(nb_pulse >= -ENCODER_Read(0) && nb_pulse >= ENCODER_Read(1)) {
        delay(10); 
      }
        

      if(nb_pulse<=-ENCODER_Read(0)){
          MOTOR_SetSpeed(0, 0);
          MOTOR_SetSpeed(1, 0.1);
          while(nb_pulse>=ENCODER_Read(1));
          MOTOR_SetSpeed(1,0);
      } 
      else if(nb_pulse<=ENCODER_Read(1)){
          MOTOR_SetSpeed(1, 0);
          MOTOR_SetSpeed(0, -0.1);
          while(nb_pulse>=-ENCODER_Read(0));
          MOTOR_SetSpeed(0,0);
      } 
    }
    delay(100);
    ENCODER_Reset(0);
    ENCODER_Reset(1);
}

void Avancer(int32_t DistanceA)
{
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  float PreviousTime = 0;
  float speed0 = 0;
  float speed1 = 0.9;   // Fonctionne bien a 0.95 robot prodige
  float distance = DistanceA * 3200L / 23.8761;

  float speedMin = .2;
  float speedMax = 0;
  float a = 0;
  float b = 0;

  bool i = true;

  while (i)
  {
    if ((speed0 <= speed1) && ((ENCODER_Read(0)/distance) <= .4))
    {
      speed0 += .01;
      speedMax = speed0;
      delay(15);    //  Fonctionne bien a 5ms
      MOTOR_SetSpeed(0, speed0);
    }
    PreviousTime = PID(PreviousTime, speed0);
    if ((ENCODER_Read(0) >= distance) && (ENCODER_Read(1) >= distance))
    {
      MOTOR_SetSpeed(0, 0);
      MOTOR_SetSpeed(1, 0);
      ENCODER_Reset(0);
      ENCODER_Reset(1);
      i = false;
    }
    if(((ENCODER_Read(0)/distance) >=.6) && ((ENCODER_Read(1)/distance) >=.6))
    {
      a = (speedMin - speedMax)/(1-.6);
      b = speedMin - (a*1);

      speed0 = (a*(ENCODER_Read(0)/distance)+b);
      MOTOR_SetSpeed(0, speed0);      
    }
  }
}

void Reculer(int32_t DistanceR)
{
  ENCODER_Reset(0);
  ENCODER_Reset(1);
  float PreviousTime = 0;
  float speed0 = 0;
  float speed1 = -0.9;   // Fonctionne bien a 0.95 robot prodige
  float distanceR = DistanceR * 3200L / 23.8761;
  float speedMin = -.2;
  float speedMax = 0;
  float a = 0;
  float b = 0;
  bool i = true;
while (i)
  {
    if ((speed0 >= speed1) && ((ENCODER_Read(0)/distanceR) <= .4))
    {
      speed0 -= .01;
      speedMax = speed0;
      delay(15);    //  Fonctionne bien a 5ms
      MOTOR_SetSpeed(0, speed0);
    }
    PreviousTime = PID(PreviousTime, speed0);
    if ((ENCODER_Read(0) <= distanceR) && (ENCODER_Read(1) <= distanceR))
    {
      MOTOR_SetSpeed(0, 0);
      MOTOR_SetSpeed(1, 0);
      ENCODER_Reset(0);
      ENCODER_Reset(1);
      i = false;
    }
    if(((ENCODER_Read(0)/distanceR) >=.6) && ((ENCODER_Read(1)/distanceR) >=.6))
    {
      a = (speedMin - speedMax)/(1-.6);
      b = speedMin - (a*1);

      speed0 = (a*(ENCODER_Read(0)/distanceR)+b);
      MOTOR_SetSpeed(0, speed0); 
    }
  }
}

void resetMOTORS(){
  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
  ENCODER_Reset(0);
  ENCODER_Reset(1);
}