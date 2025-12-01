#include "unity_fixture.h"
#include "unity.h"
#include "unity_fixture.h"
#include "Add.h"

TEST_GROUP(Adder);

TEST_SETUP(Adder)
{
}

TEST_TEAR_DOWN(Adder)
{

}

TEST(Adder, CanAddOneAndTwo)
{

    TEST_ASSERT_EQUAL(2, add(1, 1));
}

TEST_GROUP_RUNNER(Adder)
{
    RUN_TEST_CASE(Adder, CanAddOneAndTwo);
}


static void RunAllTests(void)
{
    RUN_TEST_GROUP(Adder);
}

int main(int argc, const char *argv[]) {
    return UnityMain(argc, argv, RunAllTests);
}
