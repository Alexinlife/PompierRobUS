#include <Arduino.h>
#include <LPs_ir_sensors_lib.h>
#include <LPs_movement_lib.h>




#define LeftSensor 9      // left sensor
#define RightSensor 10    // right sensor
#define ForwardSensor 8   //front sensor

boolean fire = false;
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
  fire = false;
  
  int sensorReading = analogRead(ForwardSensor);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  int sensorReading1 = analogRead(RightSensor);
  int range1 = map(sensorReading1, sensorMin, sensorMax, 0, 3);
  
  int sensorReading2 = analogRead(LeftSensor);
  int range2 = map(sensorReading2, sensorMin, sensorMax, 0, 3);
  
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    fire = true;
    //Serial.println("** Close Fire center **");
    break;
  case 1:    // A fire between 1-3 feet away.
    //Serial.println("** Distant Fire center **");
    break;

  }
  switch (range1) {
  case 0:    // A fire closer than 1.5 feet away.
    fire = true;
    Tourner(20);
    //Serial.println("** Close Fire from the left **");
    break;
  case 1:    // A fire between 1-3 feet away.
    //Serial.println("** Distant Fire from the left **");
    break;

  }
  switch (range2){
  case 0:    // A fire closer than 1.5 feet away.
    fire = true;
    Tourner(-20);
    //Serial.println("** Close Fire to the right **");
    break;
  case 1:    // A fire between 1-3 feet away.
    //Serial.println("** Distant Fire from the right **");
    break;
  }
  delay(200);  // delay between reads
  return(fire);
}