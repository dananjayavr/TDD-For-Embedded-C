#ifndef _LEDDRIVER_H
#define _LEDDRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
void LedDriver_TurnOn(int led);
void LedDriver_TurnOff(int led);
bool LedDriver_IsOn(int led);
bool LedDriver_IsOff(int led);

#ifdef __cplusplus
}
#endif

#endif
