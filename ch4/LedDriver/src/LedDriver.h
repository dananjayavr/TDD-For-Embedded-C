#ifndef _LEDDRIVER_H
#define _LEDDRIVER_H

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnOn(int led);
void LedDriver_TurnOff(int led);

#endif