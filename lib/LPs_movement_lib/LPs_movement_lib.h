#ifndef LPS_MOVEMENT_LIB_H
#define LPS_MOVEMENT_LIB_H

#include <Arduino.h>
#include <LibRobus.h>


long PID(long PreviousTime, float TargetSpeed);
void uTurn(void);
void Tourner(int angle);
void Gauche(int32_t AngleG);
void Droite(int32_t AngleD);
void Avancer(int32_t DistanceA);
void Reculer(int32_t DistanceR);
void resetMOTORS();
#endif