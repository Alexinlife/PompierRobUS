#include <LPs_sonar_lib.h>


int getUS()
{
  int distance = (int)SONAR_GetRange(0);
  return(distance);
}