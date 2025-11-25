#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, CanInitializeBuffer);
    RUN_TEST_CASE(CircularBuffer, CanInsertAnItem);
    RUN_TEST_CASE(CircularBuffer, CanGetAnItem);
    RUN_TEST_CASE(CircularBuffer, CanRetrieveCircularBufferLength);
    RUN_TEST_CASE(CircularBuffer, CanRetrieveCircularBufferCurrentItemCount);
}