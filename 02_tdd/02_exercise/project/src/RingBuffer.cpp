#include "RingBuffer.h"

RingBuffer::RingBuffer(unsigned int capacity) : _capacity{capacity}, _size{}, _readIndex{}, _writeIndex{} {

    if(!this->capacity()) {
        throw std::invalid_argument{"Zero passed as capacity."};
    }

    _data = new int[this->capacity()];
}

RingBuffer::~RingBuffer() {

    delete [] _data;
}

void RingBuffer::add(int element) {

    _data[_writeIndex] = element;
    _writeIndex = (_writeIndex + 1) % capacity();
    _readIndex = (_readIndex + (size() == capacity())) % capacity();

    _size += (size() < capacity());
}

int RingBuffer::remove() {

    if(!size()) {
        throw std::out_of_range{"Removing from zero size buffer."};
    }

    int element = _data[_readIndex];
    _readIndex = (_readIndex + 1) % capacity();

    _size--;

    return element;
}
