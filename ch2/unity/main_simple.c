#include <stdio.h>
#include "unity.h"

void setUp() {}
void tearDown() {}

void test_sprintf_NoFormatOperations()
{
    char output[5];

    TEST_ASSERT_EQUAL(3,sprintf(output,"hey"));
    TEST_ASSERT_EQUAL_STRING("hey",output);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sprintf_NoFormatOperations);
    
    return (UNITY_END());
}