
#include <gtest/gtest.h>

namespace my
{
  namespace project
  {
    namespace
    {

      // The fixture for testing class SprintfTest.
      class SprintfTest : public testing::Test
      {
      protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.
        char output[100];
        const char *expected;

        SprintfTest()
        {
          // You can do set-up work for each test here.
        }

        ~SprintfTest() override
        {
          // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override
        {
          // Code here will be called immediately after the constructor (right
          // before each test).
          memset(output, 0xaa, sizeof output);
          expected = "";
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
          expected = s;
        }

        void given(int charsWritten)
        {
          EXPECT_EQ(strlen(expected), charsWritten);
          EXPECT_STREQ(expected, output);
          EXPECT_EQ(0xaa, static_cast<unsigned char>(output[strlen(expected) + 1]));
        }
      };

      TEST_F(SprintfTest, NoFormatOperation)
      {
        expect("hey");
        given(sprintf(output, "hey"));
      }

      TEST_F(SprintfTest, InsertString)
      {
        expect("Hello, World!\n");
        given(sprintf(output, "Hello, %s!\n", "World"));
      }

    } // namespace
  } // namespace project
} // namespace my

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}