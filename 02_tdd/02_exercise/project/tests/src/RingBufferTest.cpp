#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}

TEST(RingBuffer, Constructor_PassCapacityThroughConstructor) {
    RingBuffer ringBuffer{5};
}