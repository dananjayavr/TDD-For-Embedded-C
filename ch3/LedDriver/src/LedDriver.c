#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_Destroy(void)
{

}

void LedDriver_TurnOn(uint8_t led)
{
    *ledsAddress = 1;
}

void LedDriver_TurnOff(uint8_t led)
{
    *ledsAddress = 0;
}