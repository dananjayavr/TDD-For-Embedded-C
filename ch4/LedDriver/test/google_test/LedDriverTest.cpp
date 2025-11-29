
#include <gtest/gtest.h>
#include "RuntimeErrorStub.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

namespace my
{
  namespace project
  {
    namespace
    {

      // The fixture for testing class LedDriver.
      class LedDriver : public testing::Test
      {
      protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.
        char output[100];
        const char *expected;

        LedDriver()
        {
          // You can do set-up work for each test here.
          LedDriver_Create(&virtualLeds);
        }

        ~LedDriver() override
        {
          // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override
        {
          // Code here will be called immediately after the constructor (right
          // before each test).
        }

        void TearDown() override
        {
          // Code here will be called immediately after each test (right
          // before the destructor).
        }

        // Class members declared here can be used by all tests in the test suite
        // for SprintfTest.
        void expect(const char *s)
        {
        }

        void given(int charsWritten)
        {
        }
      };

      TEST_F(LedDriver, LedsOffAfterCreate)
      {
          LedDriver_Create(&virtualLeds);

          EXPECT_EQ(0,virtualLeds);
      }

      TEST_F(LedDriver, TurnOnLedOne)
      {
          LedDriver_TurnOn(1);
          EXPECT_EQ(1, virtualLeds);
      }

      TEST_F(LedDriver, TurnOffLedOne)
      {
          LedDriver_TurnOn(1);
          LedDriver_TurnOff(1);
          EXPECT_EQ(0,virtualLeds);
      }

      TEST_F(LedDriver, TurnOnMultipleLeds)
      {
          LedDriver_TurnOn(9);
          LedDriver_TurnOn(8);
          EXPECT_EQ(0x180,virtualLeds);
      }

      TEST_F(LedDriver, AllOn) {
          LedDriver_TurnAllOn();
          EXPECT_EQ(0xffff,virtualLeds);
      }

      TEST_F(LedDriver, AllOff) {
          LedDriver_TurnAllOff();
          EXPECT_EQ(0,virtualLeds);
      }

      TEST_F(LedDriver, TurnOffAnyLed) {
          LedDriver_TurnAllOn();
          LedDriver_TurnOff(8);
          EXPECT_EQ(0xff7f,virtualLeds);
      }

      TEST_F(LedDriver, LedMemoryIsNotReadable) {
          virtualLeds = 0xffff;
          LedDriver_TurnOn(8);
          EXPECT_EQ(0x80,virtualLeds);
      }

      TEST_F(LedDriver, UpperAndLowerBounds) {
          LedDriver_TurnOn(1);
          LedDriver_TurnOn(16);
          EXPECT_EQ(0x8001, virtualLeds);
      }

      TEST_F(LedDriver, OutOfBoundsTurnOnDoesNoHarm) {
          LedDriver_TurnOn(-1);
          LedDriver_TurnOn(0);
          LedDriver_TurnOn(17);
          LedDriver_TurnOn(3141);
          EXPECT_EQ(0, virtualLeds);
      }

      TEST_F(LedDriver, OutOfBoundsTurnOffDoesNoHarm) {
          LedDriver_TurnAllOn();
          LedDriver_TurnOff(-1);
          LedDriver_TurnOff(0);
          LedDriver_TurnOff(17);
          LedDriver_TurnOff(3141);
          EXPECT_EQ(0xffff, virtualLeds);
      }

      TEST_F(LedDriver, OutOfBoundsProducesRuntimeError) {
          LedDriver_TurnOn(-1);
          EXPECT_STREQ("LED Driver: out-of-bounds LED", RuntimeError_Stub_GetLastError());
          EXPECT_EQ(-1, RuntimeError_Stub_GetLastParameter());
      }

      TEST_F(LedDriver, IsOn) {
          EXPECT_FALSE(LedDriver_IsOn(11));
          LedDriver_TurnOn(11);
          EXPECT_TRUE(LedDriver_IsOn(11));
      }

      TEST_F(LedDriver, IsOff) {
          EXPECT_TRUE(LedDriver_IsOff(12));
          LedDriver_TurnOn(12);
          EXPECT_FALSE(LedDriver_IsOff(12));
      }

      TEST_F(LedDriver, OutOfBoundsLedsAreAlwaysOff) {
          EXPECT_TRUE(LedDriver_IsOff(10));
          EXPECT_TRUE(LedDriver_IsOff(17));
          EXPECT_FALSE(LedDriver_IsOn(10));
          EXPECT_FALSE(LedDriver_IsOn(17));
      }

      TEST_F(LedDriver, TurnOffMultipleLeds) {
          LedDriver_TurnAllOn();
          LedDriver_TurnOff(9);
          LedDriver_TurnOff(8);
          EXPECT_EQ((~0x180)&0xffff, virtualLeds);
      }

    } // namespace
  } // namespace project
} // namespace my

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
