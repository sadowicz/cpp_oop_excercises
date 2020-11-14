#pragma once

class RingBuffer {

public:
    explicit RingBuffer(unsigned int capacity = 1);

    void add(int);

    unsigned int capacity() const { return _capacity; }
    unsigned int size() const { return _size; }

private:
    unsigned int _capacity;
    unsigned int _size;
};