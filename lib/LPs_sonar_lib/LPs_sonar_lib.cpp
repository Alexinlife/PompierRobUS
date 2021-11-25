#include <LPs_sonar_lib.h>

#define TRIG_PIN3 39
#define ECHO_PIN3 40

int getUS()
{
  int distance = (int)SONAR_GetRange(0);
  return(distance);
}
int sonar3()
{
  digitalWrite(TRIG_PIN3, LOW);    // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN3, HIGH);   // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);    // Send pin low again
  float range = pulseIn(ECHO_PIN3, HIGH)/58.0;
  return range; // Read in times pulse
}