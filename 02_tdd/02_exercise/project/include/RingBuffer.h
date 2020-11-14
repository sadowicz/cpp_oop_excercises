#pragma once

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);

    void add(int);

    unsigned int capacity() const { return _capacity; }

private:
    unsigned int _capacity;
};