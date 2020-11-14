#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}

TEST(RingBuffer, Constructor_PassCapacityThroughConstructor) {
    RingBuffer ringBuffer{5};
}

TEST(RingBuffer, Capacity_ReturnRingBufferCapacity) {
    RingBuffer ringBuffer{5};
    EXPECT_EQ(5, ringBuffer.capacity());
}

TEST(RingBuffer, Add) {
    RingBuffer ringBuffer{2};
    ringBuffer.add(1);
}

TEST(RingBuffer, Add_AddingElementIncrementsSize) {
    RingBuffer ringBuffer{3};
    ringBuffer.add(2);

    EXPECT_EQ(1, ringBuffer.size());
}

TEST(RingBuffer, Add_AddingElementIncrementsSizeTwoElements) {
    RingBuffer ringBuffer{3};
    ringBuffer.add(2);
    ringBuffer.add(3);

    EXPECT_EQ(2, ringBuffer.size());
}

TEST(RingBuffer, Remove) {
    RingBuffer ringBuffer{2};
    ringBuffer.remove();
}

TEST(RingBuffer, Remove_ThrowExceptionWhenSizeIsZero) {
    RingBuffer ringBuffer{2};
    EXPECT_THROW(ringBuffer.remove(), std::out_of_range);
}