#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}

TEST(RingBuffer, Constructor_PassCapacityThroughConstructor) {
    RingBuffer ringBuffer{5};
}

TEST(RingBuffer, Constructor_ThrowsExceptionWhenPassingZeroCapacity) {
    EXPECT_THROW(RingBuffer ringBuffer{0}, std::invalid_argument);
}

TEST(RingBuffer, Constructor_ThrownExceptionHasValidMessage) {
    try {
        RingBuffer ringBuffer{0};
    }
    catch(std::invalid_argument& zeroCapacityExcpt) {
        EXPECT_STREQ("Zero passed as capacity.", zeroCapacityExcpt.what());
    }
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

TEST(RingBuffer, Add_AddingElementsDoNotIncrementSizeWhenItEqualsCapacity) {
    RingBuffer ringBuffer{1};
    ringBuffer.add(1);
    ringBuffer.add(3);

    EXPECT_EQ(1, ringBuffer.size());
}

TEST(RingBuffer, Add_AddingElementAboveCapacityMovesReadIndexToNextOldest) {
    RingBuffer ringBuffer{2};
    ringBuffer.add(3);
    ringBuffer.add(8);
    ringBuffer.add(9);

    EXPECT_EQ(8, ringBuffer.remove());
}

TEST(RingBuffer, Remove) {
    RingBuffer ringBuffer{2};
    ringBuffer.add(1);
    ringBuffer.remove();
}

TEST(RingBuffer, Remove_ThrowExceptionWhenSizeIsZero) {
    RingBuffer ringBuffer{2};
    EXPECT_THROW(ringBuffer.remove(), std::out_of_range);
}

TEST(RingBuffer, Remove_ThrownExceptionHasValidMessage) {
    RingBuffer ringBuffer{4};
    try {
        ringBuffer.remove();
    }
    catch(std::out_of_range& zeroSizRemoveExcpt) {
        EXPECT_STREQ("Removing from zero size buffer.", zeroSizRemoveExcpt.what());
    }
}

TEST(RingBuffer, Remove_RemovingElementDecrementsSize) {
    RingBuffer ringBuffer{2};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.remove();

    EXPECT_EQ(1, ringBuffer.size());
}

TEST(RingBuffer, Remove_RemovingElementReturnsRemovedElement) {
    RingBuffer ringBuffer{1};
    ringBuffer.add(3);

    EXPECT_EQ(3, ringBuffer.remove());
}

TEST(RingBuffer, Remove_RemovingElementReturnsRemovedElementAnotherElement) {
    RingBuffer ringBuffer{1};
    ringBuffer.add(2);

    EXPECT_EQ(2, ringBuffer.remove());
}

TEST(RingBuffer, Remove_RemovingElementsReturnsRemovedElementsTwoElements) {
    RingBuffer ringBuffer{2};
    ringBuffer.add(2);
    ringBuffer.add(4);

    EXPECT_EQ(2, ringBuffer.remove());
    EXPECT_EQ(4, ringBuffer.remove());
}

TEST(RingBuffer, Remove_RemovingElementsReturnsRemovedElementsCapacityElements) {
    RingBuffer ringBuffer{4};

    for(int i = 0; i < ringBuffer.capacity(); i++)
        ringBuffer.add(i + 1);

    for(int i = 0; i < ringBuffer.capacity(); i++)
        EXPECT_EQ(i + 1, ringBuffer.remove());
}