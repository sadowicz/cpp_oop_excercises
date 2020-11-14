#pragma once

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);

private:
    unsigned int capacity;
};