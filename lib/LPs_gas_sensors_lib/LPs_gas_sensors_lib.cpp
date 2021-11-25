#include <Arduino.h>
#include <LPs_gas_sensors_lib.h>


int mqx_analogPin = A3; // connected to the output pin of MQ-X
bool GazDetected = false;

int ReadSmokeSensor()
{
  /* Valeurs du smoke sensor*/
    int mqx_value = analogRead(mqx_analogPin);
    //Serial.println(mqx_value);
  if (mqx_value >= 600) 
  {
    //Serial.println("Gaz detected");
    GazDetected = true;
    return(GazDetected);
  }
  delay(200); //Just here to slow down the output.
  GazDetected = false;
  return(GazDetected);
}