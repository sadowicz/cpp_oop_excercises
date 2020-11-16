#pragma once

#include <stdexcept>

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);

    void add(int element);
    int remove();

    unsigned int capacity() const { return _capacity; }
    unsigned int size() const { return _size; }

private:
    unsigned int _capacity;
    unsigned int _size;
    int _data[2];
    int* _readPtr;
    int* _writePtr;
};