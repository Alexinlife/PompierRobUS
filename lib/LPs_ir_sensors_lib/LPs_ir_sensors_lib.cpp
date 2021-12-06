#include <Arduino.h>
#include <LPs_ir_sensors_lib.h>
#include <LPs_movement_lib.h>
#include <LPs_sonar_lib.h>



#define LeftSensor 9      // left sensor
#define RightSensor 10    // right sensor
#define ForwardSensor 8   //front sensor
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void initFireSensor()
{
  pinMode(LeftSensor, INPUT);
  pinMode(RightSensor, INPUT);
  pinMode(ForwardSensor, INPUT);
}

int detectFire()
{
  int fire = 0;
  int sensorReading = analogRead(ForwardSensor);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  int sensorReading1 = analogRead(LeftSensor);
  int range1 = map(sensorReading1, sensorMin, sensorMax, 0, 3);
  
  int sensorReading2 = analogRead(RightSensor);
  int range2 = map(sensorReading2, sensorMin, sensorMax, 0, 3);
  
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    fire = 1;
    Serial.println("** Close Fire center **");
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire center **");
    fire = 1;
    break;

  }
  switch (range1) {
  case 0:    // A fire closer than 1.5 feet away.
    fire = 2;
    //Tourner(-20);
    Serial.println("** Close Fire from the left **");
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire from the left **");
    fire = 2;
    break;

  }
  switch (range2){
  case 0:    // A fire closer than 1.5 feet away.
    fire = 3;
    //Tourner(20);
    Serial.println("** Close Fire to the right **");
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire from the right **");
    fire = 3;
    break;
  }
  delay(100);
  return(fire);
}
int centerFire(){
  int capteur = detectFire();
  if(capteur == 1){
    resetMOTORS();
  }
  else if(capteur == 2){
    MOTOR_SetSpeed(0,-0.1);
    MOTOR_SetSpeed(1,0.1);
  }
  else if(capteur == 3){
    MOTOR_SetSpeed(0,0.1);
    MOTOR_SetSpeed(1,-0.1);
  }
 return(capteur);
}

void distanceFire(){
  int distance = getUS();
  delay(100);
  distance += getUS();
  delay(100);
  distance += getUS();
  delay(100);
  distance += getUS();
  delay(100);
  distance += getUS();
  delay(100);
  distance += getUS();
  distance /= 6;
  //Serial.print("Distance: ");Serial.println(distance);
  if(distance < 20){
    Reculer(distance-20);
  }
  else if(distance > 20){
    Avancer(distance+(distance*.2)-20);
  }
}