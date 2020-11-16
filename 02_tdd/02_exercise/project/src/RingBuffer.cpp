#include "RingBuffer.h"

RingBuffer::RingBuffer(unsigned int capacity) : _capacity{capacity}, _size{} {

    if(!this->capacity()) {
        throw std::invalid_argument{"Zero passed as capacity."};
    }

    _data = new int[this->capacity()];
    _readPtr = _data;
    _writePtr = _data;
}

RingBuffer::~RingBuffer() {

    delete [] _data;
}

void RingBuffer::add(int element) {

    *_writePtr++ = element;
    if(size() < capacity()) {
        _size++;
    }
}

int RingBuffer::remove() {

    if(!size()) {
        throw std::out_of_range{"Removing from zero size buffer."};
    }

    _size--;

    return *_readPtr++;
}
