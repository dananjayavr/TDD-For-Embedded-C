/*
* Test List:
* 
* All LEDs are off after the driver is initialized
* A single LED can be turned on
* A single LED can be turned off
* Multiple LEDs can be turned on/off
* Turn on all LEDs
* Turn off all LEDs
* Query LED state
* Check boundary values
* Check out-of-bounds values
*/

#include "unity_fixture.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{

}

TEST(LedDriver, LedsOffAfterCreate)
{
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180,virtualLeds);
}

TEST(LedDriver, AllOn) {
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff,virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed) {
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f,virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReadable) {
    virtualLeds = 0xffff;
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x80,virtualLeds);
}