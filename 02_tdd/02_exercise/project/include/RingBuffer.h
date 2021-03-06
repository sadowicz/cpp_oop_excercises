#pragma once

#include <stdexcept>

class RingBuffer {
    friend class RingBufferTest;
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
    unsigned int _readIndex;
    unsigned int _writeIndex;
};