/*
 * Test List:
 *
 * Can write to circular buffer
 * Can read from circular buffer
 * If buffer is empty, a read will yield a zero/null value
 * If circular buffer is full, cannot write to circular buffer (return false)
 * Can get current buffer item count
 * Can get buffer size
 */

#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
    CircularBuffer_Create(0xff);
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

TEST(CircularBuffer, CanInitializeBuffer)
{
    TEST_ASSERT_EQUAL_HEX8(0xff, CircularBuffer_Get());
}

TEST(CircularBuffer, CanInsertAnItem)
{
    TEST_ASSERT_TRUE(CircularBuffer_Put(1));
}

TEST(CircularBuffer, CanGetAnItem)
{
    CircularBuffer_Put(1);
    TEST_ASSERT_EQUAL(1, CircularBuffer_Get());
}

TEST(CircularBuffer, CanRetrieveCircularBufferLength)
{
    TEST_ASSERT_EQUAL(1, CircularBuffer_GetTotalSize());
}

TEST(CircularBuffer, CanRetrieveCircularBufferCurrentItemCount)
{
    CircularBuffer_Put(1);
    TEST_ASSERT_EQUAL(1, CircularBuffer_GetSize());
}

