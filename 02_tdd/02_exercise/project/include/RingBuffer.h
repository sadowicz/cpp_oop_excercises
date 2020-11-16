#pragma once

#include <stdexcept>

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);
    ~RingBuffer();

    void add(int element);
    int remove();

    unsigned int capacity() const { return _capacity; }
    unsigned int size() const { return _size; }

private:
    unsigned int _capacity;
    unsigned int _size;
    int* _data;
    int _readIndex;
    int _writeIndex;
};