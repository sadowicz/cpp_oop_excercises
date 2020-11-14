#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}

TEST(RingBuffer, Constructor_PassCapacityThroughConstructor) {
    RingBuffer ringBuffer{5};
}

TEST(RingBuffer, Add) {
    RingBuffer ringBuffer{2};
    ringBuffer.add();
}