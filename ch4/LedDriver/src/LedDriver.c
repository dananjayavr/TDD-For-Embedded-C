#include "LedDriver.h"
#include "RuntimeError.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 0, LAST_LED=16};

static uint16_t *ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int led) {
    return (1 << (led - 1));
}

static void updateHardware(void) {
    *ledsAddress = ledsImage;
}

static bool isLedOutOfBounds(int led) {
    if(led <=0 || led > 16) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
        return true;
    }

    return false;
}

static void clearLedImageBit(int led) {
    ledsImage &= ~(convertLedNumberToBit(led));
}

static void setLedImageBit(int led) {
    ledsImage |= convertLedNumberToBit(led);
}

void LedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_Destroy(void)
{

}

void LedDriver_TurnAllOn(void) {
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

void LedDriver_TurnAllOff(void) {
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_TurnOn(int led) {
    if(isLedOutOfBounds(led))
        return;

    setLedImageBit(led);
    updateHardware();
}

void LedDriver_TurnOff(int led)
{
    if(isLedOutOfBounds(led))
        return;

    clearLedImageBit(led);
    updateHardware();
}

bool LedDriver_IsOn(int led) {
    if(isLedOutOfBounds(led))
        return false;

    return ledsImage & (convertLedNumberToBit(led));
}

bool LedDriver_IsOff(int led) {
    return !LedDriver_IsOn(led);
}
