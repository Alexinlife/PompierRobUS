#include <Arduino.h>
#include <LPs_pump_lib.h>


// Keyes SR1y relay blink sketch

#define PUMP_ON 1			// Define relay on pin state
#define PUMP_OFF 0			// Define relay off pin state

#define Relay  38 			// Arduino pin where the relay connects

void initPump()  
{
  digitalWrite(Relay, PUMP_OFF);      // initialise the relay to off
  pinMode(Relay, OUTPUT);   
  delay(1000); 
}

void activatePump() 				// Turn the relay on and off in sequence
{
  digitalWrite(Relay, PUMP_ON);	// turn the relay on
}

void desactivatePumP()
{
  digitalWrite(Relay, PUMP_OFF);	// turn the relay off
}
