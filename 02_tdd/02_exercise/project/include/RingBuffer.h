#pragma once

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);

    void add(int);

private:
    unsigned int capacity;
};