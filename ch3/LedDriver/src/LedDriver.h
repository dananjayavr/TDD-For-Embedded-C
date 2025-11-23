#ifndef _LEDDRIVER_H
#define _LEDDRIVER_H

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);

void LedDriver_TurnOn(uint8_t led);
void LedDriver_TurnOff(uint8_t led);

#endif